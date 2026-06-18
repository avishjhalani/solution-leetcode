class Solution {
public:
    int happyFind(int n){
        int sqsum = 0;
        while(n>0){
            int dig = n%10;
            sqsum +=dig*dig;
            n = n/10;
        }
        return sqsum;
    }
    bool isHappy(int n) {
        unordered_set<int>st;
        while(st.find(n) == st.end()){
            st.insert(n);
            n = happyFind(n);
            if(n == 1) return true;
        }
        return false;

    }
};