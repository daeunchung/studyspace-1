// === [파일 이름] ===
// _02_stack.cpp		 
//===================

#include "stack.h"

void main() {
	Stack * stack = create_stack();

	push(stack, 10);
	push(stack, 20);
	push(stack, 30);
	Node * del = pop(stack);
	delete del;
	push(stack, 40);
	push(stack, 50);
	print_stack(stack);
}
