#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE    100

typedef int Element;
Element data[MAX_QUEUE_SIZE];   
int    front;        
int    rear;           

void error(char* str)
{
    fprintf(stderr, "%s\n", str);
    exit(1);
};
void init_queue() { front = rear = 0; ; }
int is_empty() { return front == rear; }
int is_full() { return front == (rear + 1) % MAX_QUEUE_SIZE; }
int size() { return(rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; }

void enqueue(Element val)
{
    if (is_full())
        error("  큐 포화 에러");
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    data[rear] = val;
}
Element dequeue()
{
    if (is_empty())
        error("  큐 공백 에러");
    front = (front + 1) % MAX_QUEUE_SIZE;
    return data[front];
}
Element peek()
{
    if (is_empty())
        error("  큐 공백 에러");
    return data[(front + 1) % MAX_QUEUE_SIZE];
}


void init_deque() { init_queue(); }
void add_rear(Element val) { enqueue(val); }
Element delete_front() { return dequeue(); }
Element get_front() { return peek(); }

void add_front(Element val)
{
    if (is_full())
        error("  덱 포화 에러");
    data[front] = val;
    front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

Element delete_rear()
{
    int prev = rear;
    if (is_empty())
        error("  덱 공백 에러");
    rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    return data[prev];
}

Element get_rear()
{
    if (is_empty())
        error("  덱 공백 에러");
    return data[rear];
}

void print_queue(char msg[]) {
    int i, maxi = rear;
    if (front >= rear) maxi += MAX_QUEUE_SIZE;
    printf("%s[%2d]= ", msg, size());
    for (i = front + 1; i <= maxi; i++)
        printf("%2d ", data[i%MAX_QUEUE_SIZE]);
    printf("\n");
}

void print_deque(char msg[]) { print_queue(msg); }

int main()
{
    int i;
    
    init_deque();
    for (i = 1; i<10; i++) {
        if (i % 2) add_front(i);
        else add_rear(i);
    }
    print_deque("원형 덱 홀수-짝수  ");
    printf("\tdelete_front() --> %d\n", delete_front());
    printf("\tdelete_rear () --> %d\n", delete_rear());
    printf("\tdelete_front() --> %d\n", delete_front());
    print_deque("원형 덱 삭제-홀짝홀");
    
    return 0;
}
