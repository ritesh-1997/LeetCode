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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *t1=l1;
        ListNode *t2=l2;
        ListNode *root = new ListNode(0);
        ListNode *x=root;
        int rem = 0;
        while(t1&&t2){
            int val = t1->val+t2->val+rem;
            
            ListNode *temp = new ListNode(val%10);
            x->next = temp;
            x=x->next;
            t1=t1->next;
            t2=t2->next;
            
            if(val>9){
                rem = 1;
            }
            else
                rem=0;
        }
        while(t1){
            int val = t1->val+rem;
            ListNode *temp = new ListNode(val%10);
            x->next = temp;
            x = x->next;
            t1 = t1->next;
            if(val>9)
                rem = 1;
            else
                rem = 0;
        }
        while(t2){
            int val = t2->val +rem;
            ListNode *temp = new ListNode(val%10);
            x->next = temp;
            x = x->next;
            t2 = t2->next;
            if(val>9)
                rem = 1;
            else
                rem =0;
        }
        if(rem){
            ListNode *temp = new ListNode(1);
            x->next = temp;
        }
        return root->next;
        
    }
};