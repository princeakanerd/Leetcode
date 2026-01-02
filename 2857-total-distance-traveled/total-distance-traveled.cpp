class Solution {
    using ll = long long ;
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        ll total = 0 ;
        while(mainTank >= 5 && additionalTank > 0){
            total += mainTank - mainTank % 5 ;
            ll temp = mainTank / 5 ;
            mainTank = mainTank % 5 + min(1ll * additionalTank, temp) ;
            additionalTank -= min(1ll * additionalTank, temp) ;
        }
        total += mainTank ;

        return total * 10 ;
    }
};