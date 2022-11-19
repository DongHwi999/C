#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>




struct node
{
   char v;
   int cnt;
   node*next;
   node*left;
   node*right;
};

node*head = 0;

int stack[100];
int top = -1;

void push(int n)
{
   top += 1;
   stack[top] = n;
}

int pop()
{
   int result = stack[top];
   top -= 1;
   return result;
}

void addToSLL(node* cur)
{
   if (head == 0)
   {
      head = cur;
      return;
   }

   node*temp = head;
   while (temp->next != 0)
   {
      temp = temp->next;
   }
   temp->next = cur;
}


void createVertex(char _v)
{   
   node*newOne = (node*)malloc(sizeof(node));
   newOne->v = _v;
   newOne->cnt = 1;
   newOne->left = newOne->right = newOne->next = 0;

   addToSLL(newOne);
}

node* findVertex(char v)
{
   node*temp = head;
   while (temp != 0)
   {
      if (temp->v == v)
      {
         return temp;
      }
      temp = temp->next;
   }
   return 0;
}

void cntCharacterNum(char* _buf)
{
   char v;
   for (int i = 0; i < 99; i++)
   {
      if (_buf[i] == '\0')
      {
         return;
      }
      v = _buf[i];
      if (findVertex(v) == 0)
      {
         createVertex(v);
      }
      else
      {
         node*find = findVertex(v);
         find->cnt += 1;
      }
   }
}

node*findSmallest()
{
   
   int short_num = INT_MAX;
   node*short_node = head;

   if (head == 0)
   {
      return 0;
   }
   
   node*temp = head;
   while (temp != 0)
   {
      if (temp->cnt < short_num)
      {
         short_node = temp;
         short_num = temp->cnt;
      }
      temp = temp->next;
   }
   
   if (short_node == head)
   {
      head = head->next;
   }
   else
   {
      node*prev = head;
      while (prev->next != short_node)
      {
         prev = prev->next;
      }
      prev->next = short_node->next;
   }

   short_node->next = 0;
   return short_node;
}

node* buildHuffmanTree( )
{
   while (1)
   {
      node* first = findSmallest();   // 빈도수 제일 낮은 것을 뽑는다.
      node* second = findSmallest();

      if (second == 0)   // 마지막에 트리만 뽑힌다.
      {
         return first;
      }

      node*newOne = (node*)malloc(sizeof(node));
      newOne->next = 0;
      newOne->left = first;
      newOne->right = second;
      newOne->cnt = first->cnt + second->cnt;

      addToSLL(newOne);   // 트리 전체를 구성원으로 넣는다.
   }
   
}


void showAll()
{
   node*temp = head;
   while (temp != 0)
   {
      printf("%c : %d\n", temp->v, temp->cnt);
      temp = temp->next;
   }
}

void showCode()
{
   for (int i = top-1; i >= 0; i--)
   {
      printf("%d", stack[i]);
   }
   printf("\n");
}

void inorderTraversal(node* cur)
{
   if (cur == 0)
   {
      pop();
      return;
   }
   push(0);
   inorderTraversal(cur->left);
   if (cur->left == 0 && cur->right == 0)
   {
      printf("%c : ",cur->v);
      showCode();
   }
   push(1);
   inorderTraversal(cur->right);
   pop();
}

int main(void)
{
   FILE*f = 0;
   f = fopen("alice.txt", "rt");

   while (!feof(f))
   {
      char buf[100];

      fgets(buf, 99, f);
      
      // buf에 담긴 내용을 한 글자씩 읽으면서
      // 각 character의 개수를 센다.

      // 단, buf[i] != '\0'
      // 마지막에 읽는 것은 99개까지 못읽을 수 있다. null characet가 아닌 때만 개수를 세야 한다.
      
      cntCharacterNum(buf);
   }

   //showAll();

   node*tree = buildHuffmanTree();

   inorderTraversal(tree);

   return 0;
}
