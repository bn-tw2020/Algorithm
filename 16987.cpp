// 주의할 점: 더 이상 깰 것이 없을 때 생각하자.
// 경우의수는 두가지로 깰 때와 깨지 못할 때로 나누자.

#include<iostream>
#include<vector>

using namespace std;
vector<pair<int, int>> vec;
int cnt,N;
int answer;
void go(int idx) {
    if(idx== N) {
        int cnt=0;
        for(pair<int, int> i: vec){
            if(i.first <=0) cnt++;
        }
        answer = max(answer, cnt);
        return;
    }
    if(vec[idx].first<=0) {
        go(idx+1); // 현재 계란이 꺠졌다면 넘어가자..
        return;
    }
    bool flag = true;
    for(int i=0; i<N; i++) {
        if(idx == i) continue; // 자기 자신은 꺨 수 없으니...
        if(vec[i].first <=0) continue; // 깨진 것은 넘어가자...
        flag = false;
        vec[idx].first -=vec[i].second; // 현재 잡은 계란 내구도 뺴기
        vec[i].first -=vec[idx].second; // 공격받은 계란 내구도 빼기
        go(idx+1);
        vec[idx].first +=vec[i].second;
        vec[i].first +=vec[idx].second; 
    }
    if(flag) go(idx+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int s, w;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>s>>w;
        vec.push_back(make_pair(s,w));
    }
    go(0);
    cout<<answer<<'\n';
    return 0;
}
