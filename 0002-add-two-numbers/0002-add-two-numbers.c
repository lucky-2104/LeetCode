
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int carry=0;

    struct ListNode * head = NULL,*tail = NULL;

    while (l1 != NULL && l2 != NULL)
    {
        struct ListNode * n = (struct ListNode *)malloc(sizeof(struct ListNode));
        int data = l1->val + l2->val+carry;
        carry = 0;
        if (data >= 10)
        {
            data = data - 10;
            carry = 1;
        }
        // for the third list
        n->val = data; 
        if (head == NULL && tail == NULL)
        {
            head = n ; tail = n;
            n->next = NULL;
        }
        else
        {
            n->next = NULL;
            tail->next = n;
            tail = n;
        }
        // for 1 and 2 list
        l1 = l1->next; l2 = l2->next;
    }
    while (l1 != NULL)
    {
        struct ListNode * n = (struct ListNode *)malloc(sizeof(struct ListNode));

        int data = l1->val + carry;
        carry = 0;
        if (data >= 10)
        {
            data = data - 10;
            carry = 1;
        }
        n->val = data;
        n->next = NULL;
        tail->next = n;
        tail = n;

        l1=l1->next;
    }
    while (l2 != NULL)
    {
        struct ListNode * n = (struct ListNode *)malloc(sizeof(struct ListNode));

        int data = l2->val + carry;
        carry = 0;
        if (data >= 10)
        {
            data = data - 10;
            carry = 1;
        }
        n->val =data;
        n->next = NULL;
        tail->next = n;
        tail = n;
        l2=l2->next;
    }

    if (carry != 0)
    {
        struct ListNode * n = (struct ListNode *)malloc(sizeof(struct ListNode));
        n->val = carry;
        n->next = NULL;
        tail->next = n;
        tail = n;    
    }
    return head;
}