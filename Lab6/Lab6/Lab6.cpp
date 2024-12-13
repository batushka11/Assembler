#include <iostream>

using namespace std;

int main()
{
    char a = 0x02;
    int y;
   
   /* __asm {
        mov al, a
        sub al, 0x05
        JC _flag
        JZ _flag
        mov y, 0
        jmp _end

        _flag:
        mov y, 1

        _end:

    }*/

   /* __asm {
        MOV ECX, 0
        MOV EAX, 0
        petla:
        CMP ECX, 5
        JNC koniec
        ADD EAX, ECX
        ADD ECX, 1
        JMP petla
        koniec :
        
        MOV y, EAX
    }*/
    typedef union {
        unsigned char BYTE;
        struct {
            unsigned char a : 2;
            unsigned char b : 3;
            unsigned char c : 3;
        }bits;
    }un_X;
    un_X x;

    if ((x.BYTE >> 5) == 1) {
        if ((x.BYTE & 0xE0) == 0x20) {
            x.BYTE &= 0xFC;
            unsigned char pom = x.BYTE & 0x0C;
            x.BYTE |= pom >> 0x02;
        }
    }
    printf("%d\n", x.BYTE);
    return 0;
}
