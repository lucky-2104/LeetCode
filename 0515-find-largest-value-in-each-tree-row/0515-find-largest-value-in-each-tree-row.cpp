class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) return result;
        queue<TreeNode*> bfs;
        bfs.push(root);

        while(!bfs.empty()){
            int sz = bfs.size();
            int maxi = INT_MIN;
            while(sz--){
                TreeNode* temp = bfs.front();
                bfs.pop();
                if(temp->left != nullptr){
                    bfs.push(temp->left);
                }
                if(temp->right != nullptr){
                    bfs.push(temp->right);
                }
                maxi = max(maxi, temp->val);
            }
            result.push_back(maxi);

        }

        return result;
    }
};