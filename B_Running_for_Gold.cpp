#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 50005;
const int INF = 1e15 + 10;
int arr[N][5];

bool isWin(int i, int winner) {
    int cnt = 0;
    for(int j = 0; j < 5; j++) {
        if(arr[i][j] < arr[winner][j]) cnt++;
    }
    return cnt >= 3;
}

void solve() {
    int n; cin>>n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 5; j++) {
            cin>>arr[i][j];
        }
    }

    int winner = 0;
    for(int i = 1; i < n; i++) {
        if(isWin(i, winner)) {
            winner = i;
        }
    }

    for(int i = 0; i < n; i++) {
        if(i != winner && isWin(i, winner)) {
            winner = -2;
            break;
        }
    }

    cout<<winner + 1<<endl;
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