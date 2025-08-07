class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<vector<int>>& pairs, int idx, int prev){
        if(idx == pairs.size())
            return 0;
        
        if(dp[idx][prev+1] != -1)
            return dp[idx][prev+1];
         
        int take = INT_MIN;
        if(prev == -1 || pairs[prev][1] < pairs[idx][0])
            take = 1 + solve(pairs, idx + 1, idx);
        int skip = solve(pairs, idx + 1, prev);

        return dp[idx][prev + 1] = max(take, skip);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        dp.resize(n, vector<int>(n + 1, -1));
        return solve(pairs, 0, -1);
    }
};