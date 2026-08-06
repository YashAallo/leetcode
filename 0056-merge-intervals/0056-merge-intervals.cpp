class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end(),
             [](auto a, auto b) { return a < b; });

        int start = -1;
        int end = -1;

        for (int i = 0; i < n; i++) {
            if (start == -1) {
                start = intervals[i][0];
                end = intervals[i][1];
            }

            if (end >= intervals[i][0]) {
                  end = max(end, intervals[i][1]);
            } else {

                ans.push_back({start, end});
                start = -1;
                i--;
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};