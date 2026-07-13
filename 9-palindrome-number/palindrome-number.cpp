class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int n =x;
        int revx =0;
        while(x!=0){
            int temp = x%10;
            if(revx>INT_MAX/10 || revx<INT_MIN/10){
                return 0;
            }
            revx = (revx*10)+temp;
            x =x/10;
        }
        return revx==n;
    }
};