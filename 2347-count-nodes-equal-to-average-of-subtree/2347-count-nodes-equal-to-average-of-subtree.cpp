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
    int sum = 0;
    int ans = 0;
    pair<int,int> f(TreeNode* node , int &result)
    {
        if(node == NULL)
        return {0,0};

        auto[left_sum , left_count] = f(node->left,result);
        auto[right_sum , right_count] = f(node->right,result);

        int curr_sum = node->val + left_sum + right_sum;
        int curr_count = 1 + left_count + right_count;

        if(curr_sum / curr_count == node->val)
        result++;

        return {curr_sum , curr_count};

    }
    int averageOfSubtree(TreeNode* root) {
        int result = 0;
        f(root,result); 
        return result;
    }
};