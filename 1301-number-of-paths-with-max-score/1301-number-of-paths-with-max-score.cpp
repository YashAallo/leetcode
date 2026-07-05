class Solution {
    const int MOD = 1e9 + 7;

    int row[3] = {0, -1, -1};
    int col[3] = {-1, 0, -1};

    pair<int, int> func(vector<string>& board, int i, int j,
                        vector<vector<pair<int, int>>>& dp) {

        if (i == 0 && j == 0)
            return {0, 1};

        if (dp[i][j] != make_pair(-1, -1))
            return dp[i][j];

        int maxi = INT_MIN;
        int ways = 0;

        for (int k = 0; k < 3; k++) {

            int r = i + row[k];
            int c = j + col[k];

            if (r < 0 || c < 0 || board[r][c] == 'X')
                continue;

            auto [prevScore, prevWays] = func(board, r, c, dp);

            if (prevScore == INT_MIN)
                continue;

            int num = 0;
            if (isdigit(board[r][c]))
                num = board[r][c] - '0';

            int score = prevScore + num;

            if (score > maxi) {
                maxi = score;
                ways = prevWays;
            }
            else if (score == maxi) {
                ways = (ways + prevWays) % MOD;
            }
        }

        return dp[i][j] = {maxi, ways};
    }

public:
    vector<int> pathsWithMaxScore(vector<string>& board) {

        int n = board.size();

        vector<vector<pair<int, int>>> dp(
            n,
            vector<pair<int, int>>(n, {-1, -1}));

        auto [score, ways] = func(board, n - 1, n - 1, dp);

        if (score == INT_MIN)
            return {0, 0};

        return {score, ways};
    }
};