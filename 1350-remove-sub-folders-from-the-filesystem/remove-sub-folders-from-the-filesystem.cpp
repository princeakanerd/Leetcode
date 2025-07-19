class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
       sort(folder.begin(), folder.end(),
     [](const string &a, const string &b){
        return a.size() < b.size();
     });

    set<string> st ;
     for(auto it : folder){
        string temp = "" ;
        bool found = false ;
        for(int i = 0 ; i < it.size() ; i ++){
            if(it[i] == '/' && st.find(temp) != st.end()){
                found = true ;
                break ;
            }
            temp.push_back(it[i]) ;
        }
        if(!found) st.insert(temp) ;
     }

     vector<string> ans(st.begin() , st.end()) ;

    
     return ans ;

    
    }
};