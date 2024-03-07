#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, k; cin>>n>>k;
    string a, b; cin>>a>>b;
    vector<int> cnt1(26, 0), cnt2(26, 0);
    for(int i = 0; i < n; i++) {
        cnt1[a[i] - 'a']++;
        cnt2[b[i] - 'a']++;
    }

    for(int i = 0; i < 26; i++) {
        if(cnt1[i] < cnt2[i]) {cout<<"No"<<endl; return; }

        cnt1[i] -= cnt2[i];
        if(cnt1[i] % k || (i == 25 && cnt1[i] > 0)) {cout<<"No"<<endl; return; }
        if(i < 25) cnt1[i + 1] += cnt1[i];
    }
    cout<<"Yes"<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 