class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int,int> mpp ;
        vector<int> res;
        for(int i = 1 ; i <= 1000 ; i++ ){
            if(i * i * i >= n) break ;
            for(int j = 1 ; j <= i ; j++ ){
                int num = i * i * i +  j * j * j ;
                if(num > n) break ;
                mpp[num] ++ ;
                if(mpp[num] == 2) res.push_back(num) ;
            }
        }
        sort(res.begin(), res.end()) ;
        return res ;
    }
};