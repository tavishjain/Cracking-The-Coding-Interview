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
	
Node* pushToLast(Node* head, int data){
	Node* node = new Node(data);
	Node* temp = head;
	if(head == NULL){
		head = node;
	}else{
		while(temp && temp->next) temp = temp->next;
		temp->next = node;
	}
	return head;
}
	
Node* pushToFront(Node* head, int data){
	Node* node = new Node(data);
	Node* temp = head;
	if(temp == NULL) head = node;
	else{
		node->next = head;
		head = node;
	}
	return head;
}
	
int getLength(Node* head){
	Node* temp = head;
	int count = 0;
	while(temp){
		count++;
		temp = temp->next;
	}
	return count;
}
	
void printList(Node* head){
	Node* temp = head;
	while(temp){
		cout << temp->data << " ";
		temp = temp->next;
	}
}

void detectLoop(Node* head){
	Node* slow = head;
	Node* fast = head;
	slow = slow->next;
	fast = fast->next->next;
	while(fast && fast->next){
		if(slow == fast) break;
		slow = slow->next;
		fast = fast->next->next;
	}
	if(slow == fast){
		slow = head;
		while(slow != fast){
			slow = slow->next;
			fast = fast->next;
		}
		cout << "Loop detected and starting node of the loop is " << slow->data;
	}else{
		cout << "No loop found";
	}
}

int main() {
	int n;
	cin >> n;
	Node* head = NULL;
	for(int i = 0 ; i < n ; i++){
		int x;
		cin >> x;
		head = pushToLast(head, x);
	}
	
	detectLoop(head);
	
	return 0;
}
