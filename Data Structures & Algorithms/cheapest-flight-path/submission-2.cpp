class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        vector<vector<int>> dist(n,vector<int>(n+2,INT_MAX));
        //(起始，中轉)所需的cost
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minHeap;

        for(auto& f:flights){
            adj[f[0]].push_back({f[1],f[2]});
        }
        dist[src][0] = 0;
        minHeap.push({0,src,0});//距離、起始、用站
        while(!minHeap.empty()){
            auto curr = minHeap.top();
            minHeap.pop();
            int dis = curr[0];
            int d1 = curr[1];
            int stop = curr[2];
            
            if(d1==dst) return dis;
            if(stop>=k+1) continue;
            for(auto& pairs:adj[d1]){
                int next = pairs.first;
                int w = pairs.second;
                int nextdis = dis+w;
                int nextStop = stop+1;
                if(nextdis<dist[next][nextStop]){
                    dist[next][nextStop] = nextdis;
                    minHeap.push({nextdis,next,nextStop});
                }
            }
        }
        return -1;
    }
};
