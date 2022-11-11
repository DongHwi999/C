// ���� Ž�� Ʈ���� ����� ���� ����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX_WORD_SIZE	 100
#define MAX_MEANING_SIZE 200

// ������ ����
typedef struct {
	char word[MAX_WORD_SIZE];		// Ű�ʵ�
	char meaning[MAX_MEANING_SIZE];
} element;
// ����� ����
typedef struct TreeNode {
	element key;
	TreeNode *left, *right;
} TreeNode;

// ���� e1 < e2 �̸� -1 ��ȯ
// ���� e1 == e2 �̸� 0 ��ȯ
// ���� e1 > e2 �̸� 1 ��ȯ
int compare(element e1, element e2)
{
	return strcmp(e1.word, e2.word);
}
// ���� Ž�� Ʈ�� ��� �Լ�
void display(TreeNode * p)
{
	if (p != NULL) {
		printf("(");
		display(p->left);
		printf("%s:%s", p->key.word, p->key.meaning);
		display(p->right);
		printf(")");
	}
}
// ���� Ž�� Ʈ�� Ž�� �Լ�
TreeNode * search(TreeNode * root, element key)
{
	TreeNode * p = root;
	while (p != NULL) {
		if (compare(key, p->key) == 0)
			return p;
		else if (compare(key, p->key) < 0)
			p = p->left;
		else if (compare(key, p->key) > 0)
			p = p->right;
	}
	return p; 	// Ž���� �������� ��� NULL ��ȯ
}
TreeNode * new_node(element item)
{
	TreeNode * temp = (TreeNode *)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
TreeNode * insert_node(TreeNode * node, element key)
{
	// Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�. 
	if (node == NULL) return new_node(key);

	// �׷��� ������ ��ȯ������ Ʈ���� ��������. 
	if (compare(key, node->key)<0)
		node->left = insert_node(node->left, key);
	else if (compare(key, node->key)>0)
		node->right = insert_node(node->right, key);
	// ��Ʈ �����͸� ��ȯ�Ѵ�. 
	return node;
}
TreeNode * min_value_node(TreeNode * node)
{
	TreeNode * current = node;
	// �� ���� �ܸ� ��带 ã���� ������
	while (current->left != NULL)
		current = current->left;
	return current;
}
// ���� Ž�� Ʈ���� Ű�� �־����� Ű�� ����� ��带 �����ϰ� 
// ���ο� ��Ʈ ��带 ��ȯ�Ѵ�. 
TreeNode * delete_node(TreeNode * root, element key)
{
	if (root == NULL) return root;

	// ���� Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� �ִ� ����
	if (compare(key, root->key)<0)
		root->left = delete_node(root->left, key);
	// ���� Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� �ִ� ����
	if (compare(key, root->key)>0)
		root->right = delete_node(root->right, key);
	// Ű�� ��Ʈ�� ������ �� ��带 �����ϸ� ��
	else {
		// ù ��°�� �� ��° ���
		if (root->left == NULL) {
			TreeNode * temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode * temp = root->left;
			free(root);
			return temp;
		}
		// �� ��° ���
		TreeNode * temp = min_value_node(root->right);

		// �߿� ��ȸ�� �İ� ��带 �����Ѵ�. 
		root->key = temp->key;
		// �߿� ��ȸ�� �İ� ��带 �����Ѵ�. 
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

//
void help()
{
	printf("�뷡�� ������ ���� ���α׷�\n\n 1. �뷡�߰�\n 2. �뷡 �˻�\n 0. ����\n\n �޴���ȣ ����> ");
}
// ���� Ž�� Ʈ���� ����ϴ� ���� ���� ���α׷� 

void help2()
{
	printf("\n �뷡 �˻� \n\n 1. �뷡 ���� \n 2. ���� �̸� \n\n �޴�����> ");
}

void help3()
{
	printf("\n 1. ���� \n 2. ����\n\n �޴�����> ");
}
int main(void)
{
   char command, command2, command3;
   element e;
   TreeNode * root = NULL;
   TreeNode * tmp;

   do {
      help();
      command = getchar();
      getchar();      // ����Ű ����
      switch (command) {
      case '1':
         printf("����:");
         gets(e.word);
         printf("����:");
         gets(e.meaning);
         root = insert_node(root, e);
         break;
      case '2':
         do {
            help2();
            command2 = getchar();
            getchar();
            switch (command2){
               case '1':
                  do {
                     help3();
                     command3 = getchar();
                     getchar();
                     switch (command3){
                        case '1':
                           printf("��� �Է�(�ѱ�): ");
                           gets(e.word);
                           tmp = search(root,e);
                           if(tmp != NULL)
                              printf("����:%s\n", e.meaning);
                           break;
                        case '2':
                           printf("��� �Է�(����): "); 
                           gets(e.word);
                           tmp = search(root,e);
                           if(tmp != NULL)
                              printf("����:%s\n", e.meaning);
                           break;
                     }
                  } while (command3 != '0');
                  break;
               case '2':
                  printf("������ �˻�\n �����Է�: ");
                  gets(e.meaning);
                  tmp = search(root,e);
                  if(tmp != NULL)
                     printf("����: %s\n",e.word);
                  break; 
                  
            }
         } while (command2 != '0');
         break;
      }

   } while (command != '0');
   return 0;
}
