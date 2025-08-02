class Solution {
public:

    vector<int> dp;

    int solve(vector<int>& nums, int idx, int n){
        dp[idx] = 0;
        dp[idx+1] = nums[idx];

        for(int i = idx + 2; i <= n; i++){
            dp[i] = max(nums[i - 1] + dp[i - 2], dp[i - 1]);
        }
        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0], nums[1]);

        dp.resize(n + 1, -1);
        int include_1st_house = solve(nums, 0, n - 1);

        fill(dp.begin(), dp.end(), -1);
        int exclude_1st_house = solve(nums, 1, n);

        return max(include_1st_house, exclude_1st_house);
    }
};