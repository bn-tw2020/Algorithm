#include<bits/stdc++.h>
using namespace std;
int n,r,c;
int dy[]={0,0,1,1};
int dx[]={0,1,0,1};
int cnt;
void go(int len, int y, int x){
    if(len==2){
        for(int i=0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny == r && nx ==c){
                cout<<cnt<<'\n';
                return;
            }
            cnt++;
        }
        return;
    }
    
    go(len/2,y,x);
    go(len/2, y, x+len/2);
    go(len/2, y+len/2, x);
    go(len/2,y+len/2,x+len/2);
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>r>>c;

    go(1<<n,0,0);
    return 0;
}
