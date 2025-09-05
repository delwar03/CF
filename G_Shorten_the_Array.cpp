#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define int long long
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int POW(long long n, long long k) {
  int ans = 1 % mod; n %= mod; if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}
const int inv2 = (mod + 1) >> 1;
// #define M (1 << 10)
#define OR 0
#define AND 1
#define XOR 2

// struct FWHT {
// public:
//   int P1[M], P2[M];
//   void wt(int *a, int n, int flag = XOR) {
//     if (n == 0) return;
//     int m = n / 2;
//     wt(a, m, flag); wt(a + m, m, flag);
//     for (int i = 0; i < m; i++){
//       int x = a[i], y = a[i + m];
//       if (flag == OR) a[i] = x, a[i + m] = (x + y) % mod;
//       if (flag == AND) a[i] = (x + y) % mod, a[i + m] = y;
//       if (flag == XOR) a[i] = (x + y) % mod, a[i + m] = (x - y + mod) % mod;
//     }
//   }
//   void iwt(int* a, int n, int flag = XOR) {
//     if (n == 0) return;
//     int m = n / 2;
//     iwt(a, m, flag); iwt(a + m, m, flag);
//     for (int i = 0; i < m; i++){
//       int x = a[i], y = a[i + m];
//       if (flag == OR) a[i] = x, a[i + m] = (y - x + mod) % mod;
//       if (flag == AND) a[i] = (x - y + mod) % mod, a[i + m] = y;
//       if (flag == XOR) a[i] = 1LL * (x + y) * inv2 % mod, a[i + m] = 1LL * (x - y + mod) * inv2 % mod; // replace inv2 by >>1 if not required
//     }
//   }
//  vector<int> multiply(int n, vector<int> A, vector<int> B, int flag = XOR) {
//     assert(__builtin_popcount(n) == 1);
//     A.resize(n); B.resize(n);
//     for (int i = 0; i < n; i++) P1[i] = A[i];
//     for (int i = 0; i < n; i++) P2[i] = B[i];
//     wt(P1, n, flag); wt(P2, n, flag);
//     for (int i = 0; i < n; i++) P1[i] = 1LL * P1[i] * P2[i] % mod;
//     iwt(P1, n, flag);
//     return vector<int> (P1, P1 + n);
//   }
//   vector<int> pow(int n, vector<int> A, long long k, int flag = XOR) {
//     assert(__builtin_popcount(n) == 1);
//     A.resize(n);
//     for (int i = 0; i < n; i++) P1[i] = A[i];
//     wt(P1, n, flag);
//     for(int i = 0; i < n; i++) P1[i] = POW(P1[i], k);
//     iwt(P1, n, flag);
//     return vector<int> (P1, P1 + n);
//   }
// }t;

struct FWHT {
    using Map = unordered_map<uint32_t,int>;
  
    int LOG;
    FWHT(uint32_t max_value) {
      LOG = 0;
      while ((1u << LOG) <= max_value) ++LOG;
    }

    void wt(Map &M, int flag = XOR) {
      for (int b = 0; b < LOG; ++b) {
        uint32_t mask = 1u << b;
  
        vector<uint32_t> keys;
        keys.reserve(M.size() * 2);
        for (auto &kv : M) {
          uint32_t x = kv.first;
          keys.push_back(x);
          keys.push_back(x ^ mask);
        }
        sort(keys.begin(), keys.end());
        keys.erase(unique(keys.begin(), keys.end()), keys.end());
  
        Map M2;
        M2.reserve(keys.size());
        for (uint32_t x : keys) {
          uint32_t y = x ^ mask;
          int64_t u = M.count(x) ? M[x] : 0;
          int64_t v = M.count(y) ? M[y] : 0;
  
          if (flag == OR) {
            if ((x & mask) == 0) {
              M2[x] = u;
              M2[y] = (u + v) % mod;
            }
          }
          else if (flag == AND) {
            if ((x & mask) != 0) {
              M2[x] = (u + v) % mod;
              M2[y] = v;
            }
          }
          else {
            if (x < y) {
              M2[x] = (u + v) % mod;
              M2[y] = (u - v + mod) % mod;
              if(!M2[x]) M2.erase(x);
              if(!M2[y]) M2.erase(y);
            }
          }
        }
        M.swap(M2);
      }
    }
  
    void iwt(Map &M, int flag = XOR) {
      for (int b = 0; b < LOG; ++b) {
        uint32_t mask = 1u << b;
  
        vector<uint32_t> keys;
        keys.reserve(M.size() * 2);
        for (auto &kv : M) {
          uint32_t x = kv.first;
          keys.push_back(x);
          keys.push_back(x ^ mask);
        }
        sort(keys.begin(), keys.end());
        keys.erase(unique(keys.begin(), keys.end()), keys.end());
  
        Map M2;
        M2.reserve(keys.size());
        for (uint32_t x : keys) {
          uint32_t y = x ^ mask;
          int64_t u = M.count(x) ? M[x] : 0;
          int64_t v = M.count(y) ? M[y] : 0;
  
          if (flag == OR) {
            if ((x & mask) == 0) {
              M2[x] = u;
              M2[y] = (v - u + mod) % mod;
            }
          }
          else if (flag == AND) {
            if ((x & mask) != 0) {
              M2[x] = (u - v + mod) % mod;
              M2[y] = v;
            }
          }
          else { // XOR
            if (x < y) {
              M2[x] = int((u + v) % mod * 1LL * inv2 % mod);
              M2[y] = int((u - v + mod) % mod * 1LL * inv2 % mod);
              if(!M2[x]) M2.erase(x);
              if(!M2[y]) M2.erase(y);
            }
          }
        }
        M.swap(M2);
      }
    }
  
    Map pointwise_mul(const Map &A, const Map &B) {
      Map C;
    //   C.reserve(min(A.size(), B.size()));
      for (auto &kv : A) {
        auto it = B.find(kv.first);
        if (it != B.end()) {
          C[kv.first] = int64_t(kv.second) * it->second % mod;
        }
      }
      return C;
    }
  
    // convolution: C = A ★ B
    Map multiply(Map A, Map B, int flag = XOR) {
      wt(A, flag);
      wt(B, flag);
      Map C = pointwise_mul(A, B);
      iwt(C, flag);
      return C;
    }
  
    Map pow(Map A, long long k, int flag = XOR) {
      wt(A, flag);
      for (auto &kv : A) {
        int64_t v = kv.second;
        int64_t res = 1, base = v % mod;
        long long e = k;
        while (e) {
          if (e & 1) res = res * base % mod;
          base = base * base % mod;
          e >>= 1;
        }
        kv.second = int(res);
      }
      iwt(A, flag);
      return A;
    }
  };

void solve() {
    int n, k; cin>>n>>k;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    auto f = [&] (int len) {
        for(int i = 0; i + len - 1 < n; i++) {
            FWHT::Map cnt;
            int mx = 0;
            for(int j = i; j <= i + len - 1; j++) {
                cnt[v[j]] = 1;
                mx = max(mx, v[j]);
            }
            FWHT fw(mx);
            auto prod = fw.multiply(cnt, cnt);
            // for(int j = i; j <= i + len - 1; j++) {
            //     prod[v[j]] = 1;
            // }
            for(auto [x, y] : prod) if(y && x >= k) return true;
        }
        return false;
    };

    int lo = 1, hi = n, best = -1;
    while(lo <= hi) {
        int mid = lo + hi >> 1;
        if(f(mid)) {
            best = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout<<best<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // FWHT::Map tmp = {{3, 1}, {4, 1}};
    // FWHT fw(5);
    // auto prod = fw.multiply(tmp, tmp);
    // for(auto [x, y] : prod) cerr<<x<<" "<<y<<endl; cerr<<endl;

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}