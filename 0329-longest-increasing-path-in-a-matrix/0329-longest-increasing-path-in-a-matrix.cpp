class Solution {
public:
    int dp[201][201];
    int solve(int i, int j, vector<vector<int>>& matrix){
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 1;
        if(j-1 >= 0 && matrix[i][j-1] > matrix[i][j]){
            ans = max(ans, 1 + solve(i, j-1, matrix));
        }
        if(i+1 < m && matrix[i+1][j] > matrix[i][j]){
            ans = max(ans, 1 + solve(i+1, j, matrix));
        }
        if(i-1 >= 0 && matrix[i-1][j] > matrix[i][j]){
            ans = max(ans, 1 + solve(i-1, j, matrix));
        }
        if(j+1 < n && matrix[i][j+1] > matrix[i][j]){
            ans = max(ans, 1 + solve(i, j+1, matrix));
        }
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                ans = max(ans, solve(i, j, matrix));
            }
        }
        return ans;
    }
};