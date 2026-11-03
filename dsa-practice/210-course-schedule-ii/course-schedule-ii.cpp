class Solution {
private:
    bool dfs(vector<vector<int>>& prerequisites, vector<int>& vis, int node,
             vector<vector<int>>& adj, stack<int>& st, vector<int> &pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if(dfs(prerequisites, vis, it, adj, st, pathVis) == false) return false;
            }else if(pathVis[it]){
                return false;
            }
        }
        st.push(node);
        pathVis[node] = 0;
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        stack<int> st;

        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if(dfs(prerequisites, vis, i, adj, st, pathVis) == false) return {};
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            ans.push_back(node);
        }
        return ans;
    }
};