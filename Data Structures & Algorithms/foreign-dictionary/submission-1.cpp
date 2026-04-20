class Solution {
    unordered_map<char,unordered_set<char>> adj;//(字，自己後面的字)
    unordered_map<char,bool> visit;
    string res;
public:
    string foreignDictionary(vector<string>& words) {
        //初始化
        for(auto& word:words){
            for(int i=0;i<word.size();i++){
                adj[word[i]];
            }
        }

        for(size_t i = 0;i<words.size()-1;i++){
            const string& w1 = words[i],& w2 = words[i+1];
            //已排序，預設w1優先於w2
            size_t minLen = min(w1.size(),w2.size());
            if(w1.length()>w2.length()&&w1.substr(0,minLen)==w2.substr(0,minLen)){
                return "";
            }
            for(size_t j = 0;j<minLen;j++){
                if(w1[j]!=w2[j]){
                    adj[w1[j]].insert(w2[j]);
                    break;//找到直接結束
                }
            }
        }

        for(const auto& pairs:adj){
            if(dfs(pairs.first)){
                return "";
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }

    //true表有環，false
    bool dfs(char c){
        if(visit.find(c)!=visit.end()){
            return visit[c];
        }
        visit[c] = true;
        for(char next:adj[c]){
            if(dfs(next)){
                return true;
            }
        }
        visit[c] = false;
        res.push_back(c);
        return false;
    }
};
