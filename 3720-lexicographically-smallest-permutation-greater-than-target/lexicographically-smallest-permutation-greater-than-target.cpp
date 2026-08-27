class Solution {
public:
string res;

bool solve(string target ,vector<int>count,string curr,bool greater,int i){
    if(i==target.length()){
        if(greater){
            res=curr;
            return true;
        }
        return false;
    }
    for(char ch ='a';ch<='z';ch++){
        if(count[ch-'a']==0){
            continue;
        }
        if(greater == false && ch<target[i]){
            continue;
        }
        curr.push_back(ch);
        count[ch-'a']--;
        bool isGreaternow = greater||ch>target[i];
        if(solve(target,count,curr,isGreaternow,i+1)){
            return true;
        }
        curr.pop_back();
        count[ch-'a']++;
    }
    return false;

}
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int>count(26,0);
        for(char c: s){
            count[c-'a']++;
        }
        string curr ="";
        solve(target ,count,curr,false,0);
        return res;
    }
};