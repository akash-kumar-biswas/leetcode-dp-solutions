class Solution {
public:
    vector<int> dp;

    Solution(){
        dp.resize(1e4 + 1, -1);
    }

    int numSquares(int n) {
        if(n == 0)
            return 0;

        if(dp[n] != -1)
            return dp[n];

        int ans = INT_MAX;
        for(int i = 1; i*i <= n; i++){
            ans = min(ans, 1 + numSquares(n - i*i));
        }
        return dp[n] = ans;
    }
};