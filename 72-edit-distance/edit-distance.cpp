class Solution {
public:
int t[501][501];
string word1,word2 ;
    int solve(int i,int j){
        int ans =0;
        if(j<0) return i+1;
        
        if(i<0) return j+1;
        if(word1[i]==word2[j]){
            return solve(i-1,j-1);
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        int insert = 1+solve(i,j-1);
        int delete1 = 1+solve(i-1,j);
        int replace = 1+solve(i-1,j-1);
        ans =min({insert,delete1,replace});
        return t[i][j]=ans;
    }
    int minDistance(string w1, string w2) {
        word1 = w1;
        word2 = w2;
        memset(t,-1,sizeof(t));
        int n = w1.size();
        int m =w2.size();
        return solve(n-1,m-1);
    }
};