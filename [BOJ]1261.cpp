#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int INF=987654321;
int dy[]={0,-1,0,1};
int dx[]={1,0,-1,0};
int _map[104][104];
int dist[104][104];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int main(){
    fill(&_map[0][0], &_map[0][0]+104*104, 0);
    fill(&dist[0][0], &dist[0][0]+104*104, INF);
    cin>>n>>m;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%1d",&_map[i][j]);
        }
    }
    pq.push({0,0});
    dist[0][0]=0;
    while(pq.size()){
        int herey = pq.top().second/1000;
        int herex = pq.top().second%1000;
        int here_dist = pq.top().first;
        pq.pop();
        if(dist[herey][herex]!=here_dist) continue;
        for(int i=0; i<4; i++){
            int ny = herey+dy[i];
            int nx = herex+dx[i];
            if(ny<0 || nx<0 || ny>=m || nx>=n) continue;

            if(_map[ny][nx]==1){
                if(dist[ny][nx]>dist[herey][herex]+1){
                    dist[ny][nx]=dist[herey][herex]+1;
                    pq.push({dist[ny][nx],ny*1000+nx});
                }
            }
            if(_map[ny][nx]==0){
                if(dist[ny][nx]>dist[herey][herex]){
                    dist[ny][nx]=dist[herey][herex];
                    pq.push({dist[ny][nx],ny*1000+nx});
                }
            }
        }
    }
    printf("%d",dist[m-1][n-1]);
    return 0;
}
