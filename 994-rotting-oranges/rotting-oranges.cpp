class Solution {
public:
typedef pair<int,int>p;
vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<p>q;
        int fresh =0;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1)fresh++;
            }
        }
        if(fresh ==0)return 0;
        int mini =0;
        while(!q.empty()){
            int x = q.size();
            while(x--){
                p curr = q.front();
                q.pop();
                int i =curr.first;
                int j = curr.second;
                for(vector<int>&dir:directions){
                    int new_i=i+dir[0];
                    int new_j =j+dir[1];
                    if(new_i>=0 && new_i<n && new_j>=0 && new_j<m && grid[new_i][new_j]==1){
                        grid[new_i][new_j]=2;
                        q.push({new_i,new_j});
                        fresh--;
                    }
                }
            }
            mini++;
        }
        return fresh==0 ? (mini-1):-1;
    }
};