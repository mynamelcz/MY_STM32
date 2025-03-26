#ifndef __AES2__
#define __AES2__

//enum KeySize { Bits128, Bits192, Bits256 };  // key size, in bits, for construtor
#define Bits128	16
#define Bits192	24
#define Bits256	32




// loopnum :可选10 12 14 16
void Aes_Init(int keysize, unsigned char* keyBytes,int loopnum);
//Aes加密函数
void Aes_Cipher(unsigned char* input, unsigned char* output);
//Aes解密函数
void Aes_InvCipher(unsigned char* input,unsigned char* output);



#endif









