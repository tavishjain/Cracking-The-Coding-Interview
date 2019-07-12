#include <iostream>
using namespace std;

struct TreeNode{
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x){
		data = x;
		left = right = NULL;
	}
};

void validateBST(TreeNode* head){
	vector<int> order;
	inorder(head, order);
	for(int i = 1 ; i < order.size() ; i++){
		if(order[i] < order[i-1]){
			 cout << "Not a BST !!!";
			 return;
		}
	}
	cout << "It is a BST !!!";
}

void inorder(TreeNode* head, vector<int> &order){
	if(head == NULL) return;
	inorder(head->left);
	order.push_back(head->data);
	inorder(head->right);
}

int main() {
	
	//Build a binary tree and then pass it into the validateBST function
	
	return 0;
}
