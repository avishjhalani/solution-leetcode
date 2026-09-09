class Solution {
public:
    long long countCommas(long long n) {
        long long  pow[6] = {1000, 1000000, 1000000000, 1000000000000, 1000000000000000, 1000000000000000000};
        long long k =0;
        for(auto&p:pow){
            k+=n>=p;
        }
        return k*(n+1)-(pow[k]-1000)/999;
    }
};