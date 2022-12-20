#include<stdio.h>
#include<stdlib.h>
#define MAX_ELEMENT 20

typedef struct {
	int key; //��
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size; //heap�� ����� ����� ����
}HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) {
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) {
	int i;

	//ó�� �ִ°Ŷ�� i�� 1�� �ȴ�
	i = ++(h->heap_size);

	//���� �������� ����� �θ��� ã��!
	//�θ��庸�� ���� �۰ų� && ���� root�� �� ������ �ݺ�
	while ((item.key > h->heap[i / 2].key) && (i != 1)) {
		//���� �� ũ��, �θ����ڸ��� ���� �ö�
		h->heap[i] = h->heap[i / 2];
		// while �ѹ� �� ���� ���� �θ𿴴� �����, �θ��� �� ->
		//�� (=�Ҿƹ��� �ҸӴ� ���^^) �� ���� ���ϰ� �Ǵ� ��
		i = i / 2;
	}
	h->heap[i] = item;
}

element delete_max_heap(HeapType* h) {
	element item, temp;
	item = h->heap[1];
	temp = h->heap[h->heap_size];
	//h->heap[h->heap_size]�� �� �迭�� ������ ��

	h->heap_size = h->heap_size - 1;

	int parent, child;
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		//���� ����� �ڽĳ�� �� �� ū �ڽĳ�� ã��
		//(��/�� �ڽ� �� �� ū�� ã��)
		if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key))
			child++; //������ �ڽ� ����� ���� �� ŭ

		//������ ���� temp�� ��Ʈ�� �ö󰡼�
		//�ڽĳ���� �� �ϸ鼭, �ڽĺ��� ������ �������� ��Ȳ
		//�ڽĳ�庸�� ũ�� ��ȯ ���߱�
		if (temp.key >= h->heap[child].key)
			break;

		//�ڽĳ�庸�� ������
		//�� �ܰ� �Ʒ��� �̵��ϸ� ��ȯ
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
	printf("\n\nmax�� ���� %d\n\n", a1.key);
	for (k = 1; k <= heap->heap_size; k++)
		printf("%d ", heap->heap[k]);

	free(heap);

}
