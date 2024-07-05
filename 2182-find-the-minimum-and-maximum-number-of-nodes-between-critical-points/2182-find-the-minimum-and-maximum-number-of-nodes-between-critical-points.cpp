/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int> diff_head;

        int count = 2;
        int prev_val = head->val;
        ListNode* walk = head->next;
        while(walk->next != NULL)
        {
            int next_val = walk->next->val;

            if((prev_val > walk->val and walk->val < next_val) or (prev_val < walk->val and next_val < walk->val) )
            diff_head.push_back(count);

            count++;
            prev_val = walk->val;
            walk = walk->next;
        }

 

        vector<int> diff = {-1,-1};
        int n = diff_head.size();
        if(n <= 1) return diff;       
        
        int min_diff = INT_MAX;
        for(int i = 0 ; i < n-1 ; i++) 
        {
            min_diff = min(min_diff , diff_head[i+1] - diff_head[i]);
        }

        diff[0] = min_diff;
        diff[1] = diff_head[n-1] - diff_head[0];

        return diff;

        

        
    }
};