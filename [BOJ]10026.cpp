#include<iostream>
using namespace std;
int n,cnt;
int visited[101][101];
char _map[101][101];
int dy[]={-1,0,+1,0};
int dx[]={0,+1,0,-1};

void dfs(int y,int x, char color){
	visited[y][x]=true;

	for(int i=0; i<4; i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(ny<0||ny>=n||nx<0||nx>=n) continue;
		if(_map[ny][nx]==color&&!visited[ny][nx]) dfs(ny,nx,color);
	}
}

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		scanf("%s", &_map[i]);
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(!visited[i][j]){
				dfs(i,j,_map[i][j]);
				cnt++;
			}
		}
	}
	cout<<cnt<<' ';

	fill(&visited[0][0],&visited[0][0]+101*101, 0);
	cnt=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(_map[i][j]=='R') _map[i][j]='G';
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(!visited[i][j]){
				dfs(i,j,_map[i][j]);
				cnt++;
			}
		}
	}
	cout<<cnt<<'\n';
	return 0;
}
