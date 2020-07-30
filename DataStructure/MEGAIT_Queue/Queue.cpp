#include <stdio.h>
#include <windows.h>
struct Node {
	int data;
	Node * next;
};
struct Queue {
	int count;
	Node * front;
	Node * rear;
};
Queue * create_queue();
Queue * create_queue() {
	Queue * queue = new Queue;
	memset(queue, 0, sizeof(Queue));
	return queue;
}
void inqueue(Queue* queue, int data) {
	Node * node = new Node;
	node->data = data;
	node->next = NULL;
	if (queue->count == 0) {
		queue->front = node;
		queue->rear = node;
	}
	else if (queue->count > 0) {
		queue->rear->next = node;
		queue->rear = node;
	}
	queue->count += 1;
}
Node * dequeue(Queue* queue) {
	if (queue->count == 0)return NULL;
	Node * del = queue->front;
	queue->front = queue->front->next;
	if (queue->front == NULL) { // 마지막꺼 삭제 
		queue->rear = NULL; // 리어삭제 
	}
	queue->count -= 1;
	return del;
}
void main() {
	Queue * queue = create_queue();
	inqueue(queue, 10);
	inqueue(queue, 20);
	inqueue(queue, 30);
	Node * del = dequeue(queue);
	printf("%d\n", del->data);
	del = dequeue(queue);
	printf("%d\n", del->data);
	del = dequeue(queue);
	printf("%d\n", del->data);
	del = dequeue(queue);
}
