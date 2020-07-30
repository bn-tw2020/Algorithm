#include <bits/stdc++.h>
using namespace std;
int f, s, g, u, d;
int ret=-1;
int visited[1000004];
queue<int> q;
int main(){
    cin>>f>>s>>g>>u>>d;
    
    fill(visited, visited+1000004, 0);
    q.push(s);
    visited[s]=1;
    
    while(q.size()){
        int here = q.front(); q.pop();

        if(here == g){
            cout<<visited[g]-1<<"\n";
            return 0;
        }
        if(!visited[here+u] && here+u<=f && here+u>=1){
            q.push(here+u);
            visited[here+u] = visited[here] + 1;
        }
        if(!visited[here-d] && here-d>=1 && here-d<=f){
            q.push(here-d);
            visited[here-d] = visited[here] + 1;
        }
      }
    
    cout<<"use the stairs"<<'\n';
    return 0;
    }
