#include <stdio.h>
#include <windows.h>
#define NUM 0
#define PLUS 1
#define MINUS 2
#define MUL 3
#define DIV 4
#define LEFT 5
#define RIGHT 6
struct Token {
	int type;
	double num;
};
struct NodeStack {	// 리스트 (outstack)
	Token data;
	NodeStack * next;
};
struct Stack {		// 스택 ( opstack : operand stack )
	int count;
	NodeStack * top;
};
Stack* CreateStack();
void Push(Stack* stack, Token data);
NodeStack* Pop(Stack * stack);
Token * MakeToken(const char * data, int* size);
Token * ConvertToken(Token * token, int* size);
Stack* CreateStack() {
	Stack * stack = new Stack;
	memset(stack, 0, sizeof(Stack));
	return stack;
}
void Push(Stack* stack, Token data) {
	NodeStack * node = new NodeStack;
	node->data = data;
	node->next = stack->top;
	stack->top = node;
	stack->count += 1;
}
NodeStack* Pop(Stack * stack) {
	if (stack->count <= 0) return 0;
	NodeStack * del = stack->top;
	stack->top = del->next;
	stack->count -= 1;
	return del;
}
Token * MakeToken(const char * data, int* size) {
	int count = 0;
	char temp = data[count];
	while (temp != 0) {
		printf("%c", temp);
		count += 1;
		temp = data[count];
	}
	printf("\n");
	//printf("%d", count); printf("\n");
	Token * p = new Token[count];
	for (int i = 0; i < count; i++) {
		Token t;
		t.num = -1;
		if (data[i] == '+') {
			t.type = PLUS;
		}
		else if (data[i] == '-') {
			t.type = MINUS;
		}
		else if (data[i] == '*') {
			t.type = MUL;
		}
		else if (data[i] == '/') {
			t.type = DIV;
		}
		else if (data[i] == '(') {
			t.type = LEFT;
		}
		else if (data[i] == ')') {
			t.type = RIGHT;
		}
		else {
			t.num = atof(&data[i]);
			//printf("%.0lf", t.num);
			t.type = NUM;
		}
		p[i] = t;
	}
	*size = count;
	return p;
}
void PrintToken(Token t) {
	if (t.type == NUM) {
		printf("[%.1f]", t.num);
	}
	else if (t.type == PLUS) {
		printf("+");
	}
	else if (t.type == MINUS) {
		printf("-");
	}
	else if (t.type == MUL) {
		printf("*");
	}
	else if (t.type == DIV) {
		printf("/");
	}
	else if (t.type == LEFT) {
		printf("(");
	}
	else if (t.type == RIGHT) {
		printf(")");
	}
	//	printf("\n");
}
int InCheck(Token t) {
	int result = -1;
	if (t.type == PLUS) {
		result = 1;
	}
	else if (t.type == MINUS) {
		result = 1;
	}
	else if (t.type == MUL) {
		result = 2;
	}
	else if (t.type == DIV) {
		result = 2;
	}
	else if (t.type == LEFT) {
		result = 0;
	}
	else if (t.type == RIGHT) {
		result = 3;
	}
	return result;
}
int OutCheck(Token t) {
	int result = -1;
	if (t.type == PLUS) {
		result = 1;
	}
	else if (t.type == MINUS) {
		result = 1;
	}
	else if (t.type == MUL) {
		result = 2;
	}
	else if (t.type == DIV) {
		result = 2;
	}
	else if (t.type == LEFT) {
		result = 3;
	}
	else if (t.type == RIGHT) {
		result = 3;
	}
	return result;
}

Token * ConvertToken(Token * token, int* size) {
	Token * calcToken = new Token[*size];
	int calcCount = 0;
	Stack * stack = CreateStack();
	for (int i = 0; i < *size; i++) {
		Token t = token[i];
		if (t.type == NUM) {
			calcToken[calcCount++] = t;
			PrintToken(t);
		}
		else {
			if (t.type == RIGHT) {
				NodeStack * del = Pop(stack);
				Token data = del->data;
				while (data.type != LEFT) {
					calcToken[calcCount++] = data;
					PrintToken(data);
					del = Pop(stack);
					data = del->data;
				}
			}
			else {
				NodeStack * del = Pop(stack);
				if (del != 0) {
					Token data = del->data;

					if (InCheck(data) < OutCheck(t)) {

						Push(stack, data);
					}
					else {
						calcToken[calcCount++] = data;
						PrintToken(data);
					}
				}

				Push(stack, t);
			}
		}
	}
	while (stack->count > 0) {
		NodeStack * del = Pop(stack);
		Token data = del->data;
		calcToken[calcCount++] = data;
		PrintToken(data);
	}

	printf("\n");
	*size = calcCount;
	return calcToken;
}
void CalcToken(Token * token, int size) {	// 두번의 pop 과 그 결과값을 한번을 push
	Stack * stack = CreateStack();
	for (int i = 0; i < size; i++) {
		Token t = token[i];
		//PrintToken(t);
		if (t.type == NUM) {
			Push(stack, t);
		}
		else {
			NodeStack * del1 = Pop(stack);
			NodeStack * del2 = Pop(stack);
			double result = 0;
			if (t.type == PLUS) {
				result = del2->data.num + del1->data.num;
			}
			else if (t.type == MINUS) {
				result = del2->data.num - del1->data.num;
			}
			else if (t.type == MUL) {
				result = del2->data.num * del1->data.num;
			}
			else if (t.type == DIV) {
				result = del2->data.num / del1->data.num;
			}
			Token temp;
			temp.type = NUM;
			temp.num = result;
			Push(stack, temp);
		}
	}
	NodeStack * last = Pop(stack);
	printf("%.1lf", last->data.num);
	printf("\n");
}
void main() {
	char * data = "(1+2)/3-(3+4)";
	int size;
	Token * token = MakeToken(data, &size);
	token = ConvertToken(token, &size);
	CalcToken(token, size);
	printf("\n");
}
