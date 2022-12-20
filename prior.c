#include<stdio.h>
#include<stdlib.h>
#define MAX_ELEMENT 20

typedef struct {
	int key; //값
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size; //heap안 저장된 요소의 개수
}HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) {
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) {
	int i;

	//처음 넣는거라면 i가 1이 된다
	i = ++(h->heap_size);

	//새로 넣으려는 노드의 부모노드 찾기!
	//부모노드보다 내가 작거나 && 내가 root가 될 때까지 반복
	while ((item.key > h->heap[i / 2].key) && (i != 1)) {
		//내가 더 크면, 부모노드자리에 내가 올라감
		h->heap[i] = h->heap[i / 2];
		// while 한번 더 돌면 원래 부모였던 노드의, 부모노드 값 ->
		//즉 (=할아버지 할머니 노드^^) 랑 나랑 비교하게 되는 것
		i = i / 2;
	}
	h->heap[i] = item;
}

element delete_max_heap(HeapType* h) {
	element item, temp;
	item = h->heap[1];
	temp = h->heap[h->heap_size];
	//h->heap[h->heap_size]은 힙 배열의 마지막 값

	h->heap_size = h->heap_size - 1;

	int parent, child;
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		//현재 노드의 자식노드 중 더 큰 자식노드 찾기
		//(왼/오 자식 중 더 큰거 찾기)
		if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key))
			child++; //오른쪽 자식 노드의 값이 더 큼

		//마지막 값인 temp가 루트로 올라가서
		//자식노드들과 비교 하면서, 자식보다 작으면 내려가는 상황
		//자식노드보다 크면 교환 멈추기
		if (temp.key >= h->heap[child].key)
			break;

		//자식노드보다 작으면
		//한 단계 아래로 이동하며 교환
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

int main() {
	element e1 = { 3 }, e2 = { 5 }, e3 = { 1 }, e4 = { 7 }, e5 = { 4 };
	element a1;
	HeapType* heap;

	heap = create();
	init(heap);

	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);
	insert_max_heap(heap, e4);
	insert_max_heap(heap, e5);

	int k;
	for ( k = 1; k <= heap->heap_size; k++)
		printf("%d ", heap->heap[k]);

	a1 = delete_max_heap(heap);
	printf("\n\nmax값 인출 %d\n\n", a1.key);
	for (k = 1; k <= heap->heap_size; k++)
		printf("%d ", heap->heap[k]);

	free(heap);

}
