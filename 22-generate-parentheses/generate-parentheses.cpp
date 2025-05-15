class Solution {
public:
    void recur(string comb,int lcount,int rcount,vector<string>&ans,int n){
        
        if(rcount==n){
            ans.push_back(comb);
            return;
        }

        if(lcount>rcount){
            recur(comb+")",lcount,rcount+1,ans,n);
        }
        
        if(lcount<n){
            recur(comb+"(",lcount+1,rcount,ans,n);
        }
        
    }


    vector<string> generateParenthesis(int n) { 
        vector<string>ans; 
        int lcount=0;
        int rcount=0;
        recur("",lcount,rcount,ans,n);
        return ans;
    }
};
