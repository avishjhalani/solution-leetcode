class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(char ch:word1){
            mp1[ch]++;
        }
        for(char ch:word2){
            mp2[ch]++;
        }
        for(auto i:mp1){
            if(mp2.find(i.first) == mp2.end()){
                return false;
            }
        }
        for(auto i:mp2){
            if(mp1.find(i.first) == mp1.end()){
                return false;
            }
        }
        unordered_map<int,int>fre1,fre2;
        for(auto i:mp1) fre1[i.second]++;
        for(auto i:mp2) fre2[i.second]++;
        return fre1==fre2;
    }
};