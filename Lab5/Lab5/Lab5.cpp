#include <iostream>

using namespace std;

int main()
{   
    char a = 0x05;
    char y;
   /* __asm {
        mov al, a
        mov ch, 0xFF

        mov bl, 0
        mov cl, 8

        reserve_loop :
            shl bl, 1
            TEST al, 1
            JZ skip_set
            or bl, 1

            skip_set :
            shr al, 1
            shr ch, 1
            JNZ reserve_loop

            mov y, bl
    }*/

    __asm {
        mov al, a
        mov bl, y
        sub a, 0x05
        JC _flag
        flag:
        mov y, 0x01
    }

    printf("%d\n",y);
    return 0;
}

//1010 = A
//1011 = B
//1100 = C
//1101 = D
//1110 = E
//1111 = F