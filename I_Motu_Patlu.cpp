#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

int sum = 0;
int a, b, x;

int f(int n) {
	int cnt = 0;
	int m = n;
	while(m) {
		cnt++;
		m /= 10;
	}
	return cnt;
}

bool hobe(int m) {
	int sum = a * m + b * f(m);
	return sum <= x;
}

void solve() {
	cin>>a>>b>>x;
    // if(b > x) {
    //     cout<<0<<endl;
    //     return;
    // }
	int l = 0, r = 1e9, ans = 0;
	while(l <= r) {
		int m = (l + r) >> 1;
		if(hobe(m)) {
			ans = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 