#include<bits/stdc++.h>
using namespace std;

int countSteps(int n){
	vector<int> vec(n+1);
	vec[1] = 1;
	vec[2] = 2;
	vec[3] = 4;
	
	for(int i = 4 ; i <= n ; i++){
		vec[i] = vec[i-1] + vec[i-2] + vec[i-3];
	}
	return vec[n];
}

int main(){
	
	int n;
	cin >> n;
	cout << countSteps(n);
	
	return 0;
}