/* Pythagorus Triplet in Array */

#include<bits/stdc++.h>
using namespace std;

bool pythagorusTriplet(int arr[],int n){
	sort(arr,arr+n);
	for(int i=n-1;i>=2;i--){
		int j=i-1;
		for(int k=0;k<j;k++){
			if(pow(arr[i],2)==(pow(arr[j],2)+pow(arr[k],2)))
				return true;
		}
	}
	return false;
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	if(pythagorusTriplet(arr,n))
		cout<<"True";
	else
		cout<<"False";
	return 0;
}