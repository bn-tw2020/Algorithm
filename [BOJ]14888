#include<bits/stdc++.h>
using namespace std;
int n,input,op;
int ret = 987654321;
int ret2 = -987654321;
vector<int> v;
vector<int> oper;

void go(int idx, int plus, int minus, int multi, int divide, int value){
    if(idx == n-1){
        ret=min(ret,value);
        ret2 = max(ret2, value);
        return;
    }
    if(plus>0) go(idx+1, plus-1,minus, multi, divide,value+v[idx+1]);
    if(minus>0) go(idx+1,plus,minus-1, multi, divide,value-v[idx+1]);
    if(multi>0) go(idx+1,plus,minus, multi-1, divide,value*v[idx+1]);
    if(divide>0) go(idx+1,plus,minus, multi, divide-1,value/v[idx+1]);
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>input;
        v.push_back(input);
    }
    for(int i=0; i<4; i++){
        cin>>op;
        oper.push_back(op);
    }
    go(0,oper[0],oper[1],oper[2],oper[3],v[0]);
    cout<<ret2<<'\n'<<ret<<'\n';
    return 0;
}
