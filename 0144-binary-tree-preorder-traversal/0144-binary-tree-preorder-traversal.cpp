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
    vector<int> preorderTraversal(TreeNode* root) {

        if(root == NULL) return{};

        vector<int>ans; 
        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty())
        {
            int level = s.size();
            for(int i = 0 ; i < level ; i++)
            {
                TreeNode* node = s.top();
                s.pop();
                ans.push_back(node->val);

                if(node->right) s.push(node->right);
                if(node->left) s.push(node->left);

            }
        }
        return ans;

        
    }
};