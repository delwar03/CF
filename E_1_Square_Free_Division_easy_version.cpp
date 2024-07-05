#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e7 + 10;
const int INF = 1e15 + 10;

int prime[N];

void solve() {
    int n, k; cin>>n>>k;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    int cnt = 1;
    set<int> st;

    for(auto it : v) {
        int num = 1;
        while(it > 1) {
            int di = prime[it], ct = 0;
            while(it % di == 0) {
                it /= di;
                ct++;
            }
            
            if(ct % 2) num *= di;
        }
        if(st.count(num)) {
            st.clear();
            cnt++;
        }
        st.insert(num);
    }

    cout<<cnt<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < N; i++) prime[i] = i;

    for(int i = 2; i * i < N; i++) {
        if(prime[i] == i) {
            for(int j = 2 * i; j < N; j += i) {
                prime[j] = i;
            }
        }
    }

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/