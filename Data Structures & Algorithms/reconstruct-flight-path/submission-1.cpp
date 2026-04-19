class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> adj;
        vector<string> res={"JFK"};
        sort(tickets.begin(),tickets.end());//排序，因為需要回傳字典序最小的，所以對tickets排序
        for(auto& ticket:tickets){
            adj[ticket[0]].push_back(ticket[1]);
        }
        dfs("JFK",res,adj,tickets.size()+1);
        return res;
    }

    bool dfs(const string& src,vector<string>&res,unordered_map<string,vector<string>>& adj,int targetLen){
        if(res.size()==targetLen) return true;
        if(adj.find(src)==adj.end()) return false;
        vector<string> temp = adj[src];
        for(int i=0;i<temp.size();i++){
            string v = temp[i];
            adj[src].erase(adj[src].begin()+i);
            res.push_back(v);
            if(dfs(v,res,adj,targetLen)) return true;
            adj[src].insert(adj[src].begin()+i,v);
            res.pop_back();
        }
        return false;
    }
};
