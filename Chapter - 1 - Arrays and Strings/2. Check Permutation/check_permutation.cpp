#include<string>
#include<set>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t)
    {
        string s1,s2;
        cin>>s1>>s2;
        if(s1.length()!=s2.length())
        cout<<"NO";
        else
        {
            int i;
            set<int> se1,se2;
            set <int>::iterator it1;
            set <int>::iterator it2;
            for(i=0;i<s1.length();i++)
            {
                se1.insert(s1[i]);
                se2.insert(s2[i]);
            }
            if(se1.size()!=se2.size())
            cout<<"NO";
            else
            {
                int f=1;
                for(it1=se1.begin(),it2=se2.begin();it1!=se1.end(),it2!=se2.end();++it1,++it2)
                {
                    if(*it1!=*it2)
                    {
                        cout<<"NO";
                        f=0;
                        break;
                    }
                }
                if(f==1)
                cout<<"YES";
            }
        }
        cout<<endl;
        t--;
    }
    return 0;
}

