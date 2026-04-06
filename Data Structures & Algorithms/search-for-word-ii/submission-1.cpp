class Trie{
public:
    Trie * children[26];
    int idx;
    int refs;

    Trie(){
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
        idx = -1;
        refs=0;
    }

    void addWord(const string& word,int i){
        Trie* cur = this;
        for(char c:word){
            int id = c-'a';
            if(!cur->children[id]) cur->children[id] = new Trie();
            cur = cur->children[id];
            cur->refs++;
        }
        cur->idx = i;
    }
};

class Solution {
    vector<string> res;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root = new Trie();
        for(int i=0;i<words.size();i++){
            root->addWord(words[i],i);
        }

        for(int r=0;r<board.size();r++){
            for(int c=0;c<board[0].size();c++){
                dfs(board,root,r,c,words);
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& board,Trie* node,int r,int c, vector<string>& words){
        if(r<0||c<0||r>=board.size()||c>=board[0].size()||board[r][c]=='*'||!node->children[board[r][c]-'a']){
            return;
        }
        char temp = board[r][c];
        board[r][c]='*';
        Trie* prev = node;
        node = node->children[temp-'a'];

        if(node->idx!=-1){
            res.push_back(words[node->idx]);
            node->idx = -1;
            node->refs--;
            if(!node->refs){
                prev->children[temp-'a']=nullptr;
                node = nullptr;
                board[r][c]=temp;
                return;
            }
        }
        dfs(board,node,r+1,c,words);
        dfs(board,node,r,c+1,words);
        dfs(board,node,r-1,c,words);
        dfs(board,node,r,c-1,words);
        board[r][c]=temp;
    }
};
