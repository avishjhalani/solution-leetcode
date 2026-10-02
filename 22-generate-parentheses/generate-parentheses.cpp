class Solution {
public:
    void solve(vector<string>&ans ,string curr , int open ,int close ){
        if(open == 0 && close ==0){
            ans.push_back(curr);
            return;
        }
        if(open>0){
            solve(ans,curr+"(",open-1,close);
        }
        if(close>open){
            solve(ans,curr+")",open,close-1);
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(ans, "",n,n);
        return ans;
    }
};