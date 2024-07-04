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
    ListNode* mergeNodes(ListNode* head) {

        ListNode * walk = head;

        ListNode* new_head = NULL;
        ListNode* tail = NULL;
        while(walk->next != NULL)
        {
            ListNode* delete_Node = walk;
            if(walk->val == 0){
                ListNode * new_node = new ListNode(0);
                if(new_head == NULL and tail == NULL)
                {
                    new_head = new_node;
                    tail = new_head;
                }
                else{
                    tail->next = new_node;
                    tail = tail->next;
                }
            }
            else
            tail->val = tail->val+walk->val;
            walk = walk->next;
            delete delete_Node;
        }
        // delete tail;
        return new_head;
        
    }
};