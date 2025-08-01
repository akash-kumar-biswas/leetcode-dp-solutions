class Solution {
public:
    vector<int> dp;

    Solution(){
        dp.resize(46, -1);
    }

    int climbStairs(int n) {
        if(n == 1 || n == 2)
            return n;
        if(dp[n] != -1)
            return dp[n];

        return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};