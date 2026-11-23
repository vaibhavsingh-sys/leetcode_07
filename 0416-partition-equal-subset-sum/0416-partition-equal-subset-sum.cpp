class Solution {
public:
    int dp[201][10001];
    bool solve(vector<int>& nums, int x, int i){
        if(x == 0){
            return true;
        }
        if(i >= nums.size()){
            return false;
        }
        if(x < 0){
            return false;
        }
        if(dp[i][x] != -1){
            return dp[i][x];
        }
        bool take = solve(nums, x-nums[i], i+1);
        bool skip = solve(nums, x, i+1);
        return dp[i][x] = take || skip;
    }
    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int tot = accumulate(nums.begin(), nums.end(), 0);
        if(tot % 2 != 0){
            return false;
        }
        int x = tot / 2;
        return solve(nums, x, 0);
    }
};