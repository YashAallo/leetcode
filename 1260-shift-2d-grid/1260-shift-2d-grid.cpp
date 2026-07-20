class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < (n * m); i++) {
            int row = i / n;
            int col = i % n;

            int shiftedRow = ((i + k) / n)%m;
            int shiftedCol = (i + k) % n;

            ans[shiftedRow][shiftedCol] = grid[row][col];
        }

        return ans;
    }
};