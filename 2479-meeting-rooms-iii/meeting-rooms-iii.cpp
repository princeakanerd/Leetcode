class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        long long ans = -1 ;
        sort(meetings.begin() , meetings.end()) ;
        priority_queue<long long, vector<long long> , greater<long long>> free ;
        priority_queue<pair<long long ,long long> , vector<pair<long long ,long long>> , greater<pair<long long ,long long>>> busy;
        map<long long ,long long> freq ;
        for(int i = 0 ; i < (int)meetings.size() ; i++ ){
            while(busy.size() && busy.top().first <= meetings[i][0]) {free.push(busy.top().second) ; busy.pop() ; }

            if(free.size()){
                freq[free.top()] ++ ;
                busy.push({meetings[i][1], free.top()}) ;
                free.pop();
            } else{
                if(ans < n - 1){
                    busy.push({meetings[i][1] , ++ans}) ;
                    freq[ans]++ ;
                } else {
                    auto [time , room] = busy.top() ;
                    busy.pop() ;
                    busy.push({time + meetings[i][1] - meetings[i][0] , room})  ;
                    freq[room]++ ;
                }
                
            }

        }
        int res = -1 , maxfreq = 0 ;

        for(auto it : freq){
            if(it.second > maxfreq){
                res = it.first ;
                maxfreq = it.second ;
            }
        }

        return res; 

    }
};