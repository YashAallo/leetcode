class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       
       int n=arr.size();
        vector<int> copy(arr);

        sort(copy.begin(), copy.end());

        map<int, int> mapRank;

        int rank = 1;
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && copy[i] == copy[i + 1])
                continue;

            mapRank[copy[i]] = rank;
            rank++;
        }

        vector<int> ans;

        for (auto num : arr) {

            ans.push_back(mapRank[num]);
        }

        return ans;
    }
};