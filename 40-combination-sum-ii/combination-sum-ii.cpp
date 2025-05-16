class Solution {
public:
vector<vector<int>>result;
void solve(vector<int>& candidates, int target,int idx ,vector<vector<int>>&result,vector<int>&temp){
        if(target<0) return;
        
        if(target==0){
            result.push_back(temp);
            return;
        }
        for(int i = idx ;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]){
                continue;
            }
            temp.push_back(candidates[i]);
            solve(candidates , target-candidates[i] ,i+1,result,temp);
            temp.pop_back();

        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        sort(begin(candidates) , end(candidates));
        solve(candidates,target,0,result,temp);
        return result;
    }
};
