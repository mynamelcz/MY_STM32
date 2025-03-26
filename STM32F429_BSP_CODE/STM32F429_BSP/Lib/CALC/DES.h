#ifndef __DES_H
#define __DES_H










unsigned int des3_cbc_encrypt(unsigned char *pout,
                              unsigned char *pdata,
                              unsigned int nlen,
                              unsigned char *pkey,
                              unsigned int klen,
                              unsigned char *piv);


unsigned int des3_cbc_decrypt(unsigned char *pout,
                              unsigned char *pdata,
                              unsigned int nlen,
                              unsigned char *pkey,
                              unsigned int klen,
                              unsigned char *piv);
#endif

