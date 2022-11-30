#include <stdlib.h>
#include <stdio.h>

#define BUCKET_SIZE (23)
#define FALSE (-1)
#define TRUE (1)

/* 해시테이블 연결리스트 구조체 */
typedef struct hash_s{
    struct hash_s   *next;
    int             value;
}   hash_t;

/* 해시테이블 초기화 함수 */
void init_hashtable(hash_t **hashtable)
{
	int i;
    for (i = 0; i < BUCKET_SIZE; i++)
        hashtable[i] = NULL;
}

/* 해시테이블 메모리해제 함수 */
void node_free(hash_t **hashtable)
{
	int i;
    for (i = 0; i < BUCKET_SIZE; i++)
    {
        free(hashtable[i]);
        hashtable[i] = NULL;
    }
}

/* 지정된 해시값으로 변경하는 함수 */
int hash(int value)
{
    int hs;

    hs = value % BUCKET_SIZE;
    if (hs < 0)
        hs += BUCKET_SIZE;
    return (hs);
}

/* 새로운 노드를 생성하여 value를 삽입하는 함수(add_value함수 내부에 존재) */
void add_index(hash_t **hashtable, int val)
{
    hash_t *new_node;

    new_node = (hash_t *)malloc(sizeof(hash_t));
    new_node->value = val;
    new_node->next = *hashtable;
    *hashtable = new_node;
}

/* value를 해시테이블에서 찾아주는 함수 */
int find_value(hash_t **hashtable, int val)
{
    int hs;
    hash_t *finder;

    hs = hash(val);
    finder = hashtable[hs];
    while (finder != NULL)
    {
        if (finder->value == val)
            return (TRUE);
        finder = finder->next;
    }
    return (FALSE);
}

/* 새로운 value를 해시테이블에 추가해주는 함수 */
int add_value(hash_t **hashtable, int val)
{
    int hs;

    if (find_value(hashtable, val) == TRUE)
        return (FALSE);
    hs = hash(val);
    while (*hashtable != NULL)
        *hashtable = (*hashtable)->next;
    add_index(&hashtable[hs], val);
    return (hs);
}

/* 해당 색인에 저장된 모든 value를 출력하는 함수 */
void print_index(hash_t **hashtable, int index)
{
    hash_t *finder;

    finder = hashtable[index];
    if (finder == NULL)
    {
        printf("존재하는 요소가 없습니다.\n");
        return ;
    }
    printf("%d색인 요소: ", index);
    while(finder != NULL)
    {
        printf("%d ", finder->value);
        finder = finder->next;
    }
    printf("\n");
}

/* 해당 value가 저장된 노드를 삭제하는 함수 */
int delete_value(hash_t **hashtable, int val)
{
    int hs;
    hash_t *temp;
    hash_t *finder;

    hs = hash(val);
    finder = hashtable[hs];
    if (finder == NULL)
        return (FALSE);
    if (hashtable[hs]->value == val)
    {
        temp = hashtable[hs]->next;
        free(hashtable[hs]);
        hashtable[hs] = temp;
        return (TRUE);
    }
    while (finder->next != NULL)
    {
        if ((finder->next)->value == val)
        {
            temp = (finder->next)->next;
            free(finder->next);
            finder->next = temp;
            return (TRUE);
        }
        finder = finder->next;
    }
    return (FALSE);
}

int main(void)
{
    hash_t *hashtable[BUCKET_SIZE];
    hash_t *temp;
    int index;

    init_hashtable(hashtable); 

    index = add_value(hashtable, 333);
    printf("%d가 %d번 색인에 저장되었습니다.\n", 333, index);
    index = add_value(hashtable, 356);
    printf("%d가 %d번 색인에 저장되었습니다.\n", 356, index);
    index = add_value(hashtable, 34);
    printf("%d가 %d번 색인에 저장되었습니다.\n", 34, index);
    print_index(hashtable, 11);
    printf("\n");

    index = delete_value(hashtable, 356);
    if (index == TRUE)
        printf("정상적으로 값이 삭제되었습니다.\n");
    else
        printf("삭제할 값이 존재하지않습니다.\n");
    print_index(hashtable, 11);
    printf("\n");

    index = delete_value(hashtable, 27);  // 존재하지않는 값을 삭제할 시
    if (index == TRUE)
        printf("정상적으로 값이 삭제되었습니다.\n");
    else
        printf("삭제할 값이 존재하지않습니다.\n");
    node_free(hashtable);
}
