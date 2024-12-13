#include <iostream>

int main()
{
    char y;
    char a = 0x80;
    /*for (int i = 0; i, 8; i++) {
        int pom = a & 0x01;
        y -= pom;
        a >>= 1;
    }*/
    /*petla_for :
            MOV EBX, A
            AND EBX, 0x01
            SUB Y, 1
            JZ koniec_for
            ADD Y, EAX
            ADD EAX, 1
            JMP petla_for
        koniec_for :*/
    /*MOV al, a
        MOV cl, 0
        MOV ch, 8

        petla:
    SUB cl, 8
        JZ _endif
        ADD cl, 8
        MOV ah, al
        AND ah, 0x01
        SUB ch, ah
        SHR al, 1
        ADD cl, 1
        JMP petla
        _endif :
    MOV y, ch*/
   /* __asm {
        MOV al, a;
        MOV bl, 0;
        MOV cl, 8;

    petla:
        MOV dl, al;
        AND dl, 1;
        JNZ nie_zero;

        ADD bl, 1;

    nie_zero:
        SHR al, 1;
        SUB cl, 1;
        JNZ petla;
        MOV y, bl;
    }

    printf("Liczba zerowych bitow w 0x%02X: %d\n", a, y);
    return 0;*/

 /*   __asm {
        MOV al, a
        MOV cl, 0
        MOV ch, 0
        petla:
        SUB cl, 8
            JZ _endif
            ADD cl, 8
            MOV ah, al
            AND ah, 0x01
            ADD ch, ah
            SHR al, 1
            ADD cl, 1
            JMP petla
            _endif :
        AND ch, 0x01
            XOR ch, 0x01
            MOV y, ch
    }*/
                                                                                                            
    __asm {
        MOV al, a
        MOV cl, 0
        MOV ch, 0
    petla:
        SUB cl, 8
        JZ _endif
        ADD cl, 8
        MOV ah, al
        SHL ch, 1
        AND ah, 0x01
        OR ch, ah
        SHR al, 1
        ADD cl, 1
        JMP petla
    _endif:
    }

    printf("Liczba zerowych bitow w 0x%02X: 0x%02X\n", a, y);
    return 0;
}

