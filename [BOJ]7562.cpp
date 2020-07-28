#include<bits/stdc++.h>
using namespace std;
int t, l;
int a, b, c, d;
int visited[304][304];
int dy[]={-1,-2,-2,-1,1,2,1,2};
int dx[]={-2,-1,1,2,-2,-1,2,1};

int bfs(int y,int x) {
    queue<pair<int,int>> q;
    q.push({y, x});
    while (q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(y ==c && x == d) return visited[c][d];
        for (int i = 0; i < 8; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 | ny >= l || nx >= l || visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    return 0;
}
int main(){
    cin>>t;
    while(t--){
        cin>>l;
        cin>>a>>b>>c>>d;
        fill(&visited[0][0], &visited[0][0]+304*304, 0);
        cout<<bfs(a,b)<<'\n';
    }
    return 0;
}
