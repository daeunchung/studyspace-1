/*
BinarySearchTree �����˻�Ʈ��
������ �� �������� Ʈ�� �����鿡���� ������ ����� �����Ϳ��� ��� ���ѵ� ������ �ʾҴ�.
�� ��� � �׸��� �˻��Ϸ���, ���� ����Ʈ���� ������ ���� Ʈ���� ��� �˻��ؾ��ϱ� ������ �˻� ������ �־��� ���ִ� ���⵵ O(n)�� ���¿���.
�̹��� ��� Ʈ���� �� �뵵�� �˻��� BST �̰�, � ��尡 ���� �� �ִ� �������� ������ ���Ͽ�
������ �� ���̹Ƿ�, �˻� ������ �־��� ��� ���⵵�� 
O(logn)�� �ȴ�. -> �������� �ܾ�ã�� ( �� �������� �������� /2, /2, /2 ... logn )


���� BST �� �Ƿ��� skewed Ʈ���� ���� �ʵ��� ���� �����Ͱ� ������� ������ �ڵ��ؾ��Ѵ�.
( ��, skew Ʈ���� BST�� ���� ������ �׷��� ǥ���Ǵ°�. skew Ʈ���� �Ǵ°��� ���ؾ��� )

��Ʈ �����Ͱ� �׻� ���� ���� Ʈ�� �����Ϳ� ������ ���� Ʈ�� ������ ���̿� �ֱ� ������ 
���� Ž�� (InOrder) �� �����ϸ� ���ĵ� ����Ʈ�� ���������.

���� �˻� Ʈ���� ���� ������ Ǯ �� ��κ��� ���, ���� ���� Ʈ���� ���� ó���ϰ� 
��Ʈ �����͸� ó���� ���� �͸��� ���� Ʈ���� ó���Ѵ�.

� �׸��� �˻��� �� ���� ���� Ʈ���� �����Ͱ� �˻��ϴ� �׸񺸴� ������ ���� ���� Ʈ�� �˻��� ������ �� �ִ�.
	������ ����Ʈ�������� ����ϴ�
	�� ������ ���� �˻� Ʈ���� ���� ���� Ʈ������ �˻��� �ɸ��� �ð��� ����
	�ٸ� ���� �ϸ�, ���� �˻� Ʈ���� �׸��� �˻��� �� ���� ���� Ʈ���� ������ ����Ʈ���� �Ѱ��� 
*/
#include <stdio.h>
#include <stdlib.h>

struct BinarySearchTreeNode {
	int data;
	struct BinarySearchTreeNode* left;
	struct BinarySearchTreeNode* right;

};

// ����� ���
// �ð����⵵ : �־��� ���(BST�� ���Ʈ���϶�) O(n)     
// �������⵵ : ������� O(n)
//				�Լ� �ѹ� call �Ҷ����� stack�� ���̰� ���̰� ���̰� n�� call �ϸ� n �� ���̰�
struct BinarySearchTreeNode* Find(struct BinarySearchTreeNode* root, int data) {
	if (root == NULL) {
		return NULL;
	}
	if (data < root->data) {
		return Find(root->left, data);
	}
	else if (data > root->data) {
		return Find(root->right, data);
	}

	return root;
}


// ������� ���
// �ð����⵵ O(n)
// �������⵵ O(1) : parameter 2�� + while�� ���µ� �޸𸮴� ���� �ʿ� X
struct BinarySearchTreeNode* Find(struct BinarySearchTreeNode* root, int data) {
	if (root == NULL) {
		return NULL;
	}
	while (root) {
		if (data == root->data)
			return root;
		else if (data > root->data)
			root = root->right;
		else if (data < root->data)
			root = root->left;
	}

	return NULL;
}



// ���� �˻� Ʈ������ �ּ� �׸� ã��
// BST ���� �ּ� �׸��� ���� �ڽ��� ���� ���� ���� ���� ����̴�
// ����� ver
// �ð����⵵ : �־��� ���(BST�� ���� ���Ʈ���϶�) O(n)     
// �������⵵ : ����� ������ ���� O(n)
struct BinarySearchTreeNode* FindMin(struct BinarySearchTreeNode* root) {
	if (root == NULL)
		return NULL;
	else if (root->left == NULL)
		return root;
	else
		return FindMin(root->left);
}


// ������� Iteration ver
// �ð����⵵ :  O(n)     // Ʈ���� ���̸�ŭ while �� ������
// �������⵵ :  O(1)	 // FindMin �Լ� �ѹ� �ҷ� 
struct BinarySearchTreeNode* FindMin(struct BinarySearchTreeNode* root) {
	if (root == NULL)
		return NULL;
	while (root->left != NULL) {	// Ʈ���� ���̸�ŭ while �� ������
		root = root->left;
	}
	return root;
}


// ���� �˻� Ʈ������ �ִ� �׸� ã��
// BST ���� �ּ� �׸��� ������ �ڽ��� ���� ���� ���� ������ ����̴�
// ����� ver
// �ð����⵵ : �־��� ���(BST�� ������ ���Ʈ���϶�) O(n)     
// �������⵵ : ����� ������ ���� O(n)    (���ÿ� �ѹ���)
struct BinarySearchTreeNode* FindMax(struct BinarySearchTreeNode* root) {
	if (root == NULL)
		return NULL;
	else if (root->right == NULL)
		return root;
	else
		return FindMax(root->right);
}

// ������� Iteration ver
// �ð����⵵ :  O(n)     // Ʈ���� ���̸�ŭ while �� ������
// �������⵵ :  O(1)	 // FindMax �Լ� �ѹ� �ҷ� (���ÿ� �ѹ���)
struct BinarySearchTreeNode* FindMax(struct BinarySearchTreeNode* root) {
	if (root == NULL)
		return NULL;
	while (root->right != NULL) {	// Ʈ���� ���̸�ŭ while �� ������
		root = root->right;
	}
	return root;
}

/*
���� �˻� Ʈ���� �����͸� �����Ϸ��� ���� �� �׸��� ��ġ�� ã�ƾ� �Ѵ�.
	��ġ�� ã�� ���� �����Ͱ� �̹� �����Ѵٸ� �����ϰ� ������ �ȴ�
	�������� �ʴ� new�������̸� Ž���� ����� ������ ��ġ�� �����͸� �߰��Ѵ�.
*/

// ���� �˻�Ʈ���� �׸� �����ϱ�	
// �ð����⵵ :  O(n)   
// �������⵵ :  ����� ������ ���� O(n)	
struct BinarySearchTreeNode* Insert(struct BinarySearchTreeNode* root, int data) {
	if (root == NULL) {
		root = (struct BinarySearchTreeNode*)malloc(sizeof(struct BinarySearchTreeNode));
		if (root == NULL) {
			printf("Memory Error");
			return;
		}
		else {
			root->data = data;
			root->left = NULL;
			root->right = NULL;
		}
	}
	else {
		if (data < root->data)	root->left = Insert(root->left, data);
		else if (data > root->data)	root->right = Insert(root->right, data);
	}
	return root;
}


/* ���� �˻�Ʈ���� �׸� �����ϱ�	( ������ )
	�� ���� ���� ���� �����ϱ� ���ϴ� �׸��� ��ġ�� ã�ƾ� �Ѵ�
	������ ��� ã������ 
		(1) ������ �׸��� ��������� : NULL�� �θ��忡�� ����
		(2) ������ �׸��� �� ���� �ڽ� ��带 �����ٸ� : ���� ����� �ڽ��� �θ��忡�� ������
		(3) ������ �׸��� �� ���� �ڽ� ��带 �����ٸ� : 
		�Ϲ����� ������ �� ����� Ű���� ���� ���� Ʈ���� �ִ� �׸�� �ٲٰ� 
		��������� ���� �� ������ ������ ��带 ����
		���� ���� Ʈ���� �ִ� �׸��� ������ �ڽ��� ���� �� �����Ƿ� �ι�° ������ ����
		���� : ������ ���� Ʈ���� �ּ� ������ ��ü�� �� �ִ�.

	�ð����⵵ O(n)
	�������⵵ : �������������� O(n)		�ݺ������������ O(1)
*/
struct BinarySearchTreeNode* Delete(struct BinarySearchTreeNode* root, int data) {
	struct BinarySearchTreeNode * temp;
	if (root == NULL)			printf("Element not there in tree");
	else if (data < root->data)	root->left = Delete(root->left, data);
	else if (data > root->data)	root->right = Delete(root->right, data);

	else {	// �׸��� ã�Ҵ�. ( ���⼭���ʹ� ã���׸��� ��ü�ϴ� ��� : �� ���� �ڵ���� �� ���� ��ã��������)
		if (root->left && root->right) {	// �Ѵ� 1�̸� �ڽĳ�� �¿��� �� �����ϸ� �̶�� �Ҹ�
			/* ���� ���� Ʈ���� �ִ� ���� ��ü�Ѵ� */
			temp = FindMax(root->left);
			root->data = temp->data;
			root->left = Delete(root->left, root->data);	// ���� �����͸� �ٽ� ��ȯ�ؾ��� 
		}
		else {
			/* �ڽ��� �ϳ� �Ǵ� ���� ���*/
			temp = root;
			if (root->left == NULL) root = root->right;
			if (root->right == NULL) root = root->left;
			free(temp);
		}
	}
	return root;
}