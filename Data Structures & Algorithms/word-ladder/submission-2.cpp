class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(),wordList.end());
        int res = 0;
        if(words.find(endWord)==words.end()||beginWord==endWord) return 0;
        queue<string> que;
        que.push(beginWord);
        while(!que.empty()){
            int len = que.size();
            res++;
            for(int i=0;i<len;i++){
                string node = que.front();
                que.pop();
                if(node==endWord) return res;
                for(int j=0;j<node.size();j++){
                    char original = node[j];
                    for(char c='a';c<='z';c++){
                        if(c==original) continue;
                        node[j] = c;
                        if(words.find(node)!=words.end()){
                            que.push(node);
                            words.erase(node);
                        }
                    }
                    node[j] = original;
                }
            }
        }
        return 0;
    }
};
