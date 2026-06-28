class Solution {
public:
    bool bs(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return false;
    }

    int lower(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    int upper(vector<int>& nums, int target) {

        int n = nums.size();
        int l = 0;
        int r = n;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();
        int first = lower(nums, target);

        if (!bs(nums,target))
            return vector<int>({-1, -1});

        int last = upper(nums, target);

        return {first, last - 1};
    }
};