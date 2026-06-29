class Solution {
public:
    int bs(vector<int>& nums, int target, int l, int r) {
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {

        int n = nums.size();
        int l = 0;
        int r = n - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        int pivot = l;
        
        cout<<l;

        int ans = bs(nums, target, 0, pivot - 1);

        if (ans == -1)
            ans = bs(nums, target, pivot, n - 1);

        return ans;
    }
};