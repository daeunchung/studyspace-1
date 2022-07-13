#include <stdio.h>

// 안돌아가 이거 개빡쳐

// full 이면 더 안차야하는데 계속 들어감 ㅡㅡ
/*
Circular Queue 는 무슨 다른 하나의 독특한 Queue 가 아니라 우리가 큐를 구현하는 방법론 이라고 할수 있다.

enqueue::
rear++;
rear = rear % QUEUE_SIZE;

dequeue::
front++;
front = front % QUEUE_SIZE;

IsQueueEmpty
if(front == rear)	// 맨 처음에 front 와 rear 가 같은곳 가리키고있지? -> ㅇㅇ 따라서 같은곳 가리키면 비었다고 판단
it is empty

IsQueueFull ( front공간 하나를 비움으로써 그공간은못쓰는대신 queue 가 꽉찼다는걸 알려주는 식) 
// rear 가 front 바로 한칸 뒤에 있을 때 -> Full
if(front == (rear+1) % QUEUE_SIZE)
it is full

circular queue 에서는 일부러 front안에 내용물을 넣지 않고 한칸을 비움으로써 rear 가 front 바로 한칸 뒤에 있음을 
컴터가 full 로 인식 할 수 있도록 한다.
queue 가 진짜 원형이 꽉 차면 front 와 rear가 같은 곳을 가리켜서 구분할 수 없기때문


*/



// Static Array 로 구현하는 Circular Queue


// 5라고 직접쓰기보다는 macro const 지정해서 사용
#define QUEUE_SIZE 5
// queuesize 가 5면 실제 들어갈 수 있는 데이터 값은 4개 인것임 (full 일때 front가 비어있어야 하니까)

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
		rear = rear % QUEUE_SIZE;		// rap around 가 발생할 수 있기 때문에 모듈러 처리

		queue[rear] = v;

		printf("enqueue is successful, %d \n", v);
	}
}

//dequeue
int dequeue() {

	// check if the queue is empty
	if (isQueueEmpty == 1) {
		return -999;	// 큐가 비어있다는 약속값
	}
	else {
		front = front + 1;
		front = front % QUEUE_SIZE;

		return queue[front];
	}
}



// return값으로 아무것도 넘기지 않는 main 함수는 체킹 중 문제가 발생할 수 있기 때문에 웬만하면 return 0;  넘기고 int main() 으로 쓰는걸 권장
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

// 이거 안돌아감 