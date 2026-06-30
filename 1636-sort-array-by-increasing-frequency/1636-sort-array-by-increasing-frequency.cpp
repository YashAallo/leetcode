class Solution {
    int offset = 100;

public:
    vector<int> frequencySort(vector<int>& nums) {

        int n = nums.size();

        vector<pair<int, int>> freq;

        for (int i = 0; i < 202; i++) {

            freq.push_back({0, i});
        }

        for (auto it : nums) {

            freq[it + 100].first++;
        }

        sort(freq.begin(), freq.end(), [](auto a, auto b) {
            if (a.first == b.first)
                return a.second > b.second;
            else
                return a.first < b.first;
        });

        vector<int> ans;

        for (auto& [count, number] : freq) {

            if (count > 0) {
                while (count) {
                    ans.push_back(number - 100);
                    count--;
                }
            }
        }

        return ans;
    }
};