class Solution {
public:
vector<int>GenerateRow(int row){
    long long ans =1;
    vector<int>tempans;
    tempans.push_back(1);

    for(int i =1;i<row;i++){
        ans = ans*(row-i);
        ans =ans/i;
        tempans.push_back(ans);
    }
    return tempans;
}
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        for(int i =1;i<=n;i++){
            vector<int>temp = GenerateRow(i);
            ans.push_back(temp);
        }
        return ans;
    }
};