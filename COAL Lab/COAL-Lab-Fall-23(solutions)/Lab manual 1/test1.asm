[org 0x0100]  ;directive in the assembler

start:

add ax, 6
add ax, 6
add ax, 6
add ax, 6
add ax, 6
add ax, 6

mov ax, 0x4c00  ;terminate
int 0x21