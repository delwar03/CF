#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    int negCnt = 0, maxNeg = -INF, indNeg = 0;
    vector<int> zeroInd;
    vector<int> zero(n + 1);

    for(int i = 0; i < n; i++) {
        cin>>v[i];
        if(v[i] == 0) {
            zeroInd.push_back(i + 1);
            zero[i + 1] = 1;
        } else if(v[i] < 0) {
            if(v[i] > maxNeg) {
                maxNeg = v[i];
                indNeg = i + 1;
            }
            negCnt++;
        }
    }
    int cnt = 0;

    if(negCnt & 1) {
        if(zeroInd.size()) {
            for(int i = 0; i < zeroInd.size() - 1; i++) {
                cout<<"1 "<<zeroInd[i]<<" "<<zeroInd[i + 1]<<endl;
                cnt++;
            }
            cout<<"1 "<<zeroInd.back()<<" "<<indNeg<<endl; cnt++;
        }
        if(cnt == n - 1) return;
        cout<<"2 "<<indNeg<<endl;
        vector<int> pos;
        for(int i = 1; i <= n; i++) {
            if(!zero[i] && (i ^ indNeg)) {
                pos.push_back(i);
            }
        }
        for(int i = 0; i < pos.size() - 1; i++) {
            cout<<"1 "<<pos[i]<<" "<<pos[i + 1]<<endl;
        }
    } else {
        if(zeroInd.size()) {
            for(int i = 0; i < zeroInd.size() - 1; i++) {
                cout<<"1 "<<zeroInd[i]<<" "<<zeroInd[i + 1]<<endl;
                cnt++;
            }
            if(zeroInd.size() != n) {
                cout<<"2 "<<zeroInd.back()<<endl;
                cnt++;
            }
        }
        
        if(cnt == n - 1) return;

        vector<int> pos;
        for(int i = 1; i <= n; i++) {
            if(!zero[i]) {
                pos.push_back(i);
            }
        }
        for(int i = 0; i < pos.size() - 1; i++) {
            cout<<"1 "<<pos[i]<<" "<<pos[i + 1]<<endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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