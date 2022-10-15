#include "stack.h"
#include "iostream"
using namespace std;

int main() {
	Stack<int> stack_int;
	if (stack_int.empty()) {
		cout <<"Initialized stack empty." << endl;
	}
	cout<<"Add num 0 to 4 to stack..." << endl;
	for (int i=0; i<5; i++) {
		stack_int.push(i);
	}
	cout<<"Current top of stack:" << stack_int.top() << endl;
	cout << "Pop the top...";
	stack_int.pop();
	cout<<"Current size of the stack:" << stack_int.size() << endl;
	cout << "Current top:" << stack_int.top() <<endl;

	return 0;
}