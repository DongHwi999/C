#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
typedef struct 
{ 
  char word[20]; 
  int length; 
  int vowel; 
} dic; 
int func_compare(dic *a, dic *b) 
{ 
  if (a->length > b->length) 
  return 1; 
  else if (a->length < b->length) 
  return -1; 
  else 
  return 0; 
} 
int main() 
{ 
  int n; 
  int i, j, k; 
  dic* words; 
  scanf_s("%d", &n);  
  words = (dic*)malloc(sizeof(dic) * n); 
  for (i = 0; i < n; i++) 
  { 
    scanf_s("%s", words[i].word, sizeof(words[i].word)); 
    words[i].vowel = 0; 
    words[i].length = strlen(words[i].word); 
    for (j = 0; j < words[i].length; j++) 
    if (words[i].word[j] == 'a' || 
    words[i].word[j] == 'e' || 
    words[i].word[j] == 'i' || 
    words[i].word[j] == 'o' || 
    words[i].word[j] == 'u') 
    words[i].vowel += 1; 
 } 
 qsort(words, n, sizeof(dic), func_compare); 
 for (i = 0; i < n; i++) { 
   printf("%s, %d\n", words[i].word, words[i].vowel); 
} 
free(words); 
return 0; 
}
