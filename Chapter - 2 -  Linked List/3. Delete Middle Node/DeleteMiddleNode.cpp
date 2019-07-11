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

void deleteMiddleNode(Node* node){
	if(node == NULL || node->next == NULL){
		cout << "Not possible";
	}else {
		node->data = node->next->data;
		node->next = node->next->next;
		cout << "Deleted the node" << endl;
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
	cout << "Old list was : ";
	printList(head);
	cout << endl;
	//Some random node to be deleted
	Node* temp = head->next->next->next->next;
	deleteMiddleNode(temp);
	cout << "new Updated list is : ";
	printList(head);
	return 0;
}
