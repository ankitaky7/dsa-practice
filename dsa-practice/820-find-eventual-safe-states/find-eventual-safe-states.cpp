class Solution {
private:
    bool dfs(vector<vector<int>>& graph, vector<int> &vis, vector<int> &pathVis, vector<int> &check,
             int node) {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        for (auto it : graph[node]) {
            if (!vis[it]) {
                if (dfs(graph, vis, pathVis, check, it) == true) {
                    check[node] = 0;
                    return true;
                }
            } else if (pathVis[it]) {
                check[node] = 0;
                return true;
            }
        }
        pathVis[node] = 0;
        check[node] = 1;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();

        vector<int>vis(v, 0);
        vector<int>pathVis(v, 0);
        vector<int>check(v, 0);
        vector<int> ans;

        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                dfs(graph, vis, pathVis, check, i);
            }
        }

        for (int i = 0; i < v; i++) {
            if (check[i] == 1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};