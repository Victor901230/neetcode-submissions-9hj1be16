class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> path;
        sort(nums.begin(),nums.end());
        dfs(nums,0,path);
        return res;
    }

    void dfs(vector<int>& nums,int i,vector<int>& path){
        if(i>=nums.size()){
            res.push_back(path);
            return;
        }

        path.push_back(nums[i]);
        dfs(nums,i+1,path);
        //取消
        path.pop_back();
        //去重
        while(i+1<nums.size()&&nums[i+1]==nums[i]){
            i++;
        }
        dfs(nums,i+1,path);
    }
};
