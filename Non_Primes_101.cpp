#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e2 + 10;
const int INF = 1e15 + 10;

int prime[N];
set<int> primes;

void solve() {
    int n; cin>>n;
    map<int, vector<int>> mp;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) {
        cin>>v[i];
        mp[v[i]].push_back(i);
    }

    for(int i = 1; i <= 105; i++) {
        for(int j = 1; j <= 105; j++) {
            if(!primes.count(i + j)) {
                if(mp.count(i) && mp.count(j)) {
                    if(i == j) {
                        if(mp[i].size() >= 2) {
                            cout<<mp[i][0]<<" "<<mp[i][1]<<endl;
                            return;
                        }
                    } else {
                        cout<<mp[i].back()<<" "<<mp[j].back()<<endl;
                        return;
                    }
                }
            }
        }
    }
    cout<<-1<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 2; i < N; i++) prime[i] = i;

    for(int i = 2; i < N; i++) {
        for(int j = 2 * i; j < N; j += i) {
            if(prime[j] == j) {
                prime[j] = i;
            }
        }
    }

    for(int i = 2; i < N; i++) {
        if(prime[i] == i) {
            primes.insert(i);
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