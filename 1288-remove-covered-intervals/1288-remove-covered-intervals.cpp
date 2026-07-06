class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        int n=intervals.size();

        sort(intervals.begin(), intervals.end(), [](auto a, auto b) {
            if (a[0] == b[0])
                return a[1] > b[1];

            return a[0] < b[0];
        });

        int start = intervals[0][0];
        int end = intervals[0][1];
        int count = 0;
        for (auto interval : intervals) {

            if (start <= interval[0] && end >= interval[1]) {
                count++;
            } else if (end <= interval[0]) {
                start = interval[0];
                end = interval[1];
            } else {

                end = interval[1];
            }
        }
        return n-(count-1);
    }
};