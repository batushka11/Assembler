#include <iostream>

using namespace std;

int main() {
	/*char A = 0x32;
	char Y;

	__asm{
		MOV AL, A
		SUB AL, 0x32
		MOV Y, AL
	}
	string str = Y ? "true" : "false";
	printf("%s", str);*/

	/*int Y = 0;
	__asm {
		MOV EAX, Y
		petla_for:
			MOV EBX, 5
			SUB EBX, EAX
			JZ koniec_for
			ADD Y, EAX
			ADD EAX, 1
			JMP petla_for
		koniec_for:
	}

	printf("%d", Y);*/

	int Y = 0;
	__asm {
		MOV EAX,0
		_while:
			MOV EBX, 5
			ADD EAX, 1
			SUB EBX, EAX
			JNZ _while
		_end:
		ADD Y, EAX
	}

	printf("%d", Y);
}