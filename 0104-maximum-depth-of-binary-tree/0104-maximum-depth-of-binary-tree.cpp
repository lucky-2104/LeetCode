/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int f(TreeNode* root)
    {
        if(root == NULL)
        return 0;

        return 1+ max(f(root->left) , f(root->right));
    }
    int maxDepth(TreeNode* root) {

        return f(root);

        if(root == NULL) return 0;

        queue<TreeNode*> q;
        q.push(root);

        int level = 0;
        while(!q.empty())
        {
            int len = q.size();

            for(int i = 0 ; i < len ; i++){

                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            level++;
        }
        return level;
        
    }
};