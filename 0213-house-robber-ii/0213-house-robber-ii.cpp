
class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp) {

        if(i < 0) {
            return 0;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        int pick = nums[i] + solve(i-2, nums, dp);

        int notPick = solve(i-1, nums, dp);

        return dp[i] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) {
            return nums[0];
        }

         vector<int> dp1(n, -1);
        int case1 = solve(n-2, nums, dp1);

         vector<int> temp(nums.begin()+1, nums.end());

        vector<int> dp2(n, -1);
        int case2 = solve(n-2, temp, dp2);

        return max(case1, case2);
    }
};
