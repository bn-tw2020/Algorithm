#include<bits/stdc++.h>

using namespace std;
stack<char> stk;
string t;
int ret;
int main(){
    cin>>t;
    for(int i=0; i<t.size(); i++){
        if(t[i]=='(') stk.push(t[i]);
        else{
            stk.pop();
            if(t[i-1]=='(')
                ret+=stk.size();
            else ret+=1;
        }
    }
    cout<<ret<<'\n';
    return 0;
}
