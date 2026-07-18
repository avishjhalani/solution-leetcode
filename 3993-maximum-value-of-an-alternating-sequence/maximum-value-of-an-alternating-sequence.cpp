class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n==1) return s;
        long long k =n/2;

        long long maxval =(long long)s+m+(k-1)*(long long)(m-1);

        long long k1 =(n+1)/2;
        long long maxval1 = (long long)s+(k1-1)*(long long)(m-1);

        return max(maxval,maxval1);
        
    }
};