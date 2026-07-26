class Solution {
public:
int n;
int m;
    void transpose(vector<vector<int>>& mat){
        for(int i =0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
    }
    void rotate(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        transpose(mat);

        for(int i=0;i<n;i++){
           reverse(mat[i].begin(),mat[i].end());
        }



    }
};