class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        vector<int> distance(n+1,INT_MAX);
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        dfs(k,0,adj,distance);
        int res = *max_element(distance.begin()+1,distance.end());//跳過第一個
        return res==INT_MAX?-1:res;
    }

    void dfs(int node,int time,unordered_map<int,vector<pair<int,int>>>& adj,vector<int>& distance){
        if(time>=distance[node]) return;
        distance[node] = time;
        for(auto [nei,w]:adj[node]){
            dfs(nei,time+w,adj,distance);
        }
    }
};
