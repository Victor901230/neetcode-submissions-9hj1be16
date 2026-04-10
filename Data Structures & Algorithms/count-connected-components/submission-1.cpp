class Solution {
    vector<vector<int>> adj;
    unordered_set<int> visit;
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        adj.assign(n,vector<int>());
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int res = 0;
        for(int i=0;i<n;i++){
            if(visit.find(i)==visit.end()){
                dfs(i);
                res++;
            }
        }
        return res;
    }

    bool dfs(int node){
        if(visit.count(node)) return false;
        visit.insert(node);
        for(auto nei:adj[node]){
            if(visit.find(nei)==visit.end()){//找不到
                dfs(nei);
            }
        }
        return true;
    }
};
