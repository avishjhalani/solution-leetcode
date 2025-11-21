class Solution {
public:
    int ladderLength(string beginword, string endword, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginword,1});
        set<string>s(wordList.begin(),wordList.end());
        s.erase(beginword);
        while(!q.empty()){
            string word =q.front().first;
            int steps =q.front().second;
            q.pop();
            if(word==endword){
                return steps;
            }
            for(int i =0;i<word.size();i++){
                char ori = word[i];
                for(char c ='a';c<='z';c++){
                    word[i]=c;
                    if(s.find(word)!=s.end()){
                        q.push({word,steps+1});
                        s.erase(word);
                    }
                }
                word[i]=ori;
            }
        }
        return 0;
    }
};