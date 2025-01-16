[org 0x0100]
jmp start
						;**************************
inputRoutine:
	push bp
	mov bp, sp
	mov bx, 0	
	mov di, equation
getInput:	
	mov ah, 0
	int 0x16			;return ascii value in al
	cmp al, 0x1B			;if excape, then exit
	je exitRoutine
	
	mov byte[di+bx], al
	
	mov ax, 0
	push ax 			; push x position
	mov ax, 0
	push ax 			; push y position
	mov ax, 7 	
	push ax 			; push attribute
	push equation
	inc bx
	push bx
	call printstr	
		
	jmp getInput					;take input again

exitRoutine:
	mov byte[di+bx], 0x20			;append ' '(space) just for terminaion
	mov word[bp+4], equation		;retun the reference
	pop bp
	ret
	
						;**************************

formNumber:
	push bp
	mov bp, sp	
	mov di, [bp+4]					;receive the reference of digit
	mov al, byte[di]	
	sub al, 0x30					;make it digit from ascii
	mov ah, byte[di+1]
	cmp ah, 0x20					;check what is next? is it space?
	je exitRoutineNumber
	inc di				
	mov dh, 10
	mul dh							;make the previous number to Ten's 
	mov ah, byte[di]
	sub ah, 0x30					;make the second digit
	add al, ah
		
exitRoutineNumber:
	
	inc di		
	mov si, di
	mov ah, 0
	mov [bp+6], ax					;return the number
	pop bp	
	ret 2

					;************************************

tokenizerRoutine:
	push bp
	mov bp, sp
	mov si, [bp+4]					;receive the reference of array
	 
	getNumber:
		push 0
		push si
		call formNumber				;get first number
		pop ax		
		mov byte[num1], al			;store the number		
		
		inc si						;leave the space
		mov cl, byte[si]			;point to operator
		mov byte[operator], cl		;pick up operator
		add si, 2			;leave the index of operator and next space
		
		push 0				;make a hole
		push si				;reference of second number
		call formNumber
		pop ax
		mov byte[num2], al	;store the second number
		
		add si, 3			;leave the space, equal operator, sapce
		push 0				;create hole
		push si
		call formNumber
		pop ax		
		mov byte[num3], al	;save third number (result)
		
		mov al, [num1]		;make copies of numbers 
		mov ah, [num2]
		mov bl, [num3]
	computeResult:	
		mov bh, [operator]	;load operator
		plus:
			cmp bh, '+'			;is the operator '+'
			jne minus			;No, may be '-'
			add al, ah			;add the two numbers
			jmp checkResult		;check the result and print
		minus:
			cmp bh, '-'			;is the operator '-'
			jne multiply		;No, may be '*'
			sub al, ah			;subtract the two numbers
			jmp checkResult		;check the result and print
		multiply:
			cmp bh, '*'			;is the operator '*'
			jne cantCompute		;No, may be some other
			mul ah				;multiply the two numbers
	checkResult:
		cmp bl, al				;is the result and thrid number same
		je printOkay			;Yes, print Okay
		jmp printNotOkay		;No, print Not Okay
	printOkay:
		mov si, okay			;si contains the address of okay message
		mov bx, 4				;bx contains the length of message
		jmp printCall		
	printNotOkay:
		mov si, notOkay		;si contains the address of notOkay message
		mov bx, 8			;bx contains the length of message
		call printCall		
	cantCompute:
		mov si, notEquation
		mov bx, 12
	printCall:
		mov ax, 1
		push ax 			; push x position
		mov ax, 1
		push ax 			; push y position
		mov ax, 7 	
		push ax 			; push attribute
		push si
		push bx
		call printstr
	pop bp
	ret 2

					;*************************************
printstr: 
	push bp
	mov bp, sp
	push es
	push ax
	push cx
	push si
	push di
	mov ax, 0xb800
	mov es, ax ; point es to video base
	mov al, 80 ; load al with columns per row
	mul byte [bp+10] ; multiply with y position
	add ax, [bp+12] ; add x position
	shl ax, 1 ; turn into byte offset
	mov di, ax ; point di to required location
	mov si, [bp+6] ; point si to string
	mov cx, [bp+4] ; load length of string in cx
	mov ah, [bp+8] ; load attribute in ah
	nextchar: mov al, [si] ; load next char of string
	mov [es:di], ax ; show this char on screen
	add di, 2 ; move to next screen location
	add si, 1 ; move to next char in string
	loop nextchar ; repeat the operation cx times
	pop di
	pop si
	pop cx
	pop ax
	pop es
	pop bp
	ret 10

				;******************************************
clrscr: 
	pusha
	mov ax, 0xb800
	mov es, ax ; point es to video base
	xor di, di ; point di to top left column
	mov ax, 0x0720 ; space char in normal attribute
	mov cx, 2000 ; number of screen locations
	cld ; auto increment mode
	rep stosw ; clear the whole screen
	popa
	ret

;**************************************
start:

	call clrscr
	push 0				;make a hole to receive the reference of equation
	call inputRoutine
	pop bp				;reference of equation array
	push bp
	call tokenizerRoutine		;It will tokenise and check result

	mov ax, 0x4c00				;Bye Bye
	int 21h

equation: db 0,0,0,0,0,0,0,0,0,0,0,0,0
okay: db 'OKAY'
notEquation: db 'Not equation'
notOkay: db 'NOT OKAY'
operator: db 0

num1: db 0
num2: db 0
num3: db 0