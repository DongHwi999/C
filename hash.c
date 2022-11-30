#include <stdlib.h>
#include <stdio.h>

#define BUCKET_SIZE (23)
#define FALSE (-1)
#define TRUE (1)

/* �ؽ����̺� ���Ḯ��Ʈ ����ü */
typedef struct hash_s{
    struct hash_s   *next;
    int             value;
}   hash_t;

/* �ؽ����̺� �ʱ�ȭ �Լ� */
void init_hashtable(hash_t **hashtable)
{
	int i;
    for (i = 0; i < BUCKET_SIZE; i++)
        hashtable[i] = NULL;
}

/* �ؽ����̺� �޸����� �Լ� */
void node_free(hash_t **hashtable)
{
	int i;
    for (i = 0; i < BUCKET_SIZE; i++)
    {
        free(hashtable[i]);
        hashtable[i] = NULL;
    }
}

/* ������ �ؽð����� �����ϴ� �Լ� */
int hash(int value)
{
    int hs;

    hs = value % BUCKET_SIZE;
    if (hs < 0)
        hs += BUCKET_SIZE;
    return (hs);
}

/* ���ο� ��带 �����Ͽ� value�� �����ϴ� �Լ�(add_value�Լ� ���ο� ����) */
void add_index(hash_t **hashtable, int val)
{
    hash_t *new_node;

    new_node = (hash_t *)malloc(sizeof(hash_t));
    new_node->value = val;
    new_node->next = *hashtable;
    *hashtable = new_node;
}

/* value�� �ؽ����̺��� ã���ִ� �Լ� */
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

/* ���ο� value�� �ؽ����̺� �߰����ִ� �Լ� */
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

/* �ش� ���ο� ����� ��� value�� ����ϴ� �Լ� */
void print_index(hash_t **hashtable, int index)
{
    hash_t *finder;

    finder = hashtable[index];
    if (finder == NULL)
    {
        printf("�����ϴ� ��Ұ� �����ϴ�.\n");
        return ;
    }
    printf("%d���� ���: ", index);
    while(finder != NULL)
    {
        printf("%d ", finder->value);
        finder = finder->next;
    }
    printf("\n");
}

/* �ش� value�� ����� ��带 �����ϴ� �Լ� */
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
    printf("%d�� %d�� ���ο� ����Ǿ����ϴ�.\n", 333, index);
    index = add_value(hashtable, 356);
    printf("%d�� %d�� ���ο� ����Ǿ����ϴ�.\n", 356, index);
    index = add_value(hashtable, 34);
    printf("%d�� %d�� ���ο� ����Ǿ����ϴ�.\n", 34, index);
    print_index(hashtable, 11);
    printf("\n");

    index = delete_value(hashtable, 356);
    if (index == TRUE)
        printf("���������� ���� �����Ǿ����ϴ�.\n");
    else
        printf("������ ���� ���������ʽ��ϴ�.\n");
    print_index(hashtable, 11);
    printf("\n");

    index = delete_value(hashtable, 27);  // ���������ʴ� ���� ������ ��
    if (index == TRUE)
        printf("���������� ���� �����Ǿ����ϴ�.\n");
    else
        printf("������ ���� ���������ʽ��ϴ�.\n");
    node_free(hashtable);
}
