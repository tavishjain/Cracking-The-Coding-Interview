#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int x){
		data = x;
		left = right = NULL;
	}
};

Node* insertIntoTree(Node* head, int x){
	//This insertion works for a BST insertion but would work well for this case
	if(head == NULL) return new Node(x);
	
	if(x < head->data){
		head->left = insertIntoTree(head->left, x);
	}else if(x > head->data){
		head->right = insertIntoTree(head->right, x);
	}
	
	return head;
}

int getDepth(Node* head){
	if(head == NULL) return 0;
	return (max(getDepth(head->left), getDepth(head->right)) + 1);
}

bool checkBalanced(Node* head){
	if(head == NULL) return true;
	int leftDepth = getDepth(head->left);
	int rightDepth = getDepth(head->right);
	if(abs(leftDepth - rightDepth) > 1){
		return false;
	}else{
		return (checkBalanced(head->left) && checkBalanced(head->right));
	}
}

int main() {
	
	Node* head = NULL;
	head = insertIntoTree(head, 6);
	head = insertIntoTree(head, 3);
	head = insertIntoTree(head, 8);
	head = insertIntoTree(head, 1);
	head = insertIntoTree(head, 7);
	head = insertIntoTree(head, 9);
	head = insertIntoTree(head, 10);
	head = insertIntoTree(head, 2);
	head = insertIntoTree(head, 4);
	head = insertIntoTree(head, 5);
	
	bool check = checkBalanced(head);
	if(check) cout << "Balanced !!!!";
	else cout << "Not Balanced !!!!";
	
	return 0;
}
