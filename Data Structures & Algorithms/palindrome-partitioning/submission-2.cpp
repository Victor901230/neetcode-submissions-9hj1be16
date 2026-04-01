class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        dfs(path,s,0,0);
        return res;
    }

    void dfs(vector<string>& path,string & s,int i,int j){//開始、結束
        if(i>=s.size()){
            res.push_back(path);
            return;
        }
        if(j==s.size()){
            return;
        }
        if(isPal(s,i,j)){
            path.push_back(s.substr(i,j-i+1));
            dfs(path,s,j+1,j+1);//前面已經確定回文，跳過直接取後面(切斷)
            path.pop_back();
        }
        dfs(path,s,i,j+1);//前面不回文，不切斷j後移
    }

    bool isPal(string& s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
