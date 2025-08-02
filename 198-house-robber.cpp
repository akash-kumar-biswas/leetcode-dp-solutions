class Solution {
public:
    vector<int> dp;

    int solve(vector<int>& nums, int idx, int n){
        if(idx >= n)
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        int rob = nums[idx] + solve(nums, idx + 2, n);
        int do_not_rob = solve(nums, idx + 1, n);
        
        return dp[idx] = max(rob, do_not_rob);
    }

    int rob(vector<int>& nums) {
        dp.resize(101, -1);
        return solve(nums, 0, nums.size());
    }
};