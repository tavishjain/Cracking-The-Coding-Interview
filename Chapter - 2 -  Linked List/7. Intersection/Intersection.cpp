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

void intersection(Node* head1, Node* head2){
	int n1 = getLength(head1);
	int n2 = getLength(head2);
	int diff = abs(n1 - n2);
	if(n1 > n2){
		while(diff--) head1 = head1->next;
	}else if(n2 > n1){
		while(diff--) head2 = head2->next;
	}
	while(head1 && head2 && head1 != head2){
		head1 = head1->next;
		head2 = head2->next;
	}
	if(head1 && head2 && head1 == head2) cout << "Found intersection !!!";
	else cout << "Not intersecting !!!";
}

int main() {
	int n1;
	cin >> n1;
	int n2;
	cin >> n2;
	Node* head1 = NULL;
	for(int i = 0 ; i < n1 ; i++){
		int x;
		cin >> x;
		head1 = pushToLast(head1, x);
	}
	Node* head2 = NULL;
	for(int i = 0 ; i < n2 ; i++){
		int x;
		cin >> x;
		head2 = pushToLast(head2, x);
	}
	
	intersection(head1, head2);
	
	return 0;
}
