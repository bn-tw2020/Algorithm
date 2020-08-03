#include<bits/stdc++.h>
using namespace std;
int n, m, ret;
int dy[]={-1,0,1,0};
int dx[]={0,-1,0,1};
int tomato[1004][1004];
int visited[1004][1004];
queue<pair<int,int>> q;
void bfs(){
  int y, x;
  while(q.size()){
    tie(y,x)=q.front(); q.pop();
    for(int i=0; i<4; i++){
      int ny=y+dy[i];
      int nx=x+dx[i];
      if(ny<0 || nx<0 || ny>=m || nx>=n) continue;
      if(tomato[ny][nx]==0){
        tomato[ny][nx]=tomato[y][x]+1;
        q.push({ny,nx});
      }
    }
  }
  return;
}

int main(){
  cin>>n>>m;
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      cin>>tomato[i][j];
      if(tomato[i][j]==1) q.push({i,j});
      
    }
  }
  
  bfs();
  int cnt =0;
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      if(tomato[i][j]==0){
          ret=-1;
          break;
      }
      cnt = max(tomato[i][j],cnt);
    }
  }
  if(ret!=-1) cout<<cnt-1<<'\n';
  else cout<<ret<<'\n';
  return 0;
}
