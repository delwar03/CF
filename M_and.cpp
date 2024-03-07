#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
int n, s;

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

bool isPossible(int x, vector<int>& v) {
    int cnt = 1, temp = v[0];
    for(int i = 1; i < n; i++) {
        if(v[i] - temp >= x) {
            temp = v[i];
            cnt++;
        }
        if(cnt == s) return true;
    }
    return false;
}

void solve() {
    cin>>n>>s;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin>>v[i];
    sort(v.begin(), v.end());
    int l = 0, r = INF, ans = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(isPossible(mid, v)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 