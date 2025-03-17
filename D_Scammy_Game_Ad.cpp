#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        // Each test case has n pairs; each pair: (left_op, left_val, right_op, right_val)
        vector<tuple<char, int, char, int>> ops(n);
        for (int i = 0; i < n; i++){
            char lop, rop;
            int lval, rval;
            cin >> lop >> lval >> rop >> rval;
            ops[i] = make_tuple(lop, lval, rop, rval);
        }
        
        // The recurrence is represented as dp(L,R) = A * L + B * R + C.
        // At the very end (after all pairs) we have dp(L,R) = L + R, so:
        long long A = 1, B = 1, C = 0;
        
        // Process pairs in reverse order.
        for (int i = n - 1; i >= 0; i--){
            char lop, rop;
            int lval, rval;
            tie(lop, lval, rop, rval) = ops[i];
            
            // Determine parameters for left gate:
            long long P_left, R0_left;
            if(lop == '+'){
                P_left = 0;
                R0_left = lval;
            } else {  // multiplication operation 'x'
                P_left = lval - 1;
                R0_left = 0;
            }
            
            // Determine parameters for right gate:
            long long P_right, R0_right;
            if(rop == '+'){
                P_right = 0;
                R0_right = rval;
            } else {
                P_right = rval - 1;
                R0_right = 0;
            }
            
            // For this pair:
            // P_pair is the coefficient that multiplies L (from left gate),
            // Q_pair is the coefficient that multiplies R (from right gate),
            // R0_pair is the constant bonus.
            long long P_pair = P_left;
            long long Q_pair = P_right;
            long long R0_pair = R0_left + R0_right;
            
            long long newA, newB, newC;
            // Decide where to allocate the bonus:
            if (A > B) {
                // Allocate all bonus to left lane.
                newA = A * (1 + P_pair);
                newB = B + A * Q_pair;
                newC = A * R0_pair + C;
            } else {
                // Allocate all bonus to right lane.
                newA = A + B * P_pair;
                newB = B * (1 + Q_pair);
                newC = B * R0_pair + C;
            }
            A = newA;
            B = newB;
            C = newC;
        }
        // The initial state is (L, R) = (1, 1)
        long long result = A + B + C;
        cout << result << "\n";
    }
    return 0;
}
