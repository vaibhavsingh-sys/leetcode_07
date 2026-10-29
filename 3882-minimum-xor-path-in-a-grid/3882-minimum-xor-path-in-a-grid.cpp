class Solution {
public:
    int solve(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bitset<1024>>>dp(m, vector<bitset<1024>>(n));
        dp[0][0][grid[0][0]] = 1;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(i == 0 && j == 0)continue;
                bitset<1024>left;
                bitset<1024>up;
                if(i > 0){
                    up = dp[i-1][j];
                }
                if(j > 0){
                    left = dp[i][j-1];
                }
                bitset<1024>combined = up | left;
                for(int xorVal = 0; xorVal < 1024; xorVal++){
                    if(combined[xorVal]){
                        int val = xorVal ^ grid[i][j];
                        dp[i][j][val] = 1;
                    }
                }
            }
        }
        for(int i = 0; i < 1024; i++){
            if(dp[m-1][n-1][i]){
                return i;
            }
        }
        return 0;
    }
    int minCost(vector<vector<int>>& grid) {
        return solve(grid);
    }
};