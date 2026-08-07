class Solution {
public:
    int majorityElement(vector<int>& nums) {

       unordered_map<int,int> mp;
       
         int max=0;
         int ans;
       for(auto num:nums)
       {
             mp[num]++;

             if(mp[num]>=max)
             {
            max=mp[num];
            ans=num;
             }
       }

       
       return ans;

        
    }
};