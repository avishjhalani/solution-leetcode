class Solution {
public:
    int prodDigit(int n){
        int temp =1;
        while(n>0){
            int tem = n%10;
            temp *=tem;
            n=n/10;
        }
        return temp;
    }
    int smallestNumber(int n, int t) {
        int prod = prodDigit(n);
        if(prod%t==0)return n;
        while(prodDigit(n)%t!=0){
            n++;
        }
        return n;
    }
};