#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int x){
		data = x;
		next = NULL;
	}
};
struct MinStack{
	Node* top = new Node(10000);
	void push(int x){
		Node* node = new Node(x);
		if(top == NULL){
			top = node;
		}else{
			node->next = top;
			top = node;
		}
	}
	int min(){
		return top->data;
	}
	void pop(){
		int x = top->data;
		Node* temp = top;
		top = top->next;
		free(temp);
	}
};
struct Stack{
	
	Node* top;
	MinStack ms;
	
	void push(int x){
		if(x < ms.min()) ms.push(x);
		Node* node = new Node(x);
		if(top == NULL){
			top = node;
		}else{
			node->next = top;
			top = node;
		}
	}
	
	int getMin(){
		return ms.min();
	}
	
	void pop(){
		if(top == NULL) cout << "Stack is empty, cannot pop more items !!" << endl;
		else{
			int x = top->data;
			if(x == ms.min()){
				ms.pop();
			}
			Node* temp = top;
			top = top->next;
			free(temp);
		}
	}
	
};

int main() {
	Stack s;
	s.push(4);
	s.push(7);
	s.push(6);
	s.push(10);
	s.push(9);
	s.push(2);
	s.push(5);

	cout << s.getMin() << " ";
	s.pop();
	cout << s.getMin() << " ";
	s.pop();
	cout << s.getMin() << " ";
	s.pop();
	cout << s.getMin() << " ";
	s.pop();
	cout << s.getMin() << " ";
	s.pop();
	cout << s.getMin() << " ";
	s.pop();
	cout << s.getMin() << " ";
	s.pop();
	cout << s.getMin() << " ";
	
	
	return 0;
}
