#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n, start, finish;
string s,temp;
int main(){
	cin >> n;
	cin.ignore();
	while (n--) {
		finish = 0;
		start = 0;
		getline(cin, s);
 
		for (int i = 0; i <= s.size(); ++i) {
			if (s[i] == ' ' || i == s.size()) {
				temp = s.substr(start, finish);
				reverse(temp.begin(), temp.end());
				cout << temp <<' ';
				start = i + 1, finish=-1;
			}
			finish++;
		}
		cout << "\n";
	}
 
	return 0;
}
