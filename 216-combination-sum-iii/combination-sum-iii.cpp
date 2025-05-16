class Solution {
public:
void solve(int k,int n,int sum,int idx ,vector<vector<int>>&result,vector<int>&temp){
    if(sum ==n &&k==0){
        result.push_back(temp);
        return;
    }
    if(sum>n){
        return ;
    }
    for(int i =idx;i<=9;i++){
        if(i>n) break;
        temp.push_back(i);
        solve(k-1,n,sum+i,i+1,result,temp);
        temp.pop_back();
    }
}

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>result;
        vector<int>temp;
        solve(k,n,0,1,result,temp);
        return result;
    }
};