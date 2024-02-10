#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 200;
const int INF = 1e15 + 10;

void solve() {
    int h, w; cin >> h >> w;
    vector<vector<int>> v(2, vector<int>(2));
    cin >> v[0][0] >> v[0][1] >> v[1][0] >> v[1][1];

    int winner = -1, turn = 0;
    while(v[0][0] < v[1][0]) {
        int dis = v[1][0] - v[0][0];
        if(dis & 1) {
            // Alice priority
            if(v[turn][1] > v[!turn][1] && v[turn][1] > 1) v[turn][1]--;
            else if(v[turn][1] < v[!turn][1] && v[turn][1] < w) {
                v[turn][1]++;
            }
        } else {
            // Bob priority
            if(v[turn][1] > v[!turn][1] && v[turn][1] < w) v[turn][1]++;
            else if(v[turn][1] < v[!turn][1] && v[turn][1] > 1) {
                v[turn][1]--;
            }
        }

        v[turn][0] += turn ? -1 : 1;

        if(v[0] == v[1]) {
            winner = turn;
            break;
        }

        turn ^= 1;
    }

    if(winner == -1) cout<<"Draw\n";
    else if(winner == 0) cout<<"Alice\n";
    else cout<<"Bob\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        // cout<<"Scenario #"<<c++<<":\n";
        solve();
    }
    return 0;
}
 
/*
i/p: 
o/p: 
*/ 