#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP (int)2e5

typedef struct _piroQ {
	int heap[MAX_HEAP];
	int count;
}prioQ;

void nodeChange(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void push(prioQ* root, int data) {
	if (root->count >= MAX_HEAP) return;
	root->heap[root->count] = data;

	int now = root->count;
	int parent = (now - 1) / 2;
	
	while (now>0 && root->heap[now] < root->heap[parent]) {
		nodeChange(&root->heap[now], &root->heap[parent]);
		now = parent;
		parent = (parent - 1) / 2;
	}
	root->count++;
}

int pop(prioQ* root) {
	if (root->count <= 0) return -99999;
	
	int ret = root->heap[0];
	int now = 0, left = 1, right = 2;
	int target = now;
	
	root->count--;
	root->heap[0] = root->heap[root->count];
	root->heap[root->count] = 0;

	while (1) {
		if (left < root->count && root->heap[target] > root->heap[left]) target = left;
		if (right < root->count && root->heap[target] > root->heap[right] ) target = right;

		if (target == now) break;
		else {
			nodeChange(&root->heap[now], &root->heap[target]);
			now = target;
			left = now * 2 + 1;
			right = now * 2 + 2;
		}
	}
	return ret;
}

int empty(prioQ* root) {
	return (root->count == 0);
}

int top(prioQ* root) {
	if (empty(root)) return -99999;
	return root->heap[0];
}

#define MAXN (int)1e5

typedef struct _classroom {
	int s;
	int t;
}classroom;

classroom room[MAXN + 5];

int N;

int comp(const void* a, const void* b) {
	return ((classroom*)a)->s - ((classroom*)b)->s;
}

void InputData() {
	scanf("%d", &N);
	int n;
	for (n = 0; n < N; n++) {
		scanf("%d %d", &room[n].s, &room[n].t);
	}
}

int Solve() {
	prioQ root;
	root.count = 0;

	qsort(room, N, sizeof(room[0]), comp);

	printf("\n");
	int n;
	for (n = 0; n < N; n++) {
		printf("%d %d\n", room[n].s, room[n].t);
	}

	// 첫번째 수업의 끝나는 시간을 넣음.
	push(&root, room[0].t);

	for (int n = 1; n < N; n++) {
		if (top(&root) <= room[n].s) {
			pop(&root);
		}
		push(&root, room[n].t);
	}
	return root.count;
}

int main() {
#if 1
	int ans = -1;

	InputData();

	ans = Solve();
	printf("%d\n", ans);
#else
	int data;
	int n = 5;

	prioQ root;
	root.count = 0;

	push(&root, 40);
	push(&root, 30);
	push(&root, 50);
	push(&root, 10);
	push(&root, 20);

	for (int i = 0; i < n; i++) {
		data = pop(&root);
		printf("%d ", data);
	}

#endif
	return 0;
}
