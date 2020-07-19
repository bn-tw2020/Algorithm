#include<bits/stdc++.h>
using namespace std;
int t;

bool Check(string str){
    stack<char> st;
    for(auto &c : str){
        if(c == '('){
            st.push(c);
        }
        else{
            if(!st.empty()){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    return st.empty();
}
int main(){
   cin>>t;
   for(int i=0; i<t; i++){
       string str;
       cin>>str;
       if(Check(str)){
           cout<<"YES"<<'\n';
       }
       else{
           cout<<"NO"<<'\n';
       }
   }
    return 0;
}
