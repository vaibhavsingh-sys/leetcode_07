
class Solution {
public:
    int dp[301][5001];

    int solve(vector<int>& coins, int amount, int i){
        if(amount == 0){
            return 1;
        }

        if(i >= coins.size() || amount < 0){
            return 0;
        }

        if(dp[i][amount] != -1){
            return dp[i][amount];
        }

        int take = solve(coins, amount-coins[i], i);
        int skip = solve(coins, amount, i+1);

        return dp[i][amount] = take + skip;
    }

    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return solve(coins, amount, 0);
    }
};
