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
        int n = nums.size();

        if(n == 1)
            return nums[0];

        dp.resize(101, -1);
        int include_1st_house = solve(nums, 0, n - 1);

        fill(dp.begin(), dp.end(), -1);
        int exclude_1st_house = solve(nums, 1, n);

        return max(include_1st_house, exclude_1st_house);
    }
};