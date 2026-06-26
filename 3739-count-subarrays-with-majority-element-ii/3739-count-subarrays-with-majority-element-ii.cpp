class Solution {
public:
    long long sort(vector<int>& pre, int low, int mid, int high) {

        int i = low;
        int j = mid;

        long long count = 0;

        while (i < mid && j < high) {
            if (pre[i] < pre[j]) {
                count += (high - j);
                i++;
            } else {
                j++;
            }
        }

        i = low;
        j = mid;

        vector<int> temp;

        while (i < mid && j < high) {
            if (pre[i] <= pre[j])
                temp.push_back(pre[i++]);
            else
                temp.push_back(pre[j++]);
        }

        while (i < mid)
            temp.push_back(pre[i++]);

        while (j < high)
            temp.push_back(pre[j++]);

        for (int k = low; k < high; k++)
            pre[k] = temp[k - low];

        return count;
    }

    long long merge(vector<int>& pre, int low, int high) {

        if (high - low <= 1)
            return 0;

        int mid = low + (high - low) / 2;

        long long count = 0;

        count += merge(pre, low, mid);
        count += merge(pre, mid, high);

        count += sort(pre, low, mid, high);

        return count;
    }

    long long countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();

        vector<int> pre(n + 1, 0);

        for (auto &x : nums)
            x = (x == target ? 1 : -1);

        for (int i = 1; i <= n; i++)
            pre[i] = pre[i - 1] + nums[i - 1];

        return merge(pre, 0, n + 1);
    }
};