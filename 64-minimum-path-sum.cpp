const int INF = 1e9;

class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(vector<vector<int>>& grid, int i, int j, int n, int m){
        if(i >= n || j >= m){
            return INF;
        }

        if(i == n-1 && j == m-1)
            return grid[i][j];

        if(dp[i][j] != -1)
            return dp[i][j];

        int right = grid[i][j] + solve(grid, i, j + 1, n, m);
        int down = grid[i][j] + solve(grid, i + 1, j, n, m);

        return dp[i][j] = min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        dp.assign(n + 1, vector<int> (m + 1, -1));
        return solve(grid, 0, 0, n, m);
    }
};