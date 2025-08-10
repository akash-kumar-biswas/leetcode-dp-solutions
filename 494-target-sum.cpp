class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& nums, int target, int i){
        if(target == 0 && i == nums.size())
            return 1;

        if(i >= nums.size())
            return 0;
        
        if(dp[i][2000 - target] != -1)
            return dp[i][2000 - target];

        int take_pos = solve(nums, target - nums[i], i + 1);
        int take_neg = solve(nums, target + nums[i], i + 1);

        return dp[i][2000 - target] = take_pos + take_neg;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        dp.assign(nums.size(), vector<int>(4*1000 + 1, -1));

        return solve(nums, target, 0);
    }
};