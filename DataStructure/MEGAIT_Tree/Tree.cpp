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
Tree * CreateTree(Tree * tree);
void AddKey(Tree * tree, int key);
void PrintTree(Tree * tree);
void PrintNode(Node *node);
int FindKey(Tree * tree, int key);
void DeleteKey(Tree * tree, int key);
int KeyCheck(Tree* tree, int key);

Tree * CreateTree(Tree * tree) {
	Tree * tree = new Tree();
	memset(tree, 0, sizeof(Tree));
	return tree;
}
void AddKey(Tree * tree, int key) {
	Node* node = new Node();
	node->key = key;
	node->left = 0;
	node->right = 0;
	if (tree->root == 0) {	// 노드 0개 였으면 root로 추가해주고
		tree->root = node;
		return;	// return으로 빠져나감 , 밑에 수행 X
	}

	// 여기부터는 노드 0개 아니었으면 수행
	Node* cur = tree->root;
	while (1) {
		if (cur->key == key) {
			printf("중복키\n");
			return;
		}
		if (cur->key > key) {
			if (cur->left == 0) {
				cur->left = node;
				return;
			}
			cur = cur->left;
		}
		if (cur->key > key) {
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
void PrintNode(Node *node) {	// L Root R in-order traversal 인가봄 중위 순회
	if (node == 0) return;
	PrintNode(node->left);
	printf("출력 : %d\n", node->key);
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
		printf("삭제 값이 없습니다 %d\n", key); return;
	} // 없는 키를 뭐 어떻게 삭제해

	// 있는 키이면 아래를 수행
	Node * par = 0;	// cur를 계속 이동시키고 이동된 cur의 부모가 누구인지 트래킹해주는 par(parent)
	Node* cur = tree->root;
	while (cur->key != key) {
		if (cur->key < key) {
			par = cur; // cur 이동전에 부모 표시해두고
			cur = cur->right;
		}else if (cur->key > key) {
			par = cur; // cur 이동전에 부모 표시해두고
			cur = cur->left;
		}
	} 
	//while문 나왔으니까 cur->key == key 라는 뜻
	printf("삭제 값 : %d\n", cur->key);

	// 좌에도 노드 X 우에도 노드 X :  key 값 가진 노드가 Leaf Node 일때
	if (cur->left == 0 && cur->right == 0) {

	}
	// 좌가 있고 우가 없던지, 좌가 없고 우가 있던지 (else if이기때문에 둘다 있는거는 이미 걸러져서 다시 안돈다)
	else if (cur->left == 0 || cur->right == 0) {
	}

	// 좌에도 노드 O 우에도 노드 O 
	else if (cur->left != 0 && cur->right != 0) {



}


int KeyCheck(Tree* tree, int key) {	
	// 입력한 키값을 가진 노드가 있는지 없는지 확인하는 함수
	int result = -1;
	Node* cur = tree->root;
	while (1) {
		if (cur->key == key) {
			result = 1;
			return result;
		}
		if (cur->key > key) {
			if (cur->left == 0)
			// 입력받은 키값이 현재노드 키값보다 작은데 현재노드->left가 없다 ?? 말 안되는거지뭐
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



