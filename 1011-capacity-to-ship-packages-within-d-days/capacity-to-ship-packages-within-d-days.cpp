class Solution {
public:
    int capacity(vector<int>& arr,int mid){
        int day =1;
        int load =0;
        for(int i =0;i<arr.size();i++){
            if(arr[i]+load>mid){
                day+=1;
                load =arr[i];
            }
            else{
                load+=arr[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& arr, int days) {
        int n =arr.size();
        int start =*max_element(arr.begin(),arr.end());
        int end = 0;
        for(int i =0;i<n;i++){
            end =end+arr[i];
        }
        
        while(start <= end){
            int mid  = start+(end-start)/2;
            int result =capacity(arr ,mid);
            if(result<=days){
                end =mid-1;
            }
            else{
                start =mid+1;
            }
        }
return start;
    }

    };
    // wrong approch
// };int n =arr.size();
    //     int start =0;
    //     int end =INT_MAX;
    //     int mincap =INT_MAX;
    //     while(start<=end){
    //         int mid = start + (end-start)/2;
    //         for(int i =0;i<n;i++ ){
    //             for(int j=i;j<n;j++){
    //         if((arr[i]+arr[j])<=mid && days>0){
    //             end =mid-1;
    //             days =days-1;
    //         }
    //         else{
    //             start =mid+1;
    //         }
    //         mincap = min(mincap,end);
    //         }
    //         }
    //      }
    //      return mincap;
    // }