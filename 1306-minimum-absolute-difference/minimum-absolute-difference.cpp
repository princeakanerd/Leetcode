class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end()) ;
        int n = arr.size() ;
        vector<vector<int>> res ;
        int mini = INT_MAX ;
        for(int i = 1 ; i < n ;i++ ){
             mini = min(mini, arr[i] - arr[i - 1]) ;
        }


        for(int i = 1 ; i < n ;i++ ){
            if(arr[i] - arr[i - 1] == mini) res.push_back({arr[i - 1], arr[i]}) ;
        }

        return res ;
    }
};