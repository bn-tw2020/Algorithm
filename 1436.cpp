// 2021.1.1
// N의 범위가 10000까지이기 때문에
// 숫자를 하나씩 더해가면서 진행해도 충분히 해결이 가능
#include<iostream>
using namespace std;
int n;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	int i=666;
	
	while(1) {
		if(to_string(i).find("666")!=string::npos) n--;
		if(n==0) break;
		i++;
	}
	cout<<i<<'\n';
	return 0;
}
