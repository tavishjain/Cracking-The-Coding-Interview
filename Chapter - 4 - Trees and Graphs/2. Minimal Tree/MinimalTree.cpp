#include <bits/stdc++.h>
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

void inorder(Node* head){
	if(head == NULL) return;
	inorder(head->left);
	cout << head->data << " ";
	inorder(head->right);
}

Node* MinimalTree(int arr[], int low, int high){
	if(low > high) return NULL;
	int mid = (low + high)/2;
	Node* node = new Node(arr[mid]);
	node->left = MinimalTree(arr, low, mid-1);
	node->right = MinimalTree(arr, mid+1, high);
	return node;
}

int main() {
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	Node* head = NULL;
	head = MinimalTree(arr, 0, 10 - 1);
	inorder(head);
	return 0;
}
