#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 4e3 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;

    auto isPowerOfTwo = [&] (int n) {
        return !(n & (n - 1));
    };
    
    auto isPrime = [&] (int n) {
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) return false;
        }
        return true;
    };

    if(n & 1) {
        if(n == 1) {
            cout<<"FastestFinger"<<endl;
        } else {
            cout<<"Ashishgup"<<endl;
        }
    } else {
        if(n == 2) {
            cout<<"Ashishgup"<<endl;
        } else {
            if(isPowerOfTwo(n)) {
                cout<<"FastestFinger"<<endl;
            } else {
                int m = n / 2;
                if(m & 1) {
                    if(isPrime(m)) {
                        cout<<"FastestFinger"<<endl;
                    } else {
                        cout<<"Ashishgup"<<endl;
                    }
                }
                else {
                    cout<<"Ashishgup"<<endl;
                }
            }
        }
    }
    // cout<<"fact: ";
    // for(auto it : fact) cout<<it<<" "; cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 