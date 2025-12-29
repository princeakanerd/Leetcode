class Solution {
public:
    unordered_map<string, bool> dp ;
    bool f(int i, string &bottom,string & newbottom, map<string,string> &mpp){
        if(bottom.size() == 1) return true ;
        if(i + 1 == bottom.size()){
            string temp = "" ;
            return f(0, newbottom, temp, mpp) ;
        }

        if(i == 0 && dp.count(bottom)){
            return dp[bottom] ;
        }

        string temp ;
        temp.push_back(bottom[i]) ;
        temp.push_back(bottom[i + 1]) ;
        
        bool res = false ;
        
        if(mpp[temp].size()){

            for(auto it : mpp[temp]){
                newbottom.push_back(it);
                res |=f(i + 1, bottom, newbottom, mpp) ;
                newbottom.pop_back() ;
            }
            
        } 

        if(i == 0) dp[bottom] = res ;
        return res ;
        
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        map<string, string> mpp ;

        for(auto it :allowed){
            string temp = it.substr(0, 2) ;
            mpp[temp].push_back(it[2]) ;
        }
        string newbottom = "";
        return f(0, bottom, newbottom, mpp) ;



        
    }
};