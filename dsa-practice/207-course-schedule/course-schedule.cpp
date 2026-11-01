class Solution {
private:
bool dfsCheck(vector<vector<int>>& adj, int node, vector<int> &vis, vector<int> &pathVis){
    vis[node] = 1;
    pathVis[node] = 1;

    for(auto it: adj[node]){
        if(!vis[it]){
            if(dfsCheck(adj, it, vis, pathVis) == false) return false;
        }else if(pathVis[it]){
            return false;
        }
    }
    pathVis[node] = 0;
    return true;
}
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>vis(numCourses, 0);
        vector<int>pathVis(numCourses, 0);

        // prerequisites to adj list
        vector<vector<int>> adj(numCourses);
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if(!vis[i]){
                if(dfsCheck(adj, i, vis, pathVis) == false) return false;
            }
        }
        return true;
    }
};