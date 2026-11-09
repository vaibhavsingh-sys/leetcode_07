class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        queue<TreeNode*> que;
        que.push(root);

        int depth = 1;

        while(!que.empty()){
            int n = que.size();

            while(n--){
                TreeNode* node = que.front();
                que.pop();

                // Check if leaf node
                if(node->left == NULL && node->right == NULL){
                    return depth;
                }

                if(node->left != NULL){
                    que.push(node->left);
                }

                if(node->right != NULL){
                    que.push(node->right);
                }
            }

            depth++;
        }

        return depth;
    }
};