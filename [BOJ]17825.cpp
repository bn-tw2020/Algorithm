#include<bits/stdc++.h>
using namespace std;
int a[14], mul[4], v[104];
vector<int> adj[54];

void SetUp(){
	for(int i=0; i<=19; i++) adj[i].push_back(i+1);
	adj[5].push_back(21), adj[21].push_back(22), adj[22].push_back(23), adj[23].push_back(24);
	adj[15].push_back(29), adj[29].push_back(30), adj[30].push_back(31), adj[31].push_back(24);
	adj[10].push_back(27), adj[27].push_back(28), adj[28].push_back(24), adj[24].push_back(25);
	adj[25].push_back(26), adj[26].push_back(20), adj[20].push_back(100);

	v[1] = 2, v[2] = 4, v[3] = 6, v[4] = 8, v[5] = 10, v[6] = 12, v[7] = 14, v[8] = 16, v[9] = 18, v[10] = 20;
	v[11] = 22, v[12] = 24, v[13] = 26, v[14] = 28, v[15] = 30, v[16] = 32, v[17] = 34, v[18] = 36, v[19] = 38, v[20] = 40;
	v[21] = 13, v[22] = 16, v[23] = 19, v[24] = 25, v[25] = 30, v[26] = 35, v[27] = 22, v[28] = 24, v[29] = 28, v[30] = 27, v[31] = 26;
}

bool checked(int mul_idx, int idx){
	if(mul_idx == 100) return false;
	for(int i =0; i<4; i++){
		if(i == idx) continue;
		if(mul_idx == mul[i]) return true;
	}
	return false;
}

int move(int here, int cnt){
	if(here==100) return 100;
  
	if(adj[here].size()>=2){
		here = adj[here][1]; cnt--;
	}

  if(cnt){
		queue<int> q;
		q.push(here);
		int there;
		while(q.size()){
			int x = q.front(); q.pop();
			there = adj[x][0];
			q.push(there);
			if(there==100) break;
			cnt--;
			if(cnt==0) break;

		}
		return there;
	}
	else return here;
}

int go(int here){
	if (here == 10) return 0;
	int ret = 0;
	for (int i = 0; i < 4; i++){
		int idx = mul[i];
		int mul_idx = move(idx, a[here]);
		if (checked(mul_idx, i)) continue;
		mul[i] = mul_idx;
		ret = max(ret, go(here + 1) + v[mul_idx]);
		mul[i] = idx;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i=0; i<10; i++){
		cin>>a[i];
	}
	SetUp();
	cout<<go(0);
	return 0;
}
