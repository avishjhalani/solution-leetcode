class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        if(n<=8) return n;
        int result =0;
        unordered_map<int,int>mp;
        int assign =2;
        for(char &ch :word){
            if(assign>9){
                assign =2;
            }
            mp[assign]++;
            result+=mp[assign];
            assign++;
        }
        return result;
    }
};