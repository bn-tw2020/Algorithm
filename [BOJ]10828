#include <iostream>
#include <stack>
using namespace std;
stack<int> stk;
int n, m;
string a;
int main() {
  cin>>n;
  for(int i=0; i<n; i++){
    cin>>a;
    if(a=="push"){
      cin>>m;
      stk.push(m);
    }
    if(a=="pop"){
      if(stk.empty()) cout<<-1<<'\n';
      else{
          cout<<stk.top()<<'\n';
          stk.pop();
      }
    }
    if(a=="size"){
      cout<<stk.size()<<'\n';
    }
    if(a=="empty"){
      if(!stk.empty()) cout<<0<<'\n';
      else cout<<1<<'\n'; 
    }
    if(a=="top"){
      if(stk.empty()) cout<<-1<<'\n';
      else cout<<stk.top()<<'\n';
    }
  }
}
