// 이진 탐색 트리를 사용한 영어 사전
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX_WORD_SIZE	 100
#define MAX_MEANING_SIZE 200

// 데이터 형식
typedef struct {
	char word[MAX_WORD_SIZE];		// 키필드
	char meaning[MAX_MEANING_SIZE];
} element;
// 노드의 구조
typedef struct TreeNode {
	element key;
	TreeNode *left, *right;
} TreeNode;

// 만약 e1 < e2 이면 -1 반환
// 만약 e1 == e2 이면 0 반환
// 만약 e1 > e2 이면 1 반환
int compare(element e1, element e2)
{
	return strcmp(e1.word, e2.word);
}
// 이진 탐색 트리 출력 함수
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
// 이진 탐색 트리 탐색 함수
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
	return p; 	// 탐색에 실패했을 경우 NULL 반환
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
	// 트리가 공백이면 새로운 노드를 반환한다. 
	if (node == NULL) return new_node(key);

	// 그렇지 않으면 순환적으로 트리를 내려간다. 
	if (compare(key, node->key)<0)
		node->left = insert_node(node->left, key);
	else if (compare(key, node->key)>0)
		node->right = insert_node(node->right, key);
	// 루트 포인터를 반환한다. 
	return node;
}
TreeNode * min_value_node(TreeNode * node)
{
	TreeNode * current = node;
	// 맨 왼쪽 단말 노드를 찾으러 내려감
	while (current->left != NULL)
		current = current->left;
	return current;
}
// 이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고 
// 새로운 루트 노드를 반환한다. 
TreeNode * delete_node(TreeNode * root, element key)
{
	if (root == NULL) return root;

	// 만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것임
	if (compare(key, root->key)<0)
		root->left = delete_node(root->left, key);
	// 만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것임
	if (compare(key, root->key)>0)
		root->right = delete_node(root->right, key);
	// 키가 루트와 같으면 이 노드를 삭제하면 됨
	else {
		// 첫 번째나 두 번째 경우
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
		// 세 번째 경우
		TreeNode * temp = min_value_node(root->right);

		// 중외 순회시 후계 노드를 복사한다. 
		root->key = temp->key;
		// 중외 순회시 후계 노드를 삭제한다. 
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

//
void help()
{
	printf("노래방 데이터 관리 프로그램\n\n 1. 노래추가\n 2. 노래 검색\n 0. 종료\n\n 메뉴번호 선택> ");
}
// 이진 탐색 트리를 사용하는 영어 사전 프로그램 

void help2()
{
	printf("\n 노래 검색 \n\n 1. 노래 제목 \n 2. 가수 이름 \n\n 메뉴선택> ");
}

void help3()
{
	printf("\n 1. 제목 \n 2. 가수\n\n 메뉴선택> ");
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
      getchar();      // 엔터키 제거
      switch (command) {
      case '1':
         printf("제목:");
         gets(e.word);
         printf("가수:");
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
                           printf("곡목 입력(한글): ");
                           gets(e.word);
                           tmp = search(root,e);
                           if(tmp != NULL)
                              printf("가수:%s\n", e.meaning);
                           break;
                        case '2':
                           printf("곡목 입력(영어): "); 
                           gets(e.word);
                           tmp = search(root,e);
                           if(tmp != NULL)
                              printf("가수:%s\n", e.meaning);
                           break;
                     }
                  } while (command3 != '0');
                  break;
               case '2':
                  printf("가수로 검색\n 가수입력: ");
                  gets(e.meaning);
                  tmp = search(root,e);
                  if(tmp != NULL)
                     printf("제목: %s\n",e.word);
                  break; 
                  
            }
         } while (command2 != '0');
         break;
      }

   } while (command != '0');
   return 0;
}
