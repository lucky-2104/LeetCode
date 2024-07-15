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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        unordered_map<int,int>indegree;

        for(int i = 0 ; i < descriptions.size() ; i++)
        {
            indegree[descriptions[i][1]]++;
            indegree[descriptions[i][0]] = indegree[descriptions[i][0]] + 0;
        }

        
        unordered_map<int , TreeNode*> addresses;
        int root_value = -1;
        for(auto x : indegree)
        {
            if(x.second == 0)
            root_value = x.first;
            addresses[x.first] = new TreeNode(x.first);
        }

        for(int i = 0 ; i < descriptions.size() ;i++)
        {
            if(descriptions[i][2] == 1) addresses[descriptions[i][0]]->left = addresses[descriptions[i][1]];
            else addresses[descriptions[i][0]]->right = addresses[descriptions[i][1]];
        }

        TreeNode* root = addresses[root_value];



        return root;



    }
};