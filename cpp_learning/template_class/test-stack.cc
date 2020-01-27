#include "stack.h"
#include <iostream>

int main() {

	Stack<int> stack;
	for (int i=0; i<100; i++){
		stack.push(i+1);
	}

	while (!stack.isEmpty()) {
		std::cout << "pop num: " << stack.pop() << std::endl;
	}
	return 0;
}

