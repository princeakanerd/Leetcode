class Solution {
public:
    vector<int> sieve(int n){
        vector<int> spf(n + 1, INT_MAX) ;

        for(long long i = 2 ; i <= n ; i++ ){
            if(spf[i] == INT_MAX){
                spf[i] = i ;
                for(long long j = i * i ; j <= n ; j += i ){
                    spf[j] = min(1ll * spf[j], i) ;
                }
            }
        }
        return spf ;
    }
    int minJumps(vector<int>& nums) {
        int n = nums.size() ;
        int maxi = 0 ;

        for(auto it : nums) maxi = max(it, maxi) ;
        vector<int> spf = sieve(maxi + 1) ;
        //  prime -> indices of number that are its multiple
        vector<vector<int>> bucket(maxi + 1);
        for(int i = 0 ; i < n ;i++ ){
            int num = nums[i] ;

            while(num > 1){
                int fact = spf[num] ;
                bucket[fact].push_back(i) ;
                while(num % fact == 0) num /= fact ;
            }
        }

        vector<int> visited(n, false) ;
        visited[0] = true ;
        queue<int> q ;
        q.push(0) ;

        int steps = 0 ;

        while(!q.empty()){
            int qs = q.size() ;
            
            for(int i = 0 ; i < qs ; i++ ){
                int idx = q.front() ;
                q.pop(); 
                if(idx == n - 1) return steps ;
                int num = nums[idx] ;

                if(idx < n - 1 && !visited[idx + 1]){
                    visited[idx + 1] = true ;
                    q.push(idx + 1) ;
                }

                if(idx > 0 && !visited[idx - 1]){
                    visited[idx - 1] = true ;
                    q.push(idx - 1) ;
                }
                if(spf[num] == num){
                    for(int j : bucket[num]){
                        if(!visited[j]){
                            visited[j] = true ;
                            q.push(j) ;
                        }
                       
                    }
                    bucket[num].clear() ;
                }
            }
            steps ++ ;
        }


        return steps ;
       
    }
};