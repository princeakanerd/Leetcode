struct Node{
        Node* links[26] ;
        
        bool flag = false ;
     
        bool containsKey(char ch){
            return links[ch - 'a'] != nullptr ;
        }

        void makeLink(char ch , Node* node){
            links[ch - 'a'] = node ;
        }

        Node* get(char ch){
            return links[ch - 'a'] ;
        }

        void setEnd(){
            flag = true ;
        }

        bool isEnd(){
            return flag ;
        }
    };


class Trie {

public:

Node* root ;
    Trie() {
        root = new Node() ;
    }
    
    void insert(string word) {
        Node* node = root ;

        for(int i = 0 ; i < word.length() ; i++ ){
            if(!node->containsKey(word[i])){
                node->makeLink(word[i] , new Node()) ;
            }
            node = node->get(word[i]) ;
        }
        node->flag = true ;
    }
    
    bool search(string word) {
        Node* node = root ;

        for(int i = 0 ;i < word.size(); i++ ){
            if(!node -> containsKey(word[i])) return false ;
            node = node -> get(word[i]) ;
        }

        return node -> flag ;
    }
    
    bool startsWith(string prefix) {
        Node* node = root ;

        for(int i = 0 ;i < prefix.size(); i++ ){
            if(!node -> containsKey(prefix[i])) return false ;
            node = node -> get(prefix[i]) ;
        }

        return true ;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */