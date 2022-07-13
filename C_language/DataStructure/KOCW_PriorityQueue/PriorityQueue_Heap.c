#include <stdio.h>
#include <stdlib.h>

/* Priority Queue : ������ �켱������ ���� �۾� �����ٸ� ó��

�켱���� ť ADT �� �����ϴ� ����� : 
Insert DeleteMin DeleteMax ..���
���� �Ϲ� ť������ Enqueue Dequeue ����� ����������, �׸���� �߰�&ó���Ǵ� ������ �ٸ� �� �ִ�

Ascending Priority Queue 
���� Ű���� ���� �׸��ϼ��� ���� �켱������ ���� ( �׻� ���� ���� �׸��� �����ϴ� ) �������� �����̿���Ƽ ť
Descending Priority Queue
ū Ű���� ���� �׸��ϼ��� ���� �켱������ ���� ( �׻� ���� ū �׸��� �����ϴ� ) �������� �����̿���Ƽ ť
*/

/*
Binary Heap
�Ϲ������� Node�� �ƴ� Array �� �����. �������ʿ� X, �޸� ��뷮�� ����\
���̶� ��� Ư���� �Ӽ��� ���� Ʈ��
����� ���� �� �ڽ��� ����� ������ <= Ȥ�� <= �Ѵٴ� ���� ���� �Ӽ�
Ʈ���� ���� h>0 �϶� ��� ���� ������ hȤ�� h-1������ �־�� �Ѵ� (��������Ʈ�� �̾�� �Ѵ�)

���� �ڽ��� 2��¥���� binary heap �� ���� ���ٰ� ����ȴ�
�迭�� ����ؼ� ��Ÿ����. ������X
*/
struct Heap {
	int * array;
	int count;		// �� ���� �׸� ����
	int capacity;	// ���� �뷮
	int heap_type;	// �ּ� ������ �ִ� ������
};


// �ð����⵵ O(1) : loop �� ������
struct Heap* CreateHeap(int capacity, int heap_type) {
	struct Heap* h = (struct Heap*)malloc(sizeof(struct Heap));
	if (h == NULL) {
		printf("Memory Error");
		return;
	}
	h->heap_type = heap_type;
	h->count = 0;
	h->capacity = capacity;
	h->array = (int*)malloc(sizeof(int) * h->capacity);
	if (h->array == NULL) {
		printf("Memory Error");
		return;
	}
	return h;
}

// ����� �θ�         // �ð����⵵ O(n)
int Parent(struct Heap* h, int i) {
	if (i <= 0 || i >= h->count)
		return -1;

	return (i - 1) / 2;
}

// ����� �ڽĵ�						// �Ѵ� �ð����⵵ O(1)
int LeftChild(struct Heap* h, int i) {
	int left = 2 * i + 1;
	if (left >= h->count) return -1;
	return left;
}
int RightChild(struct Heap* h, int i) {
	int right = 2 * i + 2;
	if (right >= h->count) return -1;
	return right;
}

// �ִ� �׸� ���ϱ�					// �ð����⵵ O(1)
// �ִ� ������ �ִ� �׸��� �׻� ��Ʈ�� �����Ƿ� 
int GetMaximum(struct Heap * h) {
	if (h->count == 0)
		return -1;
	return h->array[0];
}

/*
�׸��� ������ ����� ( Ư�� ��尡 heap Ư���� �����ϵ��� �ϱ� )
���� �׸��� ���� �߰��ϰ� ���� �� �̻� �� �Ӽ��� �������� ���� �� �ִ�.
�� ��쿡 �� ���� ��ġ�� �����Ͽ� �ٽ� ������ ������ �� �ʿ䰡 �ִ�.
�� ������ ������ ����� Heapifying �̶�� �Ѵ�.
Max Heap �� ��� : �ִ� ������ �׸��� ������ ������� 
				  �� �ڽ� ������ �ִ밪�� ã�� ���� �׸�� �ٲ�ġ�⸦ �� �� 
				  �� ������ ��� ��尡 �� �Ӽ��� ������ ������ ����ؾ� �Ѵ�.
*/

// Heapifying : PercolateDown ( i��ġ�� �׸��� ������ ����� )
// �ð����⵵  :	O(log n) �������� Ʈ���̹Ƿ� �־��� ��쿡 ��Ʈ���� �����ؼ� �������� �������� ���� ���� Ʈ���� ���̿� ����
// �������⵵  : O(1)
void PercolateDown(struct Heap* h, int i) {
	int l, r, max, temp;
	l = LeftChild(h, i);
	r = RightChild(h, i);

	if (l != -1 && h->array[l] > h->array[i])	max = l;
	else max = i;

	if (r != -1 && h->array[r] > h->array[max])	max = r;
	if (max != i) {
		// h->array[i]�� h->array[max] �ٲ�ġ���ϱ�
		temp = h->array[i];
		h->array[i] = h->array[max];
		h->array[max] = temp;
		PercolateDown(h, max);
	}
}

/*
�׸� �����ϱ� : ������ �׸�����Ϸ��� ��Ʈ���� �׸��� �����ϱ⸸ �ϸ�ȴ�
	�̰��� ǥ�� ������ �����Ǵ� ������ ���� (�ִ� �׸�)
	��Ʈ �׸��� ������ ��, ��(Ʈ��)�� ������ �׸��� �����ϰ� �� ������ �׸��� �����Ѵ�.
	�׷��� ������ �׸��� ��ü�ϰ� ���� Ʈ���� �� �Ӽ��� ������Ű�� ���� ���� �ִ�
	�ٽ� ������ ������� PercolateDown �Լ��� ȣ���ؾ���
		- ù��° �׸��� � ������ �����Ѵ�
		- ������ �׸��� ù��° �׸��� ��ġ�� �����Ѵ�
		- ù��° �׸񿡼� PercolateDown �� ȣ���Ѵ�.

�ð����⵵ : O(log n)	// �귯�����⸦ ���
*/

int DeleteMax(struct Heap * h) {
	int data;
	if (h->count == 0)
		return -1;
	data = h->array[0];
	h->array[0] = h->array[h->count-1];
	h->count--;	// �� ũ�⸦ ���δ�
	PercolateDown(h, 0);
	return data;
}



/*
�׸� �����ϱ� : ��ũ��ø���, �� �׸��� ��(Ʈ��)���� ��ġ��Ų��, 
			   �� �׸� ���� �ؿ��� ��(��Ʈ)�� �����θ���� ����

			   ���� �Ʒ��ʿ� ���Ե� ��带 ���ڸ�(����) ���� �÷��ֱ����� Ȧ���ø��� PercolateUp ���
�ð����⵵ : O(log n)	������ ����� �Լ��� �Ȱ���
*/
int Insert(struct Heap * h, int data) {
	int i;
	if (h->count == h->capacity)					// �뷮�� �����ϸ� resize
		ResizeHeap(h);
	h->count++;										// �� �׸��� �����ϱ� ���� ���� ũ�⸦ ������Ų��.
	i = h->count - 1;
	while (i > 0 && data > h->array[(i - 1)/2]) {	// ��Ʈ���� ���ų�, �θ�array[(i-1)/2] ���� ������ ����
		h->array[i] = h->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	h->array[i] = data; 
}

void ResizeHeap(struct Heap * h) {
	int* array_old = h->array;
	h->array = (int*)malloc(sizeof(int) * h->capacity * 2);
					// realloc ���ָ� �ؿ� �ڵ尡 ���پȿ� ��� ó����
	if (h->array == NULL) {
		printf("Memory Error");
		return;
	}
	for (int i = 0; i < h->capacity; i++) 
		h->array[i] = array_old[i];

	h->capacity *= 2;
	free(array_old);
}

void DestroyHeap(struct Heap* h) {
	if (h == NULL)
		return;
	free(h->array);
	free(h);
	h = NULL;		// �ǹ̾��� �ڵ� ���⿡�� ���� �ٱ��ʿ��� NULL�� ����������
}


/*SORT �� ?
	ū ���� �Ǵ� ���� ������� �����ϴ°�  
	���� ��û�ϰ� O(n����)  for(int i = 0; i<count; i++){for(int j = i; j<count; j++){
							ex) ����for�����ݾ�... �̰� ���� ������ ���Ĺ��ΰŰ�
HeapSort �� �̿��� ������?
	PercolateUp �� �ð����⵵ O(log n) �̴ϱ� �̰��� n�� �������ָ�
	O(nlog n) �̶�� ����� �Ǹ��� �ð����⵵�� ������ �����ϴٴ� ��
*/

/*
���ĵ��� ���� �迭�� ������ �����

���� ����� ������ ��� �ϳ��� n���� �׸��� �Է� �޾� �̵��� �� ���� ��ġ��Ű�� ���̴�.
�̴� n���� �������� ���Կ������� ����� �� ������ �־��� ��쿡 O(nlog n)�� �ɸ���.
������ ���� ���꿡 O(log n)�� �ʿ��ϱ� �����̴�.

�������� �׻� �� �Ӽ��� ���� -> PercolateDown ����� �ʿ� X
�����׸���� �׻� �������� ��ġ�ϹǷ� �־��� �迭�� ������ ������� ������ �ƴ� ���鸸 ������ ����� �ȴ�.
���� ������ �ƴ� ���� ó�� ��带 ã�µ� ��������.
���� ������ �׸��� h->count-1 �� ��ġ�ϹǷ� , 
������ �ƴ� ���� ó�� ���� �� ������ �׸��� �θ� ��带 ã�Ƽ� �߰��� �� �ִ�.
*/


/* �迭�� ������ �����
	 �ð����⵵ : ���� ����� �������ð��� ��(bound)�� ��� ����� ���� ���� ����Ͽ� �� �� �ִ�.
	 ���̰� h�� ���� ���� Ʈ������ n - 2(h+1��) - 1 ���� ��尡 �ְ�, 
	 �� ������ ������ ���� n-h-1 �뷫 n-logn-1 �̴� (�³�Ʋ�����ٽ��ѹ�üũ�غ���)

	 ��, ���� ���� ���� ������ PercolateDown �Լ��� �����ؼ� ���� �ð� O(n) �� �̷������.

*/
void BuildHeap(struct Heap * h, int A[], int n) {
	if (h == NULL)
		return;		// ���� ���̸� CreateHeap�ϸ� ���ٵ�..  �ƹ��͵� ���ϰ� return �϶�°� ���� �� �Լ� �ۿ��� ���� ���� ������ �����µ�
	while (n > h->capacity)		// ���� ���� n���� ���� �뷮�� ������ A[] �� ���� �� ������ ���� �뷮*2 �ݺ����� �ø���
		ResizeHeap(h);
	for (int i = 0; i < n; i++) {	// ���� heap�� �ƴ� ���°� �ϴ� �迭�� ������ copy���ֱ�
		h->array[i] = A[i];
	}
	h->count = n;					// count�� n���� ����
	for (int i = (n - 1) / 2; i >= 0; i--) {	// i = (n-1)/2 �϶��� ���帶��������� �θ� ( = �ڿ������͵����� ó������ leaf��尡 �ƴ� ��� ) ����   ~   i = 0 (root���) ����
		PercolateDown(h, i);
	}
}







/*
�� ADT �� �ַ� ���Ŀ� �̿��Ѵ�. (�� ����)
�� ���� �˰����� ��� �׸��� (���ĵ��� ���� �迭�κ���) ������ ���� ���� ��Ʈ�κ��� ���� �� ������ �׸���� ����
�� ������ ���ĵ� �迭�� ���� ��ҿ��� ������ �̷���� �� �ִ� ( ��, output �迭 ���� �̿�X)
�׺��� �����ϴ� ��� ù ���� �׸� (���� ū �׸�) �� ������ �׸��� ��ü�ϰ� �� ũ��(�迭ũ��)�� ����
�׷� ���� ù��° �׸��� �������� ������ �����. �� ������ ���� �׸��� �Ѱ��϶����� �ݺ�

�ð����⵵ : �׸��� �����κ��� ������ ������ ���� ���ĵȴ�(�ִ��׸��� ������ ��Ʈ���� �ֱ⶧��)
			���� �˰����� �ð� ���⵵�� O(log n)�̹Ƿ�, �� ���� �׸��� ���� n�� �� 
			�� ���� �˰����� �ð� ���⵵�� O(nlog n) �̴�
*/
void HeapSort(int A[], int n) {
	struct Heap* h = CreateHeap(n);	// O(1)
	int old_size, i, temp;
	BuildHeap(h, A, n); // O(n)
	old_size = h->count;
	for (i = n - 1; i > 0; i--) {// for�� n���ݺ��̴ϱ� ���ϱ� n
		// h->array[0] �� ���� ū �׸��̴�.
		temp = h->array[0];
		h->array[0] = h->array[h->count - 1];
		h->array[h->count - 1] = temp;
		h->count--;
		PercolateDown(h, 0); // O(log n)
	}						 // => O(nlog n)
	h->count = old_size;
}
// ���� : O(1) + O(n) + O(nlog n) => O(nlog n)

















/*				�������� HeapSort time-complexity : O(nlog n)

Sort�� ����� ���������� �ִµ� �� �߿��� O(n����) �ð����⵵ ������ sort �� ������ 
HeapSort�� O(nlog n) �ð� ���⵵ �����⿡ �ſ� �Ǹ��ϴٰ� �� �� �ְ� ( ���� ���̰� ����� ũ��)

Priority Queue : ���� ������ �����°� �ƴϰ� Ư�� �켱���� ������ ���� ������ ť

�׷��� Priority Queue�� �����ϱ� ���ؼ� Heap�̶�� �ڷᱸ���� ��� ��
�� Heap �� Array(�迭)�� ������ �� �ֱ⿡ ����� ���ߴٴ� ��

�׷��ٰ� ���� Sorting ���� ����� �� HeapSorting �� ���⼭ ����� �̸����� *^^*

*/