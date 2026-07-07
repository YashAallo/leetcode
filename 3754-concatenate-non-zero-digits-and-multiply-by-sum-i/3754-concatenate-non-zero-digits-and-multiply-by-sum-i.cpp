class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long place = 1;
        int sum = 0;

        while (n) {
            int d = n % 10;
            if (d != 0) {
                x += 1LL * d * place;
                place *= 10;
                sum += d;
            }
            n /= 10;
        }

        return x * sum;
    }
};