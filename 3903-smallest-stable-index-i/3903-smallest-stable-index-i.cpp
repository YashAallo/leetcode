class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> maxScore(n);
        vector<int> minScore(n);

        int maxi = 0;
        int mini = 1e9;

        // Prefix maximum
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            maxScore[i] = maxi;
        }

        // Suffix minimum
        for (int i = n - 1; i >= 0; i--) {
            mini = min(mini, nums[i]);
            minScore[i] = mini;
        }

        // Find first stable index
        for (int i = 0; i < n; i++) {
            int val = maxScore[i] - minScore[i];

            if (val <= k)
                return i;
        }

        return -1;
    }
};