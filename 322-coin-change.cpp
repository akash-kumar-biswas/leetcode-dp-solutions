class Solution {
public:

    vector<vector<int>> dp;

    int solve(vector<int>& coins, int amount, int i){
        if(amount == 0)
            return 0;

        if(amount < 0)
            return 1e9;

        if(i >= coins.size())
            return 1e9;
        
        if(dp[i][amount] != -1)
            return dp[i][amount];
        
        int take = 1 + solve(coins, amount - coins[i], i);

        int skip = solve(coins, amount, i + 1);

        return dp[i][amount] = min(take, skip);
    }
    
    int coinChange(vector<int>& coins, int amount) {

        dp.resize(coins.size() + 1, vector<int>(amount + 1, -1));

        int ans = solve(coins, amount, 0);

        return (ans >= 1e9)? -1: ans;
    }
};