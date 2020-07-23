#include<bits/stdc++.h>
using namespace std;
int r, c, k;
char a[7][7];
int visited[7][7];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};

int go(int y, int x){
    int ans=0;

    if(y == 0 && x == c-1){
        if(k == visited[y][x]) return 1;
        return 0;
    } 
    
    for(int i=0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny < 0 || nx <0 || ny >= r || nx >= c) continue;
        if (visited[ny][nx] || a[ny][nx]=='T') continue;
        visited[ny][nx] = visited[y][x]+1;
        ans += go(ny,nx);
        visited[ny][nx]=0;
    }
    return ans;
}

int main(){
    cin>>r>>c>>k;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>a[i][j];
        }
    }
    fill(&visited[0][0], &visited[0][0]+7*7, 0);
    visited[r-1][0]=1;
    cout<<go(r-1, 0)<<'\n';
    return 0;
}
