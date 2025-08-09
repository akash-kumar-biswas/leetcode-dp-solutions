class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& coins, int amount, int i){
        if(amount == 0)
            return 1;
        if(amount < 0 || i >= coins.size())
            return 0;
        
        if(dp[amount][i] != -1)
            return dp[amount][i];

        int take = solve(coins, amount - coins[i], i);
        int skip = solve(coins, amount, i + 1);

        return dp[amount][i] = take + skip;
    }

    int change(int amount, vector<int>& coins) {
        dp.resize(amount + 1, vector<int>(coins.size() + 1, -1));

        return solve(coins, amount, 0);
    }
};