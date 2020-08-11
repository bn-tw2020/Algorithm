#include<bits/stdc++.h>
using namespace std;
int n;
int INF=987654321;
int dy[]={0,-1,0,1};
int dx[]={1,0,-1,0};
int _map[130][130];
int dist[130][130];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int main(){
    while(1){
        cin>>n;
        if(n==0) break;
        fill(&_map[0][0], &_map[0][0]+130*130,0);
        fill(&dist[0][0], &dist[0][0]+130*130, INF);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>_map[i][j];
            }
        }
        
        pq.push({_map[0][0],0});
        dist[0][0]=_map[0][0];
        while(pq.size()){
            int herey = pq.top().second/1000;
            int herex = pq.top().second%1000;
            int here_dist = pq.top().first;
            pq.pop();
            if(dist[herey][herex]!=here_dist) continue;
            for(int i=0; i<4; i++){
                int ny = herey+dy[i];
                int nx = herex+dx[i];
                if(ny<0 || nx<0||ny>=n||nx>=n) continue;
                int _dist=_map[ny][nx];
                if(dist[ny][nx]>dist[herey][herex]+_dist){
                    dist[ny][nx]=dist[herey][herex]+_dist;
                    pq.push({dist[ny][nx],ny*1000+nx});
                }
            }
        }
        t++;
        printf("Problem %d: %d\n", t, dist[n - 1][n - 1]);

    }
    return 0;
}
