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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(root == NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty())
        {
            int num = q.size();
            vector<int> temp;
            for(int i = 0 ; i < num ; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(temp);
        }

        for(int i = 0 ; i < ans.size();i++)
        {
            if(i%2 == 1)
            reverse(ans[i].begin() , ans[i].end());
        }
        return ans;
        
    }
};