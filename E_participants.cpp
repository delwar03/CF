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
    int n; cin>>n;
    vector<int> v(n);
    map<int, int> freq;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        if(x == 0 && i != 0) x = n;
        v[i] = x - i;
        freq[v[i]]++;
    }
    int mxF = 0, mx = 0;
    vector<vector<int>> vec;

    for(int i = 0; i < n; i++) {
        // if(freq[i] > mxF) {
        //     mxF = freq[i];
        //     mx = i;
        // }
        vec.push_back({freq[i], i});
    }
    sort(vec.rbegin(), vec.rend());
    int ans = 0, p = vec[0][0];
    for(auto it : vec) {
        // if(it[0] < p) break;
        int val = it[1];
        int q = freq[val];
        if(val - 1 >= 0) q += freq[val - 1];
        if(val + 1 < n) q += freq[val + 1];
        ans = max(ans, q);
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