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
	void push(int x){
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
			Node* temp = top;
			top = top->next;
			free(temp);
		}
	}
};

struct MyQueue{
	Stack s;
	void enqueue(int x){
		if(s.top == NULL){
			s.push(x);
		}else{
			Stack temp;
			while(s.top){
				int x = s.top->data;
				s.pop();
				temp.push(x);
			}
			temp.push(x);
			while(temp.top){
				int x = temp.top->data;
				temp.pop();
				s.push(x);
			}
		}
	}
	void dequeue(){
		if(s.top == NULL) cout << "Queue is empty";
		s.pop();
	}
	int getTop(){
		if(s.top == NULL) return -1;
		return s.top->data;
	}
};

int main() {
	MyQueue s;
	s.enqueue(4);
	s.enqueue(7);
	// s.enqueue(6);
	// s.enqueue(10);
	// s.enqueue(9);
	// s.enqueue(2);
	// s.enqueue(5);
	// cout << "Top is : " << s.getTop() << endl;
	// s.dequeue();
	// cout << "Top is : " << s.getTop() << endl;
	// s.dequeue();
	// cout << "Top is : " << s.getTop() << endl;

	return 0;
}
