class DSU{
public:
    vector<int> parent,rank;
    
    DSU(int n):parent(n+1),rank(n+1,1){
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int find(int node){
        if(parent[node]!=node){
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }

    bool Union(int u,int v){
        int pu = find(u),pv=find(v);
        if(pu==pv) return false;
        if(rank[pu]>rank[pv]) swap(pu,pv);
        parent[pu] = pv;
        rank[pv]+=rank[pu];
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        DSU dsu(n);

        vector<array<int,3>> edges;

        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({dist,i,j});
            }
        }
        sort(edges.begin(),edges.end());

        int res = 0;
        for(auto& edge:edges){
            int distance = edge[0];
            int u = edge[1],v = edge[2];
            if(dsu.Union(u,v)){
                res+=distance;
            }
        }
        return res;
    }
};
