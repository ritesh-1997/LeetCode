/**
 * Definition: Given the head of a linked list,
 * rotate the list to the right by k places.
 *
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || k == 0)
        {
            return head;
        }
        int len = 0;
        ListNode *list = head, *nextNode, *lastNode;

        while (list->next)
        {
            list = list->next;
            len++;
        }
        // making a circular ll
        list->next = head;
        int rem = len - k % (len + 1);

        list = head;

        while (rem)
        {
            rem--;
            list = list->next;
        }
        nextNode = list->next;
        list->next = NULL;

        return nextNode;
    }
};