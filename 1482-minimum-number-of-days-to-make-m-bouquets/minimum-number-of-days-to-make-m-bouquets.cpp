class Solution {
public:
    int canmakebou(vector<int>& bloomDay, int mid, int k){
        int boucount =0;
        int conscount =0;
        for(int i =0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                conscount++;
            }
            else{
                conscount = 0;
            }
            if(conscount ==k){
                boucount++;
                conscount=0;

            }
        }
        return boucount;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n =bloomDay.size();
       int start =0;
       int end = *max_element(bloomDay.begin(), bloomDay.end());

       int min_day =-1;
       while(start<=end){
        int mid = start+(end-start)/2;
        if(canmakebou(bloomDay ,mid ,k)>=m) {
            min_day =mid;
            end =mid-1;
        }
        else{
            start =mid+1;
        }
       }
       return min_day;
    }
};