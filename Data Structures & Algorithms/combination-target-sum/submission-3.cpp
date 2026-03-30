class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(nums,0,target,path,res);
        return res;
    }

    void dfs(vector<int>& nums,int i,int target,vector<int>& path,vector<vector<int>>& res){
        if(target==0){
            res.push_back(path);
            return;
        }
        if(target<0||i>=nums.size()) return;
        path.push_back(nums[i]);
        dfs(nums,i,target-nums[i],path,res);//可以重複選
        path.pop_back();
        dfs(nums,i+1,target,path,res);
    }
};
