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

        map<int,int>indegree;

        for(int i = 0 ; i < descriptions.size() ; i++)
        {
            indegree[descriptions[i][1]]++;
            indegree[descriptions[i][0]] = indegree[descriptions[i][0]] + 0;
        }

        
        map<int , TreeNode*> addresses;
        int root_value = -1;
        for(auto x : indegree)
        {
            if(x.second == 0)
            root_value = x.first;
            addresses[x.first] = new TreeNode(x.first);
        }

        for(int i = 0 ; i < descriptions.size() ;i++)
        {
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            int choose = descriptions[i][2];

            if(choose == 1) addresses[parent]->left = addresses[child];
            else addresses[parent]->right = addresses[child];
        }

        TreeNode* root = addresses[root_value];



        return root;



    }
};