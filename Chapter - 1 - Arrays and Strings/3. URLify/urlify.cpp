#include <iostream>
using namespace std;
int main() {

    string s,result="",append="%20";
    getline(cin,s);
    
    int i,l=s.length();
    for(i=0;i<l;i++)
    {
        if(s[i]!=' ')
        result+=s[i];
        else
        result+=append;
    }
    cout<<result;

	return 0;
}
