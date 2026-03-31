class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> pick(nums.size(),false);
        dfs(nums,pick,res,path);
        return res;
    }

    void dfs(vector<int>& nums,vector<bool>& pick,vector<vector<int>>& res,vector<int>& path){
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(pick[i]==false){
                path.push_back(nums[i]);
                pick[i] = true;
                dfs(nums,pick,res,path);
                //取消
                path.pop_back();
                pick[i] = false;
            }
            //因為for往後走就不須再傳不取的狀況
        }
    }
};
