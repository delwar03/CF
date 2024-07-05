#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, h, w; cin>>n>>h>>w;
    int area = 0;
    vector<array<int, 2>> v(n);
    for(auto &x : v) {
        cin>>x[0]>>x[1];
        // if(x[0] > x[1]) swap(x[0], x[1]);
        area += x[0] * x[1];
    }
    sort(v.begin(), v.end());
    vector<vector<bool>> place;

    auto tryPlacing = [&](auto v) {

        place.assign(h, vector<bool>(w, false));

        int ind = 0;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(place[i][j])
                    continue;
                if(ind == n)
                    return false;
                
                int curH = v[ind][0], curW = v[ind][1];
                ind++;
                if(i + curH > h || j + curW > w)
                    return false;
                
                for(int k = 0; k < curH; k++) {
                    for(int l = 0; l < curW; l++) {
                        int x = i + k, y = j + l;
                        if(place[x][y])
                            return false;
                        place[x][y] = true;
                    }
                }
            }
        }
        return true;
    };

    auto tryRotations = [&](auto v) {
        bool hobe = false;
        function<void(int)> rec = [&](int ind) {
            if(hobe) {
                return;
            }

            if(ind == n) {
                if(tryPlacing(v)) {
                    hobe = true;
                }
                return;
            }

            rec(ind + 1);
            swap(v[ind][0], v[ind][1]);
            rec(ind + 1);
            swap(v[ind][0], v[ind][1]);
        };
        rec(0);

        return hobe;
    };

    auto isPossible = [&]() {
        do {
            if(tryRotations(v)) {
                return true;
            }
        } while(next_permutation(v.begin(), v.end()));

        return false;
    };

    if(isPossible()) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }
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