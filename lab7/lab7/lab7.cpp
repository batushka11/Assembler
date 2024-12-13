#include <iostream>

using namespace std;

int main()
{

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
            unsigned char a : 1;
            unsigned char b : 3;
            unsigned char c : 4;
        }bits;
    }un_X;
    un_X x{};

   
    x.BYTE = 0xF7;
    x.bits.a = 1;
    x.bits.b = 0x03;
    x.bits.c = 0x0F;

    if ((x.BYTE & 0x01)) {
        unsigned char pom = x.BYTE & 0xC0;
        pom <<= 2;
        x.BYTE |= pom;
    }
    ///*__asm {
    //    MOV AL, x.BYTE
    //    MOV BL, AL
    //    SHR AL, 5
    //    SUB AL, 1
    //    JNZ end_
    //    MOV AL, BL
    //    AND BL, 0x0C
    //    SHR BL, 2
    //    AND AL, 0xFC
    //    OR BL, AL
    //    MOV x.BYTE, BL
    //    end_ :
    //}*/

    //__asm {
    //    MOV BL, AL
    //    AND BL, 0x01
    //    MOV BH, AL
    //    SHR BH, 1
    //    AND BH, 0x07
    //    MOV CL, 0
    //    ADD CL, BH
    //    JZ ZERO_B
    //    ZERO_B :
    //    AND AL, 0x0F
    //    SHL CL, 4
    //    OR AL, CL
    //    MOV x.BYTE, CL
    //}

    printf("Y=%x\n", x.BYTE);
}
