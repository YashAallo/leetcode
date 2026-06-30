class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int n = nums.size();

        int l = 0;
        int r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
                return true;

            if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
                l++;
                r--;
            } else if (nums[l] <= nums[mid]) {
                // left half is sorted

                if(target<= nums[mid] && target >= nums[l])
                {
                    r=mid;
                }
                else
                {
                    l=mid+1;
                }


            } else {
                // right half is sorted

                if(target >=nums[mid] && target <= nums[r])
                {
                    l=mid;
                }
                else 
                {
                    r=mid-1;
                }


            }
        }

        cout << l;

        //edge case when l goes outside array
        if(l==n)
        return false;

        return nums[l] == target;
    }
};