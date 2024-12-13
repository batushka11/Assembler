#include <iostream>

int main()
{
    char Y, A = 7;
    __asm {
        MOV AL, A
        SUB AL, 0X32
        JZ _TRUE
        MOV Y, 1
        JMP _END
        _TRUE:
        MOV Y, 0
        _END:

    }
    printf("a = %d, y = %d", A, Y);
}

//MOV AL, A
//MOV AH, 0
//MOV BX, AX
//MOV CX, BX
//SHL AX, 5
//SHL BX, 2
//SUB AX, BX
//SHL BX, 1
//SUB AX, BX
//MOV Y, AX

//MOV AL, A
//MOV AH, 0
//MOV BX, AX
//MOV CX, BX
//PUSH AX, 5
//SHL BX, 3
//SHL CX, 2
//SUB AX, BX
//SUB AX, CX
//MOV Y, AX
