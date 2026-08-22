class Solution {
public:
    bool checkDivisibility(int n) {
        int sum =0;
        int prod =1;
        int n1 =n;
        while(n>0){
            int temp = n%10;
            sum+=temp;
            prod*=temp;
            n=n/10;
        }
        int div =sum+prod;
        if(n1%div==0)return true;
        return false;
    }
};