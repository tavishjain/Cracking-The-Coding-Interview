#include <iostream>
using namespace std;

#define topval 4
#define capval 2

struct Node{
	int data;
	Node* next;
	Node(int x){
		data = x;
		next = NULL;
	}
};

struct Stack{
	Node* top;
	int cap = 0;
	void push(int x){
		cap++;
		Node* node = new Node(x);
		if(top == NULL){
			top = node;
		}else{
			node->next = top;
			top = node;
		}
	}
	void pop(){
		if(top == NULL) cout << "Stack is empty, cannot pop more items !!" << endl;
		else{
			cap--;
			Node* temp = top;
			top = top->next;
			free(temp);
		}
	}
};

struct SetOfStacks{
	Stack s[10]; //total to sets of stacks
	int top = 0; //stack number for the current top
	
	int getTop(){
		if(top == topval) return s[top-1].top->data;
		if(s[top].cap == 0){
			top--;
			cout << "Reducing top !!" << endl;
		}
		return s[top].top->data;
	}
	void push(int x){
		if(top == topval){
			cout << "No more stacks remaining !!!" << endl;
		}else{
			if(s[top].cap == capval){
				cout << "Increasing top !!" << endl;
				top++;
			}
			if(top != topval){
				cout << "Inserting : " << x << endl;
				s[top].push(x);
			}else {
				cout << "No more stacks remaining !!!" << endl;
			}
		}
	}
	void pop(){
		if(top == topval) top--;
		if(s[top].cap == 0){
			top--;
			cout << "Reducing top !!" << endl;
		}
		if(top == -1){
			cout << "All stacks are empty !!!" << endl;
		}else{
			cout << "Popped : " << s[top].top->data << endl;
			s[top].pop();
		}
	}
};

int main() {
	SetOfStacks s;
	s.push(4);
	s.push(7);
	s.push(6);
	s.push(10);
	s.push(9);
	s.push(2);
	s.push(5);
	cout << "Top is : " << s.getTop() << endl;
	s.pop();
	cout << "Top is : " << s.getTop() << endl;
	s.pop();
	cout << "Top is : " << s.getTop() << endl;

	return 0;
}
