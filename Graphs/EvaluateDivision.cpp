class Solution
{
public:
    double dfs(string src, string des, set<string> &visited, map<string, vector<pair<string, double>>> &graph)
    {
        // find the src in graph
        if (graph.find(src) == graph.end())
        {
            return -1.000;
        }
        if (src == des)
        {
            return 1;
        }
        for (auto node : graph[src])
        {
            if (visited.count(node.first))
                continue;
            visited.insert(node.first);
            double res = dfs(node.first, des, visited, graph);
            if (res != -1)
            {
                return res * node.second;
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        map<string, vector<pair<string, double>>> graph;
        int n = values.size();

        for (auto i = 0; i < n; i++)
        {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            graph[a].push_back({b, val});
            graph[b].push_back({a, double(1 / val)});
        }

        vector<double> result;
        for (auto query : queries)
        {
            set<string> visited;
            result.push_back(dfs(query[0], query[1], visited, graph));
        }
        return result;
    }
};