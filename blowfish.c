#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

#include <openssl/ssl.h>
#include <openssl/evp.h>
#include <openssl/crypto.h>

struct mykey
{
    unsigned char key[16];
    unsigned char vec[8];
};

// chipteer �ʱ�ȭ 
EVP_CIPHER_CTX ctx;

// �������� ��´�. 
// �ʿ信 ���� /dev/random�� ����ص� �ȴ�.
int getrandom(char *rand, size_t size)
{
    struct timeval tp;
    int i = 0;
    int ran;

    gettimeofday(&tp, NULL);
    srandom(tp.tv_sec | tp.tv_usec);

    while(1)
    {
        if (!(size / (4*(i+1)))) break;

        ran = random();
        memcpy(rand+(i*4), (void *)&ran, 4);
        //memcpy(rand, (void *)&ran, 4);
        i++;
    }
}

// Ű ������
int keygen(struct mykey *lkey)
{
    int i = 0;
    char keyseed[24];
    getrandom(keyseed, 24);
    memcpy((void *)lkey->key, keyseed,   16);
    memcpy((void *)lkey->vec, keyseed+16, 8);
}

// chiper�� �ʱ�ȭ �Ѵ�.
int cryptinit()
{
    EVP_CIPHER_CTX_init(&ctx);
}

// data�� lkey�� �̿��ؼ� ��ȣȭ �Ѵ�.
int encrypt(unsigned char *data, size_t n, unsigned char *buf, struct mykey *lkey)
{
    int olen = 0, tlen, i;

    char test[256] = {0x00,};
    printf("msg size is %d\n", n);
    EVP_EncryptInit(&ctx, EVP_bf_cbc(), lkey->key, lkey->vec);
    if (EVP_EncryptUpdate(&ctx, buf, &olen, data, n+4) != 1)
    {
        printf("Error in encrypt update\n");
        return -1;
    }


    if (EVP_EncryptFinal(&ctx, buf+olen, &tlen) != 1)
    {
        printf("Error in encrypt final\n");
        return -1;
    }
    printf("Encrypt size=%d, %d\n", olen, tlen);
    EVP_CIPHER_CTX_cleanup(&ctx);
    return olen+tlen;
}

// �־��� ��ȣȭ�� �����͸� lkey�� �̿��ؼ� ��ȣȭ �Ѵ�.
int decrypt(char *cryptmessage, unsigned char *outbuf, struct mykey *lkey, size_t n)
{
    int olen, tlen;

    EVP_DecryptInit(&ctx, EVP_bf_cbc(), lkey->key, lkey->vec);
    if(EVP_DecryptUpdate(&ctx, outbuf, &olen, (unsigned char *)cryptmessage, n) != 1)
    {
        printf("error in decrypt \n");
        return -1;
    }

    if(EVP_DecryptFinal(&ctx, outbuf+olen, &tlen) != 1)
    {
        printf("error in decrypt final\n");
        return -1;
    }
    return olen+tlen;
}

int main()
{
    int i;
    struct mykey lkey;
    unsigned char buf[256] = {0x00,};
    unsigned char buf2[256] = {0x00,};
    unsigned char hello[256] = {0x00,};
    unsigned char hello2[256] = {0x00,};
    int n;

    strcpy((char *)hello, "hello world test test test\n");
    strcpy((char *)hello2, "hello hello..\n");
    keygen(&lkey);
    cryptinit();

    n = encrypt(hello, strlen((char *)hello), buf, &lkey);
    decrypt((char *)buf, buf2, &lkey, n);
    printf("%s\n",  buf2);
    printf("====================");

    n = encrypt(hello2, strlen((char *)hello2), buf, &lkey);
    decrypt((char *)buf, buf2, &lkey, n);
    printf("%s\n",  buf2);
}
