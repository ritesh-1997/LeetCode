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

/**
 * You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 *
 * Merge all the linked-lists into one sorted linked-list and return it.
 */

class cmp
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int k = lists.size();
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        for (int i = 0; i < k; i++)
        {
            if (lists[i])
            {
                pq.push(lists[i]);
            }
        }

        ListNode *head = NULL, *tail = NULL;
        while (!pq.empty())
        {
            auto temp = pq.top();
            pq.pop();
            if (head == NULL)
            {
                head = temp;
                tail = temp;
                if (temp->next != NULL)
                {
                    pq.push(temp->next);
                }
            }
            else
            {
                tail->next = temp;
                tail = tail->next;
                if (temp->next != NULL)
                {
                    pq.push(temp->next);
                }
            }
        }
        return head;
    }
};