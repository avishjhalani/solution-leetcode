class Solution {
public:
int n;
int t[2][101][101];
    int solve(int person ,int i,int M,vector<int>&piles){
        n=piles.size();
        if(i>=n){
            return 0;
        }
        if(t[person][i][M]!=-1){
            return t[person][i][M];
        }
        int stone =0;
        int res=(person ==1)?-1:INT_MAX;
        for(int j =1;j<=min(2*M,n-i);j++){
            stone+=piles[i+j-1];
            if(person ==1){
                res = max(res,stone+solve(0,i+j,max(M,j),piles));
            }else{
                res =min(res,solve(1,i+j,max(M,j),piles));
            }
        }
        return t[person][i][M]=res;
    }
    int stoneGameII(vector<int>& piles) {
        memset(t,-1,sizeof(t));
        int ans =solve(1,0,1,piles);
        return ans;
    }
};