class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string st;
        track(0,0,n,res,st);
        return res;
    }

    void track(int open,int close,int n,vector<string>& res,string& st){
        if(open==n&&close==n){
            res.push_back(st);
            return;
        }
        if(open<n){
            st+='(';
            track(open+1,close,n,res,st);
            st.pop_back();
        }
        if(close<open){
            st+=')';
            track(open,close+1,n,res,st);
            st.pop_back();
        }
    }
};
