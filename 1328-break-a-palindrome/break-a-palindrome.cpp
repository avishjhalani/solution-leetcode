class Solution {
public:
    string breakPalindrome(string p) {
        if(p.size()==1) return "";
        int n = p.size();
        int k=1;
        bool flag =true;
        for(int i =0;i<n/2;i++){
            if(p[i]!='a' && k>0){
                p[i]='a';
                k--;
                flag =false;
            }
        }
        if(flag){
            p[n-1] ='b';
        }
        return p;
    }
};