class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n =grid.size();
        map<vector<int>,int>mp;
        int ans =0;
        for(int row =0;row<n;row++){
            mp[grid[row]]++;
        }
        for(int c =0;c<n;c++){
            vector<int>temp;
            for(int r =0;r<n;r++){
                temp.push_back(grid[r][c]);
            }
            ans+=mp[temp];
        }
        return ans;
    }
};