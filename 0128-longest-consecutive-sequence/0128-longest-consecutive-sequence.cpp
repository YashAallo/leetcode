class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> s(nums.begin(), nums.end());

        int maxi = 0;

        for (int it : s) {

            if ( s.find(it - 1) != s.end())
                continue;

            int num = it;
            int count = 1;

            while (s.find(num + 1) != s.end()) {
                num++;
                count++;
            }

            maxi = max(maxi, count);
        }

        return maxi;
    }
};