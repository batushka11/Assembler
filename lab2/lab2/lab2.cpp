#include <iostream>

int main() {
	/*
	char A = 0x32;
	char Y;

	__asm {
		MOV AL, A
		ADD AL, 0xCE
		JZ _TRUE
		MOV Y,1
		JMP _END
		_TRUE :
		MOV Y,0
		_END:
	}
	*/

	char A = 3;
	char B = 7;
	char C = 0xCF;
	char Y;

	__asm {
		MOV AL, A
		MOV BL, B
		MOV CL, C
		SUB AL, 5
		JZ _TRUE
		SUB BL, 7
		JZ _TRUE
		MOV Y, 0
		SUB CL, 0xCA
		JZ _TRUE
		JMP _END
		_TRUE :
		MOV Y, 1
		_END :
	}

	printf("y = %d", Y);
}