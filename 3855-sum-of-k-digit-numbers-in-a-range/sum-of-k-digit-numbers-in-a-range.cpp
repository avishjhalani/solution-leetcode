class Solution {
public:
    static const long long MOD = 1e9+7;

    long long power(long long a , long long b){
        long long res =1;
        while(b){
            if(b&1){
                res = (res*a)%MOD;
            }
            a = (a*a)%MOD;
            b>>=1;
        }
        return res;
    }
    int sumOfNumbers(int l, int r, int k) {
        long long c = r-l+1;
        long long sum_digit = (1LL*(l+r)*c/2)%MOD;

        long p1 = power(c,k-1);
        long p2 = (power(10,k)-1+MOD)%MOD;

        long long in = power(9,MOD-2);
        p2 = (p2*in)%MOD;

        long long ans= sum_digit;
        ans =(ans*p1)%MOD;
        ans = (ans*p2)%MOD;

        return ans;
    }
};