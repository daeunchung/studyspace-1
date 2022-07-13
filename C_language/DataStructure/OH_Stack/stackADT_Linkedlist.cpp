/* Generic ADTs (Abstract Data Type)
1가지 타입의 데이터 만을 저장할 수 있음
- 데이터 타입이 달라지면 Item 타입 정의를 수정해야 함
- 서로 다른 타입의 데이터를 저장하는 2개의 스택을 만들 수 없음
void * 타입을 이용하여 generic 한 스택을 구현할 수 있으나 단점이 있음
객체지향 프로그래밍 언어
*/

#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

struct node {
	Item data;
	struct node * next;
};

struct stack_type {
	struct node * top;
};

static void terminate(const char * message) {
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}
Stack create()
{
	Stack s = (Stack)malloc(sizeof(struct stack_type));
	if (s == NULL)
		terminate("Error in create: stack could not be created.");
	s->top = NULL;
	return s;
}
void destroy(Stack s)
{
	make_empty(s);
	free(s);
}
void make_empty(Stack s)
{
	while (!is_empty(s))
		pop(s);
}
bool is_empty(Stack s)
{
	return s->top == NULL;
}
void push(Stack s, Item i)
{
	struct node *new_node = (node *)malloc(sizeof(struct node));
	if (new_node == NULL)
		terminate("Error in push: stack is full.");

	new_node->data = i;
	new_node->next = s->top;
	s->top = new_node;
}
Item pop(Stack s)
{
	struct node *old_top;
	Item i;

	if (is_empty(s))
		terminate("Error in pop: stack is empty.");

	old_top = s->top;
	i = old_top->data;
	s->top = old_top->next;
	free(old_top);
	return i;
}
Item peek(Stack s)
{
	if (is_empty(s))
		terminate("Error in peek: stack is empty.");
	return s->top->data;
}