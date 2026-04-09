class Solution {
    unordered_map<int,vector<int>> preMap;
    unordered_set<int> visit;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        unordered_set<int> cycle;
        for(int i=0;i<numCourses;i++){
            preMap[i]={};
        }

        for(auto pre:prerequisites){
            preMap[pre[0]].push_back(pre[1]);
        }

        for(int c=0;c<numCourses;c++){
            if(!dfs(c,res,cycle)) return {};
        }
        return res;
    }

    bool dfs(int course,vector<int>& res,unordered_set<int>& cycle){
        if(cycle.count(course)) return false;
        if(visit.count(course)) return true;
        
        cycle.insert(course);
        if(preMap.count(course)){
            for(auto pre:preMap[course]){
                if(!dfs(pre,res,cycle)) return false;
            }
        }
        cycle.erase(course);
        visit.insert(course);
        res.push_back(course);
        //topologic : 走過自己這點後加入結果->刪除
        return true;
    }
};
