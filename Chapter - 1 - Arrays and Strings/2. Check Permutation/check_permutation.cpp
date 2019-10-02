#include<iostream>

using namespace std;

bool check_permutation(string s1, string s2) {
    int len[128];
    if(s1.length()!=s2.length()) return false;
    for(int i=0;i<s1.length();i++) {
        len[s1[i]]++;
        len[s2[i]]--;
    }
    for(int i=0;i<s1.length();i++) {
        if(len[s1[i]]!=0) return false;
    }
    return true;
}

int main() {
    string s1,s2;
    cout<<"Enter string 1: ";
    cin>>s1;
    cout<<"Enter string 2: ";
    cin>>s2;
    bool permute = check_permutation(s1, s2);
    permute ? cout<<"Both are permutations of each other" : cout<<"Both are not permutations of each other";
    return 0;
}
