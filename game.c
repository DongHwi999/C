#include <stdio.h>	//ǥ����������
#include <stdlib.h>	//malloc, free ��
#include <Windows.h>//windows console api ���
#include <time.h>	//���� �õ�� time �Լ� ���
#include <conio.h>	//gotoxy���� ����� api ���

#define FIELD_WIDTH 50	//�ʵ尡�α���
#define FIELD_HEIGHT 25	//�ʵ弼�α���
#define LEFT 75			//Ű���� �� ȭ��ǥ�� char��
#define RIGHT 77		//Ű���� ��
#define UP 72			//Ű���� ��
#define DOWN 80			//������ �Ʒ�
#define ITEM_MAX 2		//ȭ�鿡 ǥ�õǴ� �����۰���
#define ITEM_GOLD 101	//��� ������ �ε�������
#define ITEM_EXP 102	//����ġ ������ �ε�������
#define LEFT_MARGIN 30	//ȭ����ʸ���(����)
#define TOP_MARGIN 3	//ȭ�� ��ܸ���(����)
#define DELAYTIME 200	//Sleep�Լ��� �� x/1000 ��

//�����̸� ������ ���߿��Ḯ��Ʈ ����ü
#pragma pack(push,1)
typedef struct _WORM
{
	int x;	//x��ǥ
	int y;	//y��ǥ
	char direction;	//�������
	struct _WORM *next;	//��������ּ�
	struct _WORM *before;//��������ּ�
}WORM, *pWORM;

//�������� ������ ���Ͽ��Ḯ��Ʈ ����ü
typedef struct _ITEM
{
	int x;
	int y;
	int itemType;
	int itemNo;
	struct _ITEM* next;
}ITEM, *pITEM;
#pragma pack(pop)

//Ŀ���� ���� ��ǥ�� �̵�
void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x + LEFT_MARGIN;//���μ��� ������ ���߱� ���ؼ� ������ ��ǥ�� 2��
	Pos.Y = y + TOP_MARGIN;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//���ӿ������
void PrintField() 
{
	for (int i = 1; i < FIELD_WIDTH; i++)
	{
		gotoxy(i, 0);
		printf("��");
		gotoxy(i, FIELD_HEIGHT);
		printf("��");
	}

	for (int i = 1; i < FIELD_HEIGHT; i++)
	{
		gotoxy(0, i);
		printf("��");
		gotoxy(FIELD_WIDTH,i);
		printf("��");
	}
	gotoxy(0, 0);
	printf("��");
	gotoxy(0, FIELD_HEIGHT);
	printf("��");
	gotoxy(FIELD_WIDTH, 0);
	printf("��");
	gotoxy(FIELD_WIDTH, FIELD_HEIGHT);
	printf("��");
}

//�����̸� �ø��� �Լ�(���߿��Ḯ��Ʈ�� �����ʿ� ��� �߰�)
void AddWorm(pWORM wormTailNode)
{
	pWORM newNode = malloc(sizeof(WORM));
	pWORM temp = wormTailNode->next;

	//�� ����� �ּڰ� �̾��ֱ�;
	newNode->before = wormTailNode;
	newNode->next = wormTailNode->next;
	wormTailNode->next = newNode;
	newNode->next->before = newNode;
	newNode->direction = temp->direction;
	newNode->x = temp->x;
	newNode->y = temp->y;
	switch (temp->direction)
	{
	case LEFT:
		newNode->x = newNode->x + 1;
		break;
	case RIGHT:
		newNode->x = newNode->x - 1;
		break;
	case UP:
		newNode->y = newNode->y + 1;
		break;
	case DOWN:
		newNode->y = newNode->y - 1;
		break;
	default:
		break;
	}
	

}

//���Ḯ��Ʈ�� �޾Ƽ� ������ ���
void PrintWorm(pWORM wormTailNode, pWORM wormHeadNode)	
{
	pWORM curr = wormTailNode->next;
	while (curr != wormHeadNode)
	{
		gotoxy(curr->x, curr->y);
		printf("O");
		curr = curr->next;
	}
}

//�������� ���
void PrintScore(int score)	
{
	gotoxy(FIELD_WIDTH + 3,  3);
	printf("���� : %d��",score);
	gotoxy(FIELD_WIDTH + 3,  5);
	printf("�����Ϸ��� Q�� ��������");
	gotoxy(FIELD_WIDTH + 3,  7);
	printf("������ ȭ��ǥŰ��");
}

//���� ������ �ڸ� �����
void ClearWorm(int x, int y)
{
	gotoxy(x, y);
	printf(" ");
}

//�� �����̱� 
void MoveWorm(pWORM wormTailNode, pWORM wormHeadNode)
{
	pWORM curr;

	curr = wormTailNode->next;
	while (curr != NULL && curr != wormHeadNode->before)
	{
		curr->x = curr->next->x;
		curr->y = curr->next->y;
		curr = curr->next;	
	}
	curr = wormHeadNode->before;
	if (curr->direction == LEFT)
	{
		curr->x--;
	}else if (curr->direction == RIGHT)
	{
		curr->x++;
	}
	else if (curr->direction == UP)
	{
		curr->y--;
	}
	else if (curr->direction == DOWN)
	{
		curr->y++;
	}
}


//�� ����Ʈ�� �Ҵ�� �޸𸮸� ������ ����
void FreeWormList(pWORM wormTailNode)
{
	int a;
	pWORM curr;
	pWORM temp;
	curr = wormTailNode;
	while (curr != NULL)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
}

//item �߻���Ű��
void CreateItem(pITEM itemNode, int* itemNo) {
		
	pITEM newItem = malloc(sizeof(ITEM));
	
	newItem->next = itemNode->next;
	newItem->itemNo = (*itemNo)++;
	itemNode->next = newItem;
	newItem->x = 3 + rand() % (FIELD_WIDTH - 3);
	newItem->y = 3 + rand() % (FIELD_HEIGHT - 3);
	newItem->itemType = ITEM_EXP;
}
//������ ȭ�鿡 ���
void PrintItem(pITEM itemNode)
{
	pITEM curr = itemNode->next;
	while (curr != NULL)
	{
		gotoxy(curr->x, curr->y);
		printf("@");
		curr = curr->next;
	}
}

//����Ʈ���� itemNo�� ��ġ�� ã�Ƽ� ī���͸� ����
int findItemNoInList(pITEM itemNode, int itemNo)	
{
	int numberOfNode = 0;	//����ȣ�� ������ ����

	pITEM curr;		//�����̸� ������ ������
	curr = itemNode->next;		//ù��° �����͸� ����Ű�� �ּҸ� curr�� �Ҵ�

	while (curr != NULL)	//�ݺ����� �����鼭 ã�� �����͸� �߰��ϸ� ����ȣ�� ����
	{
		numberOfNode++;
		if (itemNo == curr->itemNo)
		{
			return numberOfNode;
		}
		curr = curr->next;
	}

	return numberOfNode;
}



//�������� ����ȣ�� �޾� �� ��ȣ�� ��带 ����
void delItemFromList(pITEM itemNode, int targetNodeNumber)
{	
	pITEM beforeTarget;		//������ ����� �ճ��
	pITEM target;		//������ ���

	int counter = 0;

	beforeTarget = itemNode;

	if (targetNodeNumber < 0)   // 0�� �ԷµǸ� FirstNode�� �����ϱ� ������ �������� �ʰ� ����
		return 0;

	//��带 targetNodeNumber-1 ��ŭ �̵����Ѽ� beforeTarget�� ������ ��� ������ �̵���Ŵ
	while (counter < targetNodeNumber - 1)
	{
		beforeTarget = beforeTarget->next;
		counter = counter + 1;
	}

	//��带 ����Ʈ���� ����
	target = beforeTarget->next;
	beforeTarget->next = target->next;
	free(target);
}

//������(�����)�� ���� ��尡 �������� �˻�, 
//delItemNo�� ���� �������� ����� �Լ��� �Ѱ��� ����
int CheckItemHit(pWORM wormHeadPointer, pITEM itemNode, int* delItemNo)
{
	pITEM curr;
	int nodeNo = 0;
	curr = itemNode->next;
	while (curr != NULL)
	{
		if (wormHeadPointer->x == curr->x && wormHeadPointer->y == curr->y)
		{
			if (curr->itemType == ITEM_EXP)
			{
				*delItemNo = curr->itemNo;
				return 1; //������ ������ 1����
			}
		}
		nodeNo++;
		curr = curr->next;
	}
	return 0;//�������� �ȸ����� 0
}

//�������� ��ũ�� ����Ʈ �޸� ����
void FreeItemList(pITEM itemNode)
{
	pITEM curr;
	pITEM temp;
	curr = itemNode;
	while (curr != NULL)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
}

//����� �׽�Ʈ������ ����� ���� ������ ���� ����Ʈ ����Լ�
/* 
void PrintItemList(pITEM itemNode)
{
	pITEM curr;
	curr = itemNode->next;
	gotoxy( -LEFT_MARGIN, 2);
	while (curr != NULL)
	{
		printf("�����۹�ȣ : %d\n", curr->itemNo);
		curr = curr->next;
	}
}
*/
int main()
{	
	pWORM wormHeadNode = malloc(sizeof(WORM));//���߿��Ḯ��Ʈ �����
	pWORM wormTailNode = malloc(sizeof(WORM));//���߿��Ḯ��Ʈ ���ϳ��
	pWORM addWorm = malloc(sizeof(WORM));//ù��° ������
	pITEM itemNode = malloc(sizeof(ITEM));//�����ۿ� ���� ���Ḯ��Ʈ


	wormHeadNode->next = NULL;
	wormHeadNode->before = addWorm;
	addWorm->next = wormHeadNode;
	addWorm->before = wormTailNode;
	addWorm->x = FIELD_WIDTH/2;
	addWorm->y = FIELD_HEIGHT/2;
	addWorm->direction = RIGHT;
	wormTailNode->next = addWorm;
	wormTailNode->before = NULL;

	itemNode->next = NULL;
	itemNode->itemNo = -1;
	
	//������ ���ӽ��� ������ ����
	for(int i = 9; i>0 ; i--)
		AddWorm(wormTailNode);
	
	//���� �Ӹ��� ����Ű�� ������
	pWORM wormHeadPointer = addWorm;

	int score = 0;			//��������
	int itemCounter = 0;	//������ ���� �ѵ� ī����
	char key;				//Ű�Է¹��� ����
	int delItemNo=0;		//��������۳ѹ��� ���� �����ʱ�ȭ
	int itemNo = 10000		;//�������� ���ʹ�ȣ

	//������ ���� ��ġ ���� �õ�
	srand((unsigned int)time(NULL));
	
	system("cls");	//ȭ�������
	PrintField();	//�ʵ� ���


	while (1)
	{
		//�׽�Ʈ�� ��ºκ�
		//gotoxy(-LEFT_MARGIN, 0);
		//printf("���� ������ : %d\n",delItemNo);
		//PrintItemList(itemNode);

		if (_kbhit() != 0)
		{
			
			key = _getch();
			if (key == 'q' || key == 'Q')
			{
				printf("%c", key);
				break;
			}
			if (key == LEFT && wormHeadPointer->direction != RIGHT)
			{
				wormHeadPointer->direction = LEFT;
			}
			else if (key == RIGHT && wormHeadPointer->direction != LEFT)
			{
				wormHeadPointer->direction = RIGHT;
			}
			else if (key == UP && wormHeadPointer->direction != DOWN)
			{
				wormHeadPointer->direction = UP;
			}
			else if (key == DOWN && wormHeadPointer->direction != UP)
			{
				wormHeadPointer->direction = DOWN;
			}
		}
		
		//�� ������ �ڸ� �����
		ClearWorm(wormTailNode->next->x, wormTailNode->next->y);
		
		//�� ��ĭ�� �����̱�
		MoveWorm(wormTailNode, wormHeadNode);

		//���� �ε����� ���ӿ���
		if (wormHeadPointer->x == 0 || wormHeadPointer->x == FIELD_WIDTH || wormHeadPointer->y == 0 || wormHeadPointer->y == FIELD_HEIGHT)
		{
			system("cls");
			gotoxy(FIELD_WIDTH / 2 -10 , FIELD_HEIGHT / 2);
			printf("���� �ε������ϴ�. GAME OVER");
			FreeWormList(wormTailNode);
			FreeItemList(itemNode);
			return 0;
		}

		//�������� ����
		while (itemCounter < ITEM_MAX)
		{
			CreateItem(itemNode,&itemNo);
			itemCounter++;
		}

		//������ �Ծ����� Ȯ��
		if (CheckItemHit(wormHeadPointer, itemNode, &delItemNo))
		{
			AddWorm(wormTailNode);
			delItemFromList(itemNode, findItemNoInList(itemNode,delItemNo));
			score += 100;
			itemCounter--;
		}
		PrintItem(itemNode);
		PrintWorm(wormTailNode, wormHeadNode);
		PrintScore(score);
		Sleep(DELAYTIME);
	}

	FreeWormList(wormTailNode);
	FreeItemList(itemNode);

	return 0;
}
