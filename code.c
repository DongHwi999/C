#include <stdio.h>

#include <ctype.h>

 

char *encrypt(char *dest, const char *src);

char *decrypt(char *dest, const char *encryptstr);

int main(void)

{

    char source[100] = "Welcome! Here is ehclub.net";

    char en_str[100];

    char de_str[100];
	int a;
 

    printf("source: %s\n", source);

    encrypt(en_str, source);

    printf("encrypted: %s\n", en_str);

    decrypt(de_str, en_str);

    printf("decrypted: %s\n", de_str);

 

    return 0;

}

 

char *encrypt(char *dest, const char *src)

{

    char *origin;

    for (origin = dest; *src; dest++, src++)//���� ���ڸ� ���� ������ �ݺ�

    {

        if (isupper(*src))//�빮���� ��

        {

            *dest = (*src - 'A' + 5) % 26 + 'A';//5ĭ �б�('A'->'F')

        }

        if (islower(*src))//�ҹ����� ��

        {

            *dest = (*src - 'a' + 10) % 26 + 'a';//10ĭ �б�('a'->'k')

        }

        if (isdigit(*src))//���� ������ ��

        {

            *dest = (*src - '0' + 3) % 10 + '0';//3ĭ �б�(0->3)

        }

        if (isalnum(*src) == 0)

        {

            *dest = *src;

        }

    }

    *dest = '\0';

    return origin;

}

char *decrypt(char *dest, const char *encryptstr)

{

    char *origin;

    for (origin = dest; *encryptstr; dest++, encryptstr++)//���� ���ڸ� ���� ������ �ݺ�

    {

        if (isupper(*encryptstr))//�빮���� ��

        {

            *dest = (*encryptstr - 'A' + 21) % 26 + 'A';//21ĭ �б�('F'->'A')

        }

        if (islower(*encryptstr))//�ҹ����� ��

        {

            *dest = (*encryptstr - 'a' + 16) % 26 + 'a';//16ĭ �б�('k'->'a')

        }

        if (isdigit(*encryptstr))//���� ������ ��.

        {

            *dest = (*encryptstr - '0' + 7) % 10 + '0';//7ĭ �б�(3->0)

        }

        if (isalnum(*encryptstr) == 0)

        {

            *dest = *encryptstr;

        }

    }

    *dest = '\0';

    return origin;

}
