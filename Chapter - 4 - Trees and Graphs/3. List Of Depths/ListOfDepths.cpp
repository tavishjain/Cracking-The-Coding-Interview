#include <bits/stdc++.h>
using namespace std;

struct Node{
	int value;
	struct Node *left;
	struct Node *right;
	Node(int x){
		value = x;
		left = right = NULL;
	}
};

Node* buildBinaryTree(Node *root, vector<int> nums, int i, int n){
	if(i < n){
		Node* node = new Node(nums[i]);
		root = node;
		root->left = buildBinaryTree(root->left, nums, 2*i + 1, n);
		root->right = buildBinaryTree(root->right, nums, 2*i + 2, n);
	}
	return root;
}

int findDepth(Node* root){
	int count = 0;
	while(root){
		root = root->left;
		count++;
	}
	return count;
}

void levelOrderTraversal(Node *root, vector<vector<int>> &list, int nodes){ 
    if (root == NULL) return; 
  
    queue<Node*> q; 
    q.push(root);
    int j = 0;
    int found = 1;
    while (!q.empty()) { 
        Node *curr = q.front(); 
        q.pop(); 
        if(found == 0){
        	j = j+1;
        	found = pow(2, j);
        }
        if(curr->left) q.push(curr->left); 
        if(curr->right) q.push(curr->right); 
        list[j].push_back(curr->value);
        found--;
    } 
} 

int main() {
	// your code goes here
	Node* root = NULL;
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0 ; i < n ; i++) cin >> nums[i];
	
	root = buildBinaryTree(root, nums, 0, n);
	int depth = findDepth(root);
	vector<vector<int>> list(depth);
	
	levelOrderTraversal(root, list, n);
	for(int i = 0 ; i < list.size() ; i++){
		for(int j = 0 ; j < list[i].size() ; j++){
			cout << list[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}