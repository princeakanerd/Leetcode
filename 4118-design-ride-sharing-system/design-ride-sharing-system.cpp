class RideSharingSystem {
public:
    queue<int> driver ;
    set<pair<int,int>> rider ;
    map<int,int> mpp ;
    int cnt ;
    
    RideSharingSystem() {
        cnt = 0 ;
    }
    
    void addRider(int riderId) {
        rider.insert({cnt , riderId}) ;
        mpp[riderId] = cnt ;
        cnt ++ ;
    }
    
    void addDriver(int driverId) {
        driver.push(driverId) ;
    }
    
    vector<int> matchDriverWithRider() {
        if(driver.empty() || rider.empty()) return {-1, -1} ;
        int d = driver.front() ;
        driver.pop() ;
        int r = rider.begin() -> second ;
        rider.erase(rider.begin()) ;
        
        return {d, r} ;
    }
    
    void cancelRider(int riderId) {
        rider.erase({mpp[riderId], riderId}) ;
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */