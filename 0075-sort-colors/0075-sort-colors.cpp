class Solution {
public:
    void sortColors(vector<int>& nums) {

        vector<int> has(3, 0);

        for (auto num : nums) {
            has[num]++;
        }

        nums.clear();

        for (int i = 0; i < 3; i++) {
            int size = has[i];

            while (size) {
                nums.push_back(i);
                size--;
            }
        }

    }
};