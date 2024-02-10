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

void solve() {
    string s; cin>>s;
    string a = "", b = "";
    a += s[0];
    a += s[1];
    b += s[2];
    b += s[3];
    int x = stoi(a);
    int y = stoi(b);
    // cout<<x<<" "<<y<<endl;
    vector<int> f(2, 0);
    if(x <= 12 && x > 0) f[0]++;
    if(y <= 12 && y > 0) f[1]++;
    if(f[0] && f[1]) cout<<"AMBIGUOUS"<<endl;
    else if(!f[0] && !f[1]) cout<<"NA"<<endl;
    else if(f[0]) cout<<"MMYY"<<endl;
    else cout<<"YYMM"<<endl;
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