class Solution {

    void power(vector<int>& nums, int i, vector<vector<int>>& list,
               vector<int>& temp) {
        int n = nums.size();

        if (i == n ) {
            list.push_back(temp);
            return;
        }

  
        // take
        temp.push_back(nums[i]);
        power(nums,i+1,list,temp);
        temp.pop_back();

        //not take
        int next=i+1;

        while( next<n && nums[i]==nums[next])
        next++;

        power(nums,next,list,temp);


    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> list;
        vector<int> temp;

        sort(nums.begin(),nums.end());
        power(nums, 0, list, temp);

         return list;
    }
};