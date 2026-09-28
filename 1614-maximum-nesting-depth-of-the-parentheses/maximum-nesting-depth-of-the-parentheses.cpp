class Solution {
public:
    int maxDepth(string s) {
        int count =0;
        int maxcount =0;
        for(char c:s){
            if(c =='('){
                count++;
            }
            else if(c ==')'){
                count --;
            }
            maxcount =max(count,maxcount);
        }
        return maxcount;
    }
};