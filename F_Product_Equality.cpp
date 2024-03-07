#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 4e3 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<string> v(n);
    for(auto &x : v) cin>>x;

    set<int> primes;

    auto getRandomPrimes = [&] () {
        random_device rd;
        mt19937 gen(rd());
        int l = 1e8, r = 1e9;
        uniform_int_distribution<> distr(l, r);

        while(1) {
            int num = distr(gen);
            for(int i = 2; i * i <= num; i++) {
                if(num % i == 0) {
                    num = 0;
                    break;
                }
            }
            if(num) {
                primes.insert(num);
            }
            if(primes.size() > 20) return;
        }
    };
    getRandomPrimes();
    int ans = INF;

    for(auto &m : primes) {
        map<int, int> mp;
        vector<int> b(n);
        for(int i = 0; i < n; i++) {
            for(auto &ch : v[i]) {
                b[i] = b[i] * 10 + (ch - '0');
                b[i] %= m;
            }
            mp[b[i]]++;
        }
        int curAns = 0;
        for(auto &x : b) {
            for(auto &y : b) {
                int z = (x * y) % m;
                if(mp.count(z)) curAns += mp[z];
            }
        }
        ans = min(ans, curAns);
    }
    cout<<ans<<endl;
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