class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& nums, int idx, int prev){
        if(idx == nums.size())
            return 0;
        
        if(dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];

        int take = INT_MIN;
        if(prev == -1 || nums[prev] < nums[idx])
            take = 1 + solve(nums, idx + 1, idx);
        int skip = solve(nums, idx + 1, prev);

        return dp[idx][prev + 1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        dp.resize(nums.size(), vector<int> (nums.size(), -1));

        return solve(nums, 0, -1);
    }
};