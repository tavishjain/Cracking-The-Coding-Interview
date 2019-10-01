#include<iostream>

using namespace std;

bool is_unique(string str) {
    if (str.length()>128) return false;
    bool char_set[128];
    for(int i=0;i<str.length();i++) {
        if(char_set[str[i]]) return false;
        char_set[str[i]]=true;
    }
    return true;
}

int main() {
    string str;
    cout<<"Enter the string you want to check: ";
    cin>>str;
    cout<<is_unique(str);
    return 0;
}
