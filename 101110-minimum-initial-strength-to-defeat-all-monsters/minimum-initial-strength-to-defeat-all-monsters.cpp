class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();

        vector<long long>diff(n+1,0);
        for(auto &b:boosts){
            int l =b[0],r=b[1], v=b[2];
            diff[l]+=v;
            diff[r+1]-=v;
        }
        vector<long long>bonus(n);
        long long run =0;
        for(int i =0;i<n;i++){
            run+=diff[i];
            bonus[i]=run;            
        }
        auto fes = [&](long long S)->bool{
            long long cur = S;
            for(int i =0;i<n;i++){
                if(cur+bonus[i]<monsters[i])return false;
                cur-=monsters[i];
                if(cur<0) cur =0;
            }
            return true;
        };
        long long lo =0,hi =0;
        for(int n : monsters)hi+=n;

        while(lo<hi){
            long long mid = lo+(hi-lo)/2;
            if(fes(mid))hi =mid;
            else lo =mid+1;
        }
        return lo;
    }
};