#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
 
#include <string.h>
#include<stdbool.h>
 
 
 
 
 
 
int main() {
 
    char c[51];
    int alpha[26] = { 0 };
    scanf("%s", c);
    
 
    int lenStr = strlen(c);
 
    for (int i = 0; i < lenStr; i++) {
        alpha[c[i] - 'A']++;
    }
    
    //홀수 일때 가운데를 고려
    int count = 0;
    char mid=NULL;
    for (int i = 0; i < 26; i++) {
        if (alpha[i] % 2 != 0) {
            mid = i+'A';
            count++;
            alpha[i]--;
 
        }
    }
 
    if (count == 0) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < alpha[i] / 2; j++) {
                printf("%c", i + 'A');
            }
        }
 
        for (int i = 25; i >= 0; i--) {
            for (int j = 0; j < alpha[i] / 2; j++) {
                printf("%c", i + 'A');
            }
        }
    }
    else if (count == 1) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < alpha[i] / 2; j++) {
                printf("%c", i + 'A');
            }
        }
        printf("%c", mid);
 
        for (int i = 25; i >= 0; i--) {
            for (int j = 0; j < alpha[i] / 2; j++) {
                printf("%c", i + 'A');
            }
        }
 
    }
    else {
        printf("I'm Sorry Hansoo");
    }
    
    
}
 

