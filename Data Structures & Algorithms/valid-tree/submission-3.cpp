class Solution {
    unordered_set<int> visit;
    vector<vector<int>> adj;
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;

        adj.assign(n,vector<int>());
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        if(!dfs(0,-1)) return false;
        return visit.size()==n;//最後判斷所有點都被接上
    }

    bool dfs(int node,int parent){
        if(visit.count(node)) return false;//有環
        visit.insert(node);
        for(auto nei:adj[node]){
            if(nei==parent) continue;
            if(!dfs(nei,node)) return false;
        }
        return true;
    }
};
