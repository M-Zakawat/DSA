class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;  // use long long to avoid overflow on -INT_MIN
        if (exp < 0) {
            x = 1.0 / x;
            exp = -exp;
        }
        
        double result = 1.0;
        double base = x;
        
        while (exp > 0) {
            if (exp & 1) {          // if current bit is 1
                result *= base;
            }
            base *= base;           // square for next bit
            exp >>= 1;              // move to next bit
        }
        
        return result;
    }
};