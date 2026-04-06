class Trie{
public:
    vector<Trie*> children;
    bool endOfWord;
    Trie():children(26,nullptr), endOfWord(false){}
};

class WordDictionary {
    Trie *root;
public:
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie * cur = root;
        for(char c:word){
            int i = c-'a';
            if(cur->children[i]==nullptr) cur->children[i] = new Trie();
            cur = cur->children[i];
        }
        cur->endOfWord=true;
    }
    
    bool search(string word) {
        return dfs(word,0,root);
    }

    //直接用int i = c-'a';在''會產生負索引，所以須輔助方法dfs紀錄開始索引
    bool dfs(string word,int j,Trie *root){//i開始索引
        Trie * cur = root;
        for(int i = j;i<word.size();i++){
            char c = word[i];
            if(c=='.'){
                for(Trie* child:cur->children){
                    if(child!=nullptr&&dfs(word,i+1,child)){
                        return true;
                    }
                }
                return false;
            }else{
                if(cur->children[c-'a']==nullptr) return false;
                cur = cur->children[c-'a'];
            }
        }
        return cur->endOfWord;
    }
};
