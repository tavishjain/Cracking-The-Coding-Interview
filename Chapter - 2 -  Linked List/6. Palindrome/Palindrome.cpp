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

void palindrome(Node *head){
	Node* ans = NULL;
	Node* temp = head;
	while(temp){
		ans = pushToFront(ans, temp->data);
		temp = temp->next;
	}
	temp = head;
	while(temp && ans){
		if(temp->data != ans->data){
			cout << "Not a Plaindrome";
			return;
		}
		temp = temp->next;
		ans = ans->next;
	}
	cout << "Palindrome !!!";
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
	
	palindrome(head);
	
	return 0;
}
