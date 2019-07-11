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
	while(temp) count++;
	return count;
}

void printList(Node* head){
	Node* temp = head;
	while(temp){
		cout << temp->data << " ";
		temp = temp->next;
	}
}

void RemoveDups(Node *head){
	bool vis[10000];
	for(int i = 0 ; i < 10000 ; i++) vis[i] = false;
	
	Node* temp = head;
	Node* ans = NULL;
	while(temp){
		if(vis[temp->data] == true){
			
		}else{
			vis[temp->data] = true;
			ans = pushToLast(ans, temp->data);
		}
		temp = temp->next;
	}
	cout << "New list after removal of duplicates is : ";
	printList(ans);
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
	
	RemoveDups(head);
	
	return 0;
}
