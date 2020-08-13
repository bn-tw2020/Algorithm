#include <bits/stdc++.h>
using namespace std;
int r,c,start_i, start_j, end_i, end_j;
string s;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
char _map[54][54];
int water[54][54], visited[54][54];
queue<pair<int,int>> water_q;
queue<pair<int,int>> q;

void move_water(){
    int y,x;
    while(water_q.size()){
        tie(y,x)=water_q.front(); water_q.pop();
        for(int i=0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny<0 || nx<0|| ny>=r ||nx>=c) continue;
            if(_map[ny][nx]=='.'&&!water[ny][nx]){
                water[ny][nx]=water[y][x]+1;
                water_q.push({ny,nx});
            }
        }
    }
    return;
}

void bfs(){
    int y,x;
    while(q.size()){
        tie(y,x) = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny<0 || nx<0|| ny>=r ||nx>=c) continue;

            if(!visited[ny][nx] && (_map[ny][nx]=='.'||_map[ny][nx]=='D')){
                if(water[ny][nx]==0 || (water[ny][nx] > visited[y][x]+1)){
                    q.push({ny,nx});
                    visited[ny][nx]=visited[y][x]+1;
                }
            }
        }
    }
}
int main() {
    cin>>r>>c;

    for(int i=0; i<r; i++){
        cin>>s;
        for(int j=0; j<c; j++){
            _map[i][j]=s[j];
            if(s[j]=='S'){
                q.push({i,j});
                visited[i][j]=1;
            }
            else if(s[j]=='D'){
                end_i=i;
                end_j=j;
            }
            else if(s[j]=='*'){
                water_q.push({i,j});
                water[i][j]=1;
            }
        }
    }
    move_water();
    bfs();
    if(visited[end_i][end_j]) cout<<visited[end_i][end_j]-1<<'\n';
    else cout<<"KAKTUS"<<'\n';
    return 0;
}
