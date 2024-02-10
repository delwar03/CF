#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

int binPow(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}

vector<int> getDivisior(int n) {
    vector<int> res;
    res.push_back(1);
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            res.push_back(i);
            if(i != n / i) {
                res.push_back(n / i);
            }
        }
    }
    if(n > 1) res.push_back(n);
    sort(res.begin(), res.end());
    return res;
}

bool isPalin(string s) {
    int l = 0, r = s.size() - 1;
    while(l < r) {
        if(s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

void solve() {
    string s; cin>>s;
    int n = s.size();
    int ans = 1;
    for(int i = 0; i < n; i++) {
        string str = "";
        for(int j = i; j < n; j++) {
            str += s[j];
            if(isPalin(str)) {
                ans = max(ans, (int) str.size());
            }
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