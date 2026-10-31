class Solution {
public:
int n , m ,MOD =1e9+7;
// int count =0;
int t[501][501][3];
int solve(vector<vector<int>>& grid,int i,int j,int dir){
    if(i>=m||j>=n){
        return 0;
    }
    if(i == m-1&& j==n-1){
        return 1;
    }
    if(t[i][j][dir]!=-1){
        return t[i][j][dir];
    }
    long long ans = 0;
    if(grid[i][j]==1){
        if(dir == 1){
            ans = solve(grid,i+1,j,2);
        }
        else if(dir == 2){
            ans = solve(grid,i,j+1,1);
        }
    }
    else{
        ans = (solve(grid,i,j+1,1)+solve(grid,i+1,j,2))%MOD;
        }
    return t[i][j][dir]=ans;
    
}
    int uniquePaths(vector<vector<int>>& grid) {
        m =grid.size();
        n = grid[0].size();
        memset(t,-1,sizeof(t));
        return solve(grid,0,0,0);
    }
};