class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,0,target,path,res);
        return res;
    }

    void backtrack(vector<int>& candidates,int i,int target,vector<int>& path,vector<vector<int>>& res){
        if(target==0){
            res.push_back(path);
            return;
        }
        if(target<0||i>=candidates.size()) return;

        //取前可以重複
        path.push_back(candidates[i]);
        backtrack(candidates,i+1,target-candidates[i],path,res);
        //不取時判斷去重，因為取過才要判斷不要取到一樣
        path.pop_back();
        while(i+1<candidates.size()&&candidates[i]==candidates[i+1]) i++;
        backtrack(candidates,i+1,target,path,res);
    }
};
