#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N =  2000005;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int siv[N];

int binpow (int a ,int b) {
    int ans=1 ;
    while (b > 0) {
        if (b & 1) ans= ans*a;
        a= a*a ;
        b >>= 1;
    }
    return ans;
}
void solve() {

    int n ; cin >> n ;
    vector < int> prime;
    for (int i=1 ; i <N ; i++) siv[i]=i;
    for (int i = 2 ;i < N  ;i++) {
        if (siv[i] == i) {
            prime.push_back (i);
            for (int j = i*i ; j < N ; j += i) {
                if (siv[j] == j) {
                    siv[j] = i;
                }
            }
        }
    } 
  
    int ans=0;

    for (int i=0 ; i < prime.size () ; i++) {
        int x= binpow (prime[i] ,8);
        if (x <= n) ans++;
        else break;
    }

    for (int i=0 ;i < prime.size () ;i++) {
        int p= prime[i]* prime[i];
        if (p * p > n) break;
        for (int j= i+1 ; j < prime.size () ;j++) {
            int pp= p * prime[j] * prime[j];
            if (pp >n) break;
            else ans++;
        }
    }
    cout << ans <<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}