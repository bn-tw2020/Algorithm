#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, t, ans;
ll lo, hi, mid;
vector<long long> tree;

int check(ll mid){
	ll sum = 0;
	for (int i = 0; i < tree.size(); i++){
		sum += max((ll)0, (tree[i] - mid));
	}
	if (sum < m)
		return 1;
	else
		return 0;
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> t;
		tree.push_back(t);
	}
	lo = 0;
	hi = 1e9;
	while (lo <= hi){
		mid = (lo + hi) / 2;
		if (check(mid))
			hi = mid - 1;
		else{
			lo = mid + 1;
			ans = mid;
		}
	}
	cout << ans;
	return 0;
}
