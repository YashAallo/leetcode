class Solution {

    int digit(int num) {
        int ans = 1;
        while (num) {
            int digit = num % 10;
            num /= 10;
            ans *= digit;
        }
        return ans;
    }

public:
    int smallestNumber(int n, int t) {

        while (true) {
            if (digit(n) % t == 0) {
                return n;
            }
            n++;
        }
        return -1;
    }
};