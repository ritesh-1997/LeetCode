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
    
    void reorderList(ListNode* head) {
        vector<ListNode *> v;
        ListNode *root = head;

        while(root){
            v.push_back(root);
            root = root->next;
        }

        ListNode * root1 = head, *root2=head->next;
        int i =0, j=v.size()-1;

        while(i<j){
            root1->next = v[j];
            v[j]->next = root2;
            root1 = root2;
            root2 = root2->next;            
            i++;
            j--;
        }
        root1->next = NULL;
    }
};