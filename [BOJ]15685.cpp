#include <bits/stdc++.h>
using namespace std;
int n;
int dra[104][104];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int x, y, d, g;

int go(){
    int ret = 0;
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            if (dra[i][j] == 1 && dra[i + 1][j] == 1 && dra[i][j + 1] == 1 && dra[i + 1][j + 1] == 1){
                ret++;
            }
        }
    }
    return ret;
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        vector<int> cur;
        cin >> x >> y >> d >> g;
        cur.push_back(d);
        for (int i = 0; i < g; i++){
            for (int j = cur.size() - 1; j >= 0; j--){
                cur.push_back((cur[j] + 1) % 4);
            }
        }

        dra[x][y] = 1;

        for (auto dir : cur){
            x += dx[dir];
            y += dy[dir];
            dra[x][y] = 1;
        }
    }
    cout << go() << '\n';
    return 0;
}
