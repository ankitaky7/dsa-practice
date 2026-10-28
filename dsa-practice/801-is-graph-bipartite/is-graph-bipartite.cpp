class Solution {
private:
    bool check(vector<vector<int>>& graph, int v, int start, vector<int> &color) {
        queue<int>q;
        q.push(start);
        color[start] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            // graph[node] direct neighbors deta hai (same as adj[node])
            for(auto it: graph[node]){
                // Agar neighbor unvisited/uncolored hai
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                    // agr adjacent node ka color same hai 
                }else if(color[it] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();

        vector<int>color(v, -1);

        for (int i = 0; i < v; i++) {
            if (color[i] == -1) {
                if (check(graph, v, i, color) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};