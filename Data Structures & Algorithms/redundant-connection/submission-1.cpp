class Solution {
    int cycleStart;
    vector<bool> visit;
    unordered_set<int> cycle;
    vector<vector<int>> adj;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        visit.resize(n+1,false);
        adj.assign(n+1,vector<int>());
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        cycleStart = -1;
        dfs(1,-1);
        
        //因要回傳edges中最後出現的->由後往前
        for(int i=n-1;n>=0;i--){
            int u = edges[i][0];
            int v = edges[i][1];
            if(cycle.count(u)&&cycle.count(v)){
                return {u,v};
            }
        }
        return {};
    }

    //找到環return true
    bool dfs(int node,int parent){
        if(visit[node]){//有環
            cycleStart = node;
            return true;
        }
        visit[node] = true;
        for(auto nei:adj[node]){
            if(nei==parent) continue;
            if(dfs(nei,node)){//往下走有環
                if(cycleStart!=-1){//有環起點
                    cycle.insert(node);
                }
                if(node==cycleStart){
                    cycleStart=-1;
                }
                return true;
            }
        }
        return false;
    }
};
