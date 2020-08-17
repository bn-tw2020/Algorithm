#include<bits/stdc++.h>
using namespace std;
int n;
int src[26];
int des[26];
string str1, str2;
bool flag;
int main(){
  cin>>n;
  for(int i=0; i<n; i++){
    flag=true;
    fill(src, src+26, 0);
    fill(des, des+26, 0);
    cin>>str1>>str2;

    if(str1.size() != str2.size()){
      flag = false;
    }
    else{
      for(int i=0; i<str1.size(); i++){
        src[str1[i]-97]++;
        des[str2[i]-97]++;
      }

      for(int i=0; i<26; i++){
        if(src[i]!=des[i]){
          flag=false;
          break;
        }
      }
    }
    if(flag){
      cout<<"Possible"<<'\n';
    } else{
      cout<<"Impossible"<<'\n';
    }
  }
  return 0;
}
