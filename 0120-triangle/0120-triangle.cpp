
class Solution {
public:
    int dp[201][201];
    bool vis[201][201];

    int solve(vector<vector<int>>& triangle, int i, int j){
        int n = triangle.size();

        if(i == n-1){
            return triangle[i][j];
        }

        if(vis[i][j]){
            return dp[i][j];
        }

        vis[i][j] = true;

        int down = solve(triangle, i+1, j);
        int diagonal = solve(triangle, i+1, j+1);

        return dp[i][j] = triangle[i][j] + min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        memset(vis, false, sizeof(vis));
        return solve(triangle, 0, 0);
    }
};
