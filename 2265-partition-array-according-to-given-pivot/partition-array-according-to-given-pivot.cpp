class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> small, big ;
        int cnt = 0 ;


        for(auto it : nums){
            if(it < pivot) small.push_back(it) ;
            else if(it == pivot) cnt ++ ;
            else big.push_back(it) ;
        }

        vector<int> res;

        for(auto it : small) res.push_back(it) ;
        for(int i = 0 ;i < cnt ;i++ ) res.push_back(pivot) ;
        for(auto it : big) res.push_back(it) ;
        return res;
    }
};