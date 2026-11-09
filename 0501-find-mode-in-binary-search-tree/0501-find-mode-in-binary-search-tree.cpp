class Solution {
public:
    unordered_map<int,int> mp;

    void solve(TreeNode* root){
        if(root == NULL){
            return;
        }

        mp[root->val]++;

        solve(root->left);
        solve(root->right);
    }

    vector<int> findMode(TreeNode* root) {

        solve(root);

        int maxi = 0;

        for(auto it : mp){
            maxi = max(maxi, it.second);
        }

        vector<int> ans;

        for(auto it : mp){
            if(it.second == maxi){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};