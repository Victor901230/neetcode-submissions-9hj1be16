class Solution {
public:
    vector<string> res;
    vector<string> digitToChar = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        string path;
        dfs(digits,path,0);
        return res;
    }

    void dfs(string& digits,string &path,int i){
        if(i>=digits.size()){
            res.push_back(path);
            return;
        }
        string ch = digitToChar[digits[i]-'0'];
        for(int j = 0;j<ch.size();j++){
            path+=ch[j];
            dfs(digits,path,i+1);
            path.pop_back();
        }
    }
};
