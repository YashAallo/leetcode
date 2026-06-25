class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();

        vector<int> v;

        for (int i = 0; i < n; i++) {
            if (nums[i] == target)
                v.push_back(i);
        }

        int ans = 0;
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                

               

                auto low = lower_bound(v.begin(), v.end(), l);
                auto up = upper_bound(v.begin(), v.end(), r);

                int count = up - low;
                int len = r - l + 1;

                if (2 * count > len)
                    ans++;
            }
        }

        return ans;
    }
};