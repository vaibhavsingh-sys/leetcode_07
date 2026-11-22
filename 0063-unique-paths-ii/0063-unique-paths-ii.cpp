class Solution {
public:
    int dp[101][101];
    int solve(vector<vector<int>>& obstacleGrid, int i, int j){
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n){
            return 0;
        }
        if(obstacleGrid[i][j] == 1){
            return 0;
        }
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int right = solve(obstacleGrid, i, j + 1);
        int down = solve(obstacleGrid, i+1, j);
        return dp[i][j] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp, -1, sizeof(dp));
        return solve(obstacleGrid, 0, 0);
    }
};