class Solution {
public:
long takentime(vector<int>&arr,int speed){
    long time =0;
    for(int i:arr){
        time+=int(ceil((double)i/speed));
    }
    return time;
}
    int minEatingSpeed(vector<int>& arr, int h) {
        int low =1;
        int high =1;
        for(int i:arr){
            if(i>high){
                high=i;
            }
        }
        while(low<high){
            int mid =low+(high-low)/2;
            long time = takentime(arr,mid);
            if(time<=h) high=mid;
            else low = mid+1;
        }
        return low;
    }
};