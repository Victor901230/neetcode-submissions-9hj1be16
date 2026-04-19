class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), node = 0;
        vector<int> dist(n,INT_MAX);
        vector<int> visit(n,false);
        int edge = 0,res=0;  

        while(edge<n-1){
            visit[node] = true;
            int nextnode =-1;
            for(int i=0;i<n;i++){
                if(visit[i]) continue;
                int curdist = abs(points[i][0]-points[node][0])+ abs(points[i][1]-points[node][1]);
                dist[i] = min(dist[i],curdist);
                if(nextnode==-1||dist[i]<dist[nextnode]){
                    nextnode = i;
                }
            }
            res+=dist[nextnode];
            node = nextnode;
            edge++;
        } 
        return res;
    }
};
