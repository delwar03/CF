#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

vector<string> elements = {
    "", "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne",
    "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca",
    "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
    "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr",
    "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
    "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
    "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
    "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg",
    "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
    "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm"
    };

map<string, int> mp;

int dp[18][1LL << 18];

void solve() {
    int n, k; cin>>n>>k;
    vector<int> v, p;
    for(int i = 0; i < n; i++) {
        string s; cin>>s;
        v.push_back(mp[s]);
    }
    for(int i = 0; i < k; i++) {
        string s; cin>>s;
        p.push_back(mp[s]);
    }

    vector<vector<int>> dp((1LL << n), {-1, -1}); // (j, sum)
    vector<int> par(1LL << n);
    dp[0] = {0, 0};

    for(int mask = 0; mask < (1LL << n); mask++) {
        if(dp[mask][0] == -1) continue;

        for(int i = 0; i < n; i++) {
            if((mask >> i) & 1) continue;
            int j = dp[mask][0], curSum = dp[mask][1];
            if(curSum + v[i] > p[j]) continue;

            int new_mask = mask | (1LL << i);
            par[new_mask] = i;
            curSum += v[i];
            if(curSum == p[j]) {
                dp[new_mask] = {j + 1, 0};
            } else {
                dp[new_mask] = {j, curSum};
            }
        }
    }

    if(dp.back()[0] == -1) {
        cout<<"NO"<<endl;
        return;
    }

    vector<int> ans;

    for(int mask = (1LL << n) - 1; mask; mask ^= (1LL << par[mask])) {
        ans.push_back(par[mask]);
    }

    reverse(ans.begin(), ans.end());

    cout<<"YES"<<endl;

    int j = 0, curSum = 0;

    for(int i = 0; i < n; i++) {
        if(curSum) cout<<"+";
        cout<<elements[v[ans[i]]];

        curSum += v[ans[i]];
        if(curSum == p[j]) {
            cout<<"->"<<elements[p[j]]<<endl;
            j++;
            curSum = 0;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 1; i <= 100; i++) {
        mp[elements[i]] = i;
    }

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/