#include <iostream>
#include <stdio.h>


int main() {
	//#pragma pack(1)
	//typedef struct {
	//	unsigned char a;
	//	int b;
	//	long c;
	//}MTestStruct;

	//MTestStruct testStruct;
	//testStruct.a = 0x49;
	//testStruct.b = 2;
	//testStruct.c = 3;

	//// odp : 49 2000 3000

	//char* adr = (char*)(&testStruct);
	//int size = sizeof(testStruct);
	//for (int i = 0; i < size; i++) {
	//	//	printf("%x", (unsigned char)adr[i]);
	//}

	//for (int i = 0; i < size; i++) {
	//	switch (i) {
	//	case (0): adr[i] = 0x49;
	//		break;
	//	case (1): adr[i] = 2;
	//		break;
	//	case (5): adr[5] = 3;
	//		break;

	//	default: adr[i] = 0;

	//	}
	//	printf("%x", (unsigned char)adr[i]);

	//class Base {
	//private:
	//	unsigned char a;
	//public:
	//	virtual void aaa() {};
	//};

	class Base {
	public:
		unsigned char a;
		virtual void aaa() {};
	};

	class MTestStruct : public Base {
	public:
		int b;
		long c;
		virtual void aaa() {};
	};

	MTestStruct testStruct;

	testStruct.a = 1;
	testStruct.b = 2;
	testStruct.c = 3;

	_asm {
		lea edi, testStruct
	}

	printf("%x", testStruct);
}

//_asm{
//	lea edi, testStruct
//	mov[edi], 0x01
//	add edi, 1
//
//	mov[edi], 0x02
//	add edi, 1
//
//	mov[edi], 0x00
//	add edi, 1
//
//	mov[edi], 0x00
//	add edi, 1
//
//	mov[edi], 0x00
//	add edi, 1
//
//	mov[edi], 0x03
//	add edi, 1
//
//	mov[edi], 0x00
//	add edi, 1
//
//	mov[edi], 0x00
//	add edi, 1
//	
//	mov[edi], 0x00
//	add edi, 1
//}

//adr[0] = 1;
//*(int*)adr[1] = 2;
//*(int*)adr[5] = 3;
//
//_asm {
//	lea edi, testStruct
//	mov dword ptr[edi], 2
//	add edi, 4
//	mov dword ptr [edi], 3
//}