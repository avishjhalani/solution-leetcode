class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st(nums.begin(),nums.end());
        int i=1;
        bool flag =true;
        while(flag){
            if(st.find(k*i)==st.end()){
                flag = false;
            }
            else{
                i++;
            }
        }
        return k*i;
    }
};