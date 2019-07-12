#include <bits/stdc++.h>
using namespace std;

#define n 10

struct Graph{
	vector<int> adj[n];
	void pushEdge(int from, int to){
		adj[from].push_back(to);
	}
};

void printPaths(int u, int d, vector<int> adj[], vector<bool> visited, int path[], int &path_index){
    visited[u] = true; 
    path[path_index] = u; 
    path_index++; 
  
    if (u == d) { 
        for (int i = 0; i<path_index; i++) cout << path[i] << " "; 
        cout << endl; 
    }else{ 
        vector<int>::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
            if (!visited[*i]) 
                printPaths(*i, d, adj, visited, path, path_index); 
    } 
    path_index--; 
    visited[u] = false; 
}

void findPath(int from, int to, vector<int> adj[]){
	queue<int> q;
	q.push(from);
	vector<bool> vis(n, false);
	vis[from] = true;
	bool found = false;
	while(!q.empty()){
		int num = q.front();
		q.pop();
		for(auto it : adj[num]){
			if(!vis[it]){
				 if(it == to){
				 	found = true;
				 	break;
				 }
				 q.push(it);
				 vis[it] = true;
			}
		}
	}
	if(!found){
		cout << "No Path found !!!" << endl;
	}else{
		cout << "Path found !!" << endl;
		for(int i = 0 ; i < n ; i++) vis[i] = false;
		int path_index = 0;
		int path[n];
		printPaths(from, to, adj, vis, path, path_index);
	}
}

int main() {
	Graph g;
	g.pushEdge(1, 2);
	g.pushEdge(2, 4);
	g.pushEdge(4, 7);
	g.pushEdge(2, 3);
	g.pushEdge(3, 5);
	g.pushEdge(1, 5);
	g.pushEdge(5, 6);
	g.pushEdge(6, 7);
	
	findPath(1, 6, g.adj);
	
	return 0;
}
