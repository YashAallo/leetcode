class Solution {
    int row[3] = {0, -1, -1}; // 0,-1  -1,0  -1,-1
    int col[3] = {-1, 0, -1}; // 0,-1  -1,0  -1,-1

    int func(vector<string>& board, int i, int j, vector<vector<int>>& dp) {
        if (i == 0 && j == 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int maxi = INT_MIN;
        for (int k = 0; k < 3; k++) {
            int r = i + row[k];
            int c = j + col[k];

            if (r >= 0 && c >= 0 && board[r][c] != 'X') {
                int num = 0;

                if (r != 0 || c != 0)
                    num = board[r][c] - '0';

                maxi = max(maxi, num + func(board, r, c, dp));
            }
        }

        long long mod = 1e9 + 7;
        return dp[i][j] = maxi % mod;
    }

    int path(vector<string>& board, int i, int j, int target,
             vector<vector<vector<int>>>& dp) {

        if (target < 0)
            return 0;

        if (i == 0 && j == 0) {
            if (target == 0)
                return 1;
        }

        if (dp[i][j][target] != -1)
            return dp[i][j][target];

        int sum = 0;
        for (int k = 0; k < 3; k++) {
            int r = i + row[k];
            int c = j + col[k];

            if (r >= 0 && c >= 0 && board[r][c] != 'X') {
                int num = 0;

                if (r != 0 || c != 0)
                    num = board[r][c] - '0';

                sum += path(board, r, c, target - num, dp);
            }
        }

        return dp[i][j][target] = sum;
    }

public:
    vector<int> pathsWithMaxScore(vector<string>& board) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> dp1(n + 1, vector<int>(m + 1, -1));

        int maxi = func(board, n - 1, m - 1, dp1);
        maxi = max(maxi, 0);

        vector<vector<vector<int>>> dp2(
            n, vector<vector<int>>(m, vector<int>(maxi + 1, -1)));

        int validPath = path(board, n - 1, m - 1, maxi, dp2);

        return {maxi, validPath};
    }
};