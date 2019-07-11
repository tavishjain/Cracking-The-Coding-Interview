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
	
	void sumLists(Node* head1, Node* head2){
		Node* temp1 = head1;
		Node* temp2 = head2;
		Node* ans = NULL;
		int carry = 0;
		while(temp1 && temp2){
			int sum = temp1->data + temp2->data + carry;
			ans = pushToLast(ans, sum%10);
			carry = sum/10;
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		while(temp1){
			int sum = temp1->data + carry;
			ans = pushToLast(ans, sum%10);
			carry = sum/10;
			temp1 = temp1->next;
		}
		while(temp2){
			int sum = temp2->data + carry;
			ans = pushToLast(ans, sum%10);
			carry = sum/10;
			temp2 = temp2->next;
		}
		if(carry != 0){
			ans = pushToLast(ans, carry);
		}
		cout << "the sum list is : ";
		printList(ans);
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
		// cout << "Old list was : ";
		// printList(head);
		// cout << endl;
		
		sumLists(head1, head2);
		
		return 0;
	}
