class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum =0;
        long long num =0;
        int help =1;
        while(n>0){
            int temp = n%10;
            if(temp!=0){
                num = num+temp*help;
                help*=10;
                sum+=temp;
            }
            n=n/10;
        }
        return num * sum;
    }
};