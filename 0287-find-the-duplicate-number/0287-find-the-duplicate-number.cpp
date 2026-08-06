class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = 0;
        int fast = 0;

        do {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
        } while (fast != slow);
        
        
        int slow1=0,slow2=slow;
        while(slow1!=slow2)
        {
            slow1=nums[slow1];
            slow2=nums[slow2];
        }

        return slow1;

        
    }
};