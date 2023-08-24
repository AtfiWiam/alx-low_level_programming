section .data
	hello db "Hello, Holberton",0
	newline db 10, 0  ; Newline character followed by null terminator
	format db "%s%s",0

section .text
	global main
	extern printf

main:
	push rbp
	mov rdi, format
	mov rsi, hello
	mov rdx, newline  ; Adding the newline string to the output
	call printf
	pop rbp
	ret

