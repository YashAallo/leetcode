class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         int n=nums.size();
        unordered_map<int, int> mp;
        unordered_map<int, int> pushed;

        
        vector<int> ans;
        for (auto num : nums) {
            mp[num]++;

            if (mp[num] > (n/3)  ) {
                
              pushed[num]=1;
            }
        }

        for(auto [num,val]:pushed )
        {
            // cout<<num<<" ";
            ans.push_back(num);
        }

        return ans;
    }
};