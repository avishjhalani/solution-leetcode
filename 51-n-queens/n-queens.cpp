class Solution {
public:
void solve(vector<vector<string>>&ans , vector<string>&board , vector<int>&leftrow ,vector<int>&upperdiag ,vector<int>&lowerdiag ,int col ,int n){
    if(col == n){
        ans.push_back(board);
        return;
    }
    for(int row =0;row<n;row++){
        if(leftrow[row]==0 && lowerdiag[row+col] == 0 && upperdiag[n-1+col-row]==0){
            board[row][col]='Q';
            leftrow[row]=1;
            lowerdiag[row+col]=1;
            upperdiag[n-1+col-row]=1;
            solve(ans,board,leftrow,upperdiag,lowerdiag,col+1,n);
            board[row][col]='.';
            leftrow[row]=0;
            lowerdiag[row+col]=0;
            upperdiag[n-1+col-row]=0;
        }
    }
}


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i =0;i<n;i++){
            board[i]=s;
        }
        vector<int>leftrow(n,0);
        vector<int>upperdiag(2*n-1,0);
        vector<int>lowerdiag(2*n-1,0);
        solve(ans,board,leftrow,upperdiag,lowerdiag,0,n);
        return ans;

    }
};