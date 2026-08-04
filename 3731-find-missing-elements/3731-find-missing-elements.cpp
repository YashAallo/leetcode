class Solution {
    void func(vector<int>& nums, vector<int>& ans, int l, int r) {
        for (int i = l + 1; i < r; i++) {
            ans.push_back(i);
        }
    }

public:
    vector<int> findMissingElements(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n - 1; i++) {
            func(nums, ans, nums[i], nums[i + 1]);
        }
        return ans;
    }
};