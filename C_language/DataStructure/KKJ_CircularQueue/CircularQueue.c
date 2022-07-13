#include <stdio.h>

// �ȵ��ư� �̰� ������

// full �̸� �� �������ϴµ� ��� �� �Ѥ�
/*
Circular Queue �� ���� �ٸ� �ϳ��� ��Ư�� Queue �� �ƴ϶� �츮�� ť�� �����ϴ� ����� �̶�� �Ҽ� �ִ�.

enqueue::
rear++;
rear = rear % QUEUE_SIZE;

dequeue::
front++;
front = front % QUEUE_SIZE;

IsQueueEmpty
if(front == rear)	// �� ó���� front �� rear �� ������ ����Ű������? -> ���� ���� ������ ����Ű�� ����ٰ� �Ǵ�
it is empty

IsQueueFull ( front���� �ϳ��� ������ν� �װ����������´�� queue �� ��á�ٴ°� �˷��ִ� ��) 
// rear �� front �ٷ� ��ĭ �ڿ� ���� �� -> Full
if(front == (rear+1) % QUEUE_SIZE)
it is full

circular queue ������ �Ϻη� front�ȿ� ���빰�� ���� �ʰ� ��ĭ�� ������ν� rear �� front �ٷ� ��ĭ �ڿ� ������ 
���Ͱ� full �� �ν� �� �� �ֵ��� �Ѵ�.
queue �� ��¥ ������ �� ���� front �� rear�� ���� ���� �����Ѽ� ������ �� ���⶧��


*/



// Static Array �� �����ϴ� Circular Queue


// 5��� �������⺸�ٴ� macro const �����ؼ� ���
#define QUEUE_SIZE 5
// queuesize �� 5�� ���� �� �� �ִ� ������ ���� 4�� �ΰ��� (full �϶� front�� ����־�� �ϴϱ�)

int queue[QUEUE_SIZE];
int front = 0, rear = 0;

// is queue empty
// return 1 if empty
//		  0 if not
int isQueueEmpty() {
	return (front == rear) ? 1 : 0;
	/*if(front == rear){return 1;} else{return 0;}*/
}

// is queue full
// return 1 if full
//		  0 if not
int isQueueFull() {
	return ((rear + 1) % QUEUE_SIZE == front) ? 1 : 0;
	/*if ((rear + 1) % QUEUE_SIZE == front) {return 1;} else{return 0;}*/
}

//enqueue
void  enqueue(int v) {

	// check if the queue is full
	if (isQueueFull == 1) {
		printf("queue is full \n");
		return;
	}
	else {
		rear = rear + 1;
		rear = rear % QUEUE_SIZE;		// rap around �� �߻��� �� �ֱ� ������ ��ⷯ ó��

		queue[rear] = v;

		printf("enqueue is successful, %d \n", v);
	}
}

//dequeue
int dequeue() {

	// check if the queue is empty
	if (isQueueEmpty == 1) {
		return -999;	// ť�� ����ִٴ� ��Ӱ�
	}
	else {
		front = front + 1;
		front = front % QUEUE_SIZE;

		return queue[front];
	}
}



// return������ �ƹ��͵� �ѱ��� �ʴ� main �Լ��� üŷ �� ������ �߻��� �� �ֱ� ������ �����ϸ� return 0;  �ѱ�� int main() ���� ���°� ����
int main(void) {

	enqueue(1);
	enqueue(2);
	enqueue(3);

	printf("dequeue %d\n", dequeue());
	printf("dequeue %d\n", dequeue());
	printf("dequeue %d\n", dequeue());
	printf("dequeue %d\n", dequeue());
	printf("dequeue %d\n", dequeue());
	printf("dequeue %d\n", dequeue());

	return 0;
}

// �̰� �ȵ��ư� 