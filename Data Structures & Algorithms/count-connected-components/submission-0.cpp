class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        vector<bool> visit(n, false);

        for(const auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int res = 0;
        for(int i = 0; i < n; i++){
            if(!visit[i]){
                dfs(i, adj, visit);
                res++;
            }
            
        }
        return res;
    }

    private:
    void dfs(int node, vector<vector<int>>& adj,vector<bool>& visit ){

        visit[node] = true;
        for(int n: adj[node]){
            if(!visit[n]){
                dfs(n, adj, visit);
            }
        }
    }
};
