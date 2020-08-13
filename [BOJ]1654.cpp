#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int k, n;
int a[10000];
int _max=-987654321;
ll ans=0;
bool chk(ll mid) {
    int cnt = 0;
    for (int i = 0; i < k; ++i)
        cnt += a[i] / mid;
 
    return cnt < n;
}
 
int main() {
    cin>>k>>n;
 
    for (int i = 0; i < k; ++i) {
        cin>>a[i];
        _max = max(a[i],_max);
    }
    
    ll lo = 1, hi = _max;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (chk(mid)) {
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
            ans = mid;
        }
    }
 
    cout<<ans<<'\n';
 
    return 0;
}
