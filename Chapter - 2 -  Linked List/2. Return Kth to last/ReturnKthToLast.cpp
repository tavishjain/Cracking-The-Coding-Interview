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

void kthToLast(Node *head){
	int k;
	cin >> k;
	int n = getLength(head);
	if(k > n){
		cout << "k is greater than n !!!!";
	}else{
		Node* slow = head;
		Node* fast = head;
		while(k--) fast = fast->next;
		while(fast){
			slow = slow->next;
			fast = fast->next;
		}
		cout << "kth from last is : " << slow->data;
	}
}

int main() {
	//Number of nodes in the linked list
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
	
	kthToLast(head);
	
	return 0;
}
