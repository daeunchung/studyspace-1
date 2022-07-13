#include <stdio.h>
#include <Windows.h>
struct Node {
	int key;
	Node * left;
	Node * right;
};
struct Tree {
	int count;
	Node * root;
};
Tree * CreateTree();
void AddKey(Tree * tree, int key);
void PrintTree(Tree * tree);
void PrintNode(Node *node);
int FindKey(Tree * tree, int key);
void DeleteKey(Tree * tree, int key);
int KeyCheck(Tree* tree, int key);

Tree * CreateTree() {
	Tree * tree = new Tree();
	memset(tree, 0, sizeof(Tree));
	return tree;
}
void AddKey(Tree * tree, int key) {
	Node* node = new Node();
	node->key = key;
	node->left = 0;
	node->right = 0;
	if (tree->root == 0) {	// ��� 0�� ������ root�� �߰����ְ�
		tree->root = node;
		return;	// return���� �������� , �ؿ� ���� X
	}

	// ������ʹ� ��� 0�� �ƴϾ����� ����
	Node* cur = tree->root;
	while (1) {
		if (cur->key == key) {
			printf("�ߺ�Ű\n");
			return;
		}
		if (cur->key > key) {
			if (cur->left == 0) {
				cur->left = node;
				return;
			}
			cur = cur->left;
		}
		if (cur->key < key) {
			if (cur->right == 0) {
				cur->right = node;
				return;
			}
			cur = cur->right;
		}
	}
}
void PrintTree(Tree * tree) {
	PrintNode(tree->root);
}
void PrintNode(Node *node) {	// L Root R in-order traversal �ΰ��� ���� ��ȸ
	if (node == 0) return;
	PrintNode(node->left);
	printf("��� : %d\n", node->key);
	PrintNode(node->right);
}
int FindKey(Tree * tree, int key) {
	int result = -1;
	Node* cur = tree->root;
	while (1) {
		if (cur->key == key) {
			result = 1;
			return result; 
		}
		if (cur->key > key) {
			if (cur->left == 0)
				return result;
			cur = cur->left;
		}
		else {
			if (cur->right == 0)
				return result;
			cur = cur->right;
		}
	}
}

void DeleteKey(Tree * tree, int key) {
	if (KeyCheck(tree, key) == -1) {
		printf("���� ���� �����ϴ� %d\n", key); return;
	} // ���� Ű�� �� ��� ������

	// �ִ� Ű�̸� �Ʒ��� ����
	Node * par = 0;	// cur�� ��� �̵���Ű�� �̵��� cur�� �θ� �������� Ʈ��ŷ���ִ� par(parent)
	Node* cur = tree->root;
	while (cur->key != key) {
		if (cur->key < key) {
			par = cur; // cur �̵����� �θ� ǥ���صΰ�
			cur = cur->right;
		}else if (cur->key > key) {
			par = cur; // cur �̵����� �θ� ǥ���صΰ�
			cur = cur->left;
		}
	} 

	//while�� �������ϱ� cur->key == key ��� ��
	printf("���� �� : %d\n", cur->key);

	// �¿��� ��� X �쿡�� ��� X :  key �� ���� ��尡 Leaf Node �϶�
	if (cur->left == 0 && cur->right == 0) {
		if (cur == tree->root) tree->root = 0;
		else if (par->left == cur) par->left = 0;
		else if (par->right == cur) par->right= 0;
		delete cur;
	}
	// �°� �ְ� �찡 ������, �°� ���� �찡 �ִ��� (else if�̱⶧���� �Ѵ� �ִ°Ŵ� �̹� �ɷ����� �ٽ� �ȵ���)
	else if (cur->left == 0 || cur->right == 0) {
		if (cur == tree->root) {
			if (cur->left != 0) par->left = cur->left;
			if (cur->right!= 0) par->right = cur->right;
		}
		else if (par->left == cur) {
			if (cur->left != 0) par->left = cur->left;
			if (cur->right != 0) par->left = cur->right;
		}
		else if (par->right == cur) {
			if (cur->left != 0) par->right = cur->left;
			if (cur->right != 0) par->right = cur->right;
		}
		delete cur;
	}

	// �¿��� ��� O �쿡�� ��� O 
	else if (cur->left != 0 && cur->right != 0) {

		// ������ �ѹ��� �������� ���� ( �ֳ��ϸ� ���� ���߿� ���� ū���� cur �� �ٲ��ٲ��� ������)
		Node * par2 = cur;
		Node * cur2 = cur->left;

		// ��ü�� ��� ã�� ( ������ ���� ������ ���� ã���ش�)
		while (cur2->right != 0) {
			par2 = cur2;
			cur2 = cur2->right;
		}
		printf("��ü�� Ű : %d\n", cur2->key);

		if (cur2->left != 0) {
			if (par2->left == cur2) {
				par2->left = cur2->left;
				printf("1. par2 : %d\n", par2->key);
				printf("1. cur2 : %d\n", cur2->key);
			}
			else if (par2->right == cur2) {
				par2->right = cur2->left;
				printf("2. par2 : %d\n", par2->key);
				printf("2. cur2 : %d\n", cur2->key);
			}
		}
		else if (cur2->left == 0) {
			if (par2->left == cur2) {
				par2->left = 0;
				printf("3. par2 : %d\n", par2->key);
				printf("3. cur2 : %d\n", cur2->key);
			}
			else if (par2->right == cur2) {
				par2->right = 0;
				printf("4. par2 : %d\n", par2->key);
				printf("4. cur2 : %d\n", cur2->key);
			}
		}
		cur->key = cur2->key;
		cur = cur2;
		delete cur;
	}

}


int KeyCheck(Tree* tree, int key) {	
	// �Է��� Ű���� ���� ��尡 �ִ��� ������ Ȯ���ϴ� �Լ�
	int result = -1;
	Node* cur = tree->root;
	while (1) {
		if (cur->key == key) {
			result = 1;
			return result;
		}
		if (cur->key > key) {
			if (cur->left == 0)
			// �Է¹��� Ű���� ������ Ű������ ������ ������->left�� ���� ?? �� �ȵǴ°�����
				return result;
			cur = cur->left;

		}
		if (cur->key < key) {
			if (cur->right == 0)
				return result;
			cur = cur->right;
		}
	}
}

void main() {
	Tree * tree = CreateTree();

	AddKey(tree, 40);
	AddKey(tree, 20);
	AddKey(tree, 30);
	AddKey(tree, 10);
	AddKey(tree, 9);
	DeleteKey(tree, 20);
	PrintTree(tree);


}



