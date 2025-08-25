class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res ;
        int n = mat.size() , m = mat[0].size() ;
        bool flip = false ;
        for(int i = 0 ; i < n ;i++ ){
            vector<int> temp ;
            int tempi = i , tempj = 0 ;
            while(tempi >= 0 && tempj < m){
                temp.push_back(mat[tempi][tempj]) ;
                tempi-- ;
                tempj++ ;
            }
            if(i % 2) reverse(temp.begin() , temp.end()) ;
            flip = 1 - flip ;
            for(auto it : temp)res.push_back(it) ;
        }

        for(int j = 1 ; j < m ; j++ ){
            vector<int> temp ;
            int tempi = n - 1 , tempj = j ;
            while(tempi >= 0 && tempj < m){
                temp.push_back(mat[tempi][tempj]) ;
                tempi-- ;
                tempj++ ;
            }
            if(flip) reverse(temp.begin() , temp.end()) ;
            flip = 1 - flip ;
            for(auto it : temp)res.push_back(it) ;
        }

        return res ;
    }
};