#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e15 + 10;
vector<int> siv(N, 1);

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    int neg = 0, pos = 0;
    int negCnt = 0, posCnt = 0;
    for(auto &x : v) {
        cin>>x;
        if(x < 0) swap(negCnt, posCnt);
        x < 0 ? negCnt++ : posCnt++;
        neg += negCnt;
        pos += posCnt;
    }
    cout<<neg<<" "<<pos<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 