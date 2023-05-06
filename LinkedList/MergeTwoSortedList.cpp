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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * temp, *head1 = list1, *head2 = list2,*head1_prev = NULL;
        if(list1==NULL)
            return list2;
        if(list2==NULL)
            return list1;
        if(list1->val<list2->val){
            temp = list1;
            temp->next = mergeTwoLists(list1->next,list2);
        }
        else{
            temp = list2;
            temp->next = mergeTwoLists(list1,list2->next);
        }
        return temp;
    }
};