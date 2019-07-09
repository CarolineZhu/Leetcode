class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        if (num == 1 || num == 0) return false;
        for (int i = 1; i <= sqrt(num); i++) {
            if (num % i == 0) {
                if (i == num / i || i == 1) sum += i;
                else sum += i + num / i;
            }
        }
        cout << sum;
        if (sum == num) return true;
        else return false;
    }
};