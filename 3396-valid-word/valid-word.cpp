class Solution {
public:
    bool isvalid(char c){
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') ;
    }
    bool isValid(string word) {
        int conso = 0 , vows = 0 ;
        set<char> vow = {'a', 'e', 'i' ,'o' ,'u' , 'A' , 'E' , 'I' , 'O' , 'U'} ;
        
        if(word.size() < 3) return false ;
        for(auto it : word){
            if(!isvalid(it)) return false ;
            if(vow.find(it) != vow.end()) vows++ ;
            else if(it < '0' || it > '9') conso ++ ;
        }

        if(!vows || !conso) return false ;

        return true ;
    }
};