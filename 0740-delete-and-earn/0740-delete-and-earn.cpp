
class Solution {
public:
    int solve(int i, vector<int>& points, vector<int>& dp) {

        if(i == 0) {
            return points[0];
        }

        if(i < 0) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        int pick = points[i] + solve(i-2, points, dp);

        int notPick = solve(i-1, points, dp);

        return dp[i] = max(pick, notPick);
    }

    int deleteAndEarn(vector<int>& nums) {

        int maxi = *max_element(nums.begin(), nums.end());

        vector<int> points(maxi+1, 0);

        for(int i = 0; i < nums.size(); i++) {
            points[nums[i]] += nums[i];
        }

        vector<int> dp(maxi+1, -1);

        return solve(maxi, points, dp);
    }
};
