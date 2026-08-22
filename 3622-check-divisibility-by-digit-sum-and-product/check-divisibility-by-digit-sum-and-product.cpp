class Solution {
public:
    bool checkDivisibility(int n) {
        int x =n;
        int sum =0;
        int prod =1;
        int temp;
        while(n>0){
            temp =n%10;
            sum+=temp;
            prod*=temp;
            n=n/10;
        }
        if(x%(sum+prod)==0)return true;
        return false;
    }
};