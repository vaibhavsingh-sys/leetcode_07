class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == NULL) return ans;

        queue<TreeNode*> que;
        que.push(root);

        bool leftToRight = true;

        while(!que.empty()) {
            int size = que.size();
            vector<int> level;

            for(int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();

                level.push_back(node->val);

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }

            if(!leftToRight) {
                reverse(level.begin(), level.end());
            }

            ans.push_back(level);

            leftToRight = !leftToRight;
        }

        return ans;
    }
};