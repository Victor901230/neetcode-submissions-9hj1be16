class Solution {
    unordered_map<int,vector<int>> preMap;//(課，先修)
    unordered_set<int> visit;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0;i<numCourses;i++){
            preMap[i] = {};
        }
        for(auto pre:prerequisites){
            preMap[pre[0]].push_back(pre[1]);
        }

        for(int c=0;c<numCourses;c++){
            if(!dfs(c)) return false;
        }
        return true;
    }

    bool dfs(int course){
        if(visit.count(course)) return false;
        if(preMap[course].empty()) return true;
        visit.insert(course);
        for(auto pre:preMap[course]){
            if(!dfs(pre)) return false;
        }

        //course不產生迴圈
        visit.erase(course);
        preMap[course].clear();
        return true;
    }
};
