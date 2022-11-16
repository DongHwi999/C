#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode
{
	element data;
	struct ListNode* link;
} ListNode;

void insert(ListNode** phead, ListNode* p, ListNode* new_p)
{
	if (*phead == NULL)
	{
		new_p->link = NULL;
		*phead = new_p;
	}
	else
	{
		new_p->link = NULL;
		ListNode* p = *phead;
		while (p->link != NULL)
			p = p->link;
		p->link = new_p;
	}
}

ListNode* create_node(element data)
{
	ListNode* new_p;
	new_p = (ListNode*)malloc(sizeof(new_p));
	new_p->data = data;
	new_p->link = NULL;
	return new_p;
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d ", p->data);
}

int get_sum(ListNode* head)
{
	int sum = 0;
	for (ListNode* p = head; p != NULL; p = p->link)
		sum += p->data;
	return sum;
}

int main(void)
{
	int n, num;
	ListNode* head = NULL;

	printf("노드의 개수 : ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		printf("노드 #%d 데이터 : ", i);
		scanf("%d", &num);
		insert(&head, head, create_node(num));
	}

	printf("연결 리스트의 데이터 합 : %d\n", get_sum(head));
	return 0;
}

