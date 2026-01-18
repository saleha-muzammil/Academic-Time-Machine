[org 0x0100]

start:

mov ax, 3
add bx, ax

add ax, 3
add bx, ax

add ax, 3
add bx, ax

add ax, 3
add bx, ax

add ax, 3
add bx, ax

mov ax, 0x4c00	;terminate the program
int 0x21
