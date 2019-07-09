class Solution {
public:
    
    double calPow(double x, int n) {
        if (n == 1) return x;
        if (n == -1) {
            return 1.0 / x;
        }
        if (n % 2 == 0) {
            double t = calPow(x, n / 2);
            return t * t;
        } else {
            double t = calPow(x, n / 2);
            double t2;
            if (n > 0) t2 = calPow(x, n / 2 + 1);
            else t2 = calPow(x, n / 2 - 1);
            return t * t2;
        }
    }
    
    
    double myPow(double x, int n) {
        if (n == 0) return 1;
        return calPow(x, n);
    }
};