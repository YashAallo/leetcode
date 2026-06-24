class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        vector<int> has;

        for(int i=0;i<n;i++)
        {
            has.push_back(i);;
        }

        int maxi=1;
        int ind=0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j ]+1) {
                    dp[i] = dp[j] + 1;
                    has[i]=j;

                }
            }

            if(dp[i]>maxi)
            {
                maxi=dp[i];
                ind=i;
            }
        }

        vector<int> v;

        while(has[ind]!=ind)
        {
            v.push_back(nums[ind]);
            ind=has[ind];
        }

        v.push_back(nums[ind]);

        reverse(v.begin(),v.end());

        return v;
    }
};