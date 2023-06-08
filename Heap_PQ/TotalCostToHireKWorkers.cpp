/**
 * You are given a 0-indexed integer array costs where costs[i] is the cost of hiring the ith worker.
 *
 * You are also given two integers k and candidates. We want to hire exactly k workers according
 *  to the following rules:
 *
 * You will run k sessions and hire exactly one worker in each session.
 *
 * In each hiring session, choose the worker with the lowest cost from either the first candidates
 * workers or the last candidates workers. Break the tie by the smallest index.
 *
 * For example, if costs = [3,2,7,7,1,2] and candidates = 2, then in the first hiring session,
 * we will choose the 4th worker because they have the lowest cost [3,2,7,7,1,2].
 *
 * In the second hiring session, we will choose 1st worker because they have the same lowest
 * cost as 4th worker but they have the smallest index [3,2,7,7,2]. Please note that the indexing may
 * be changed in the process.
 *
 * If there are fewer than candidates workers remaining, choose the worker with the lowest cost among
 * them. Break the tie by the smallest index.
 *
 * A worker can only be chosen once.
 *
 * Return the total cost to hire exactly k workers.
 */

class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        long long ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        int n = costs.size();
        int i = 0, j = n - 1;
        // store min of n or candidates
        while (i < n && i < candidates)
        {
            pq1.push(costs[i++]);
        }
        // make suffix queue to get min element from suffix
        while (j >= i && j >= n - candidates)
        {
            pq2.push(costs[j--]);
        }
        while (k--)
        {
            // both not empty
            if (!pq1.empty() && !pq2.empty())
            {
                if (pq1.top() < pq2.top())
                {
                    ans += pq1.top();
                    pq1.pop();
                    if (i <= j)
                    {
                        pq1.push(costs[i++]);
                    }
                }
                else if (pq1.top() > pq2.top())
                {
                    ans += pq2.top();
                    pq2.pop();
                    if (i <= j)
                    {
                        pq2.push(costs[j--]);
                    }
                }

                else
                { // equal cost of hiring from both q then hire from first
                    ans += pq1.top();
                    pq1.pop();
                    if (i <= j)
                    {
                        pq1.push(costs[i++]);
                    }
                }
            }
            // pq1 is empty
            else if (pq1.empty())
            {
                ans += pq2.top();
                pq2.pop();
                if (i <= j)
                {
                    pq2.push(costs[j--]);
                }
            }
            // pq2 is empty
            else
            {
                ans += pq1.top();
                pq1.pop();
                if (i <= j)
                {
                    pq1.push(costs[i++]);
                }
            }
        }
        return ans;
    }
};