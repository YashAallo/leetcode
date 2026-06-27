class Solution {
public:
    int maximumLength(vector<int>& nums) {

        map<int, int> freq;

        for (auto it : nums) {
            freq[it]++;
        }

        int maxi = 1;
        for (int it : nums) {
            int count = 0;

            long long num = it;

            while (freq[num] >= 2 && num != 1) {
                count++;

                if (num > sqrt(LLONG_MAX))
                   {
                     
                     break;
                   }

                num *= num;
            }

            if (freq[num] == 1) {
                count = 2 * count + 1;
                maxi = max(maxi, count);
            } else if (num != it) {
                count = 2 * (count - 1) + 1;
                maxi = max(maxi, count);
            }
        }

        int val = freq[1];

        maxi = (val % 2 != 0) ? max(maxi, val) : max(maxi, val - 1);

        return maxi;
    }
};