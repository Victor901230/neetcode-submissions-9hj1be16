class Trie{
public:
    Trie *children[26];
    bool endOfWord;
    Trie(){
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
        endOfWord = false;
    }
};

class PrefixTree {
    Trie *root; 
public:
    PrefixTree() {
        root = new Trie();
    }
    
    void insert(string word) {
        Trie* cur = root;
        for(char c:word){
            int i = c-'a';
            if(cur->children[i]==nullptr){
                cur->children[i] = new Trie();
            }
            cur=cur->children[i]; 
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        Trie* cur = root;
        for(char c:word){
            int i = c-'a';
            if(cur->children[i]==nullptr){
                return false;
            }
            cur=cur->children[i];
        }
        return cur->endOfWord;
    }
    
    bool startsWith(string prefix) {
        Trie* cur = root;
        for(char c:prefix){
            int i = c-'a';
            if(cur->children[i]==nullptr){
                return false;
            }
            cur=cur->children[i];
        }
        return true;
    }
};
