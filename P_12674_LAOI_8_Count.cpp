#include <iostream>
#include <vector>
using namespace std;

const long long mod = 998244353;

long long mod_pow(long long base, long long exp, long long modulus) {
    base %= modulus;
    long long result = 1;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<long long> dp(n, 0);
    vector<long long> f(n, 0);
    vector<long long> T1(41, 0);
    vector<long long> T2(41, 0);
    vector<long long> F_sum(41, 0);

    vector<long long> inv_table(41, 0);
    for (int i = 1; i <= 40; i++) {
        inv_table[i] = mod_pow(i, mod - 2, mod);
    }

    long long pre = 1;
    long long inv_pre = 1;

    for (int i = 0; i < n; i++) {
        int a = A[i];
        long long cur = (pre * a) % mod;

        if (i == 0) {
            T2[a] = (T2[a] + 1) % mod;
        } else {
            T1[a] = (T1[a] + dp[i-1]) % mod;
            T2[a] = (T2[a] + (f[i-1] * inv_pre) % mod) % mod;
        }

        dp[i] = (T1[a] + (cur * T2[a]) % mod) % mod;

        if (i == 0) {
            F_sum[a] = (F_sum[a] + 1) % mod;
            f[i] = F_sum[a];
        } else {
            F_sum[a] = (F_sum[a] + f[i-1]) % mod;
            f[i] = F_sum[a];
        }

        pre = cur;
        inv_pre = (inv_pre * inv_table[a]) % mod;
    }

    cout << dp[n-1] % mod << endl;

    return 0;
}