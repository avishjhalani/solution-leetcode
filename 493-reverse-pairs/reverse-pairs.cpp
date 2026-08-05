class Solution {
public:
int ans =0;
    void merge(vector <int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }
        while (left <= mid) {
            temp.push_back(arr[left++]);
        }
        while (right <= high) {
            temp.push_back(arr[right++]);
        }
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }
    void countPair(vector<int>& nums, int low,int mid, int high){
        int right =mid+1;
        for(int i =low;i<=mid;i++){
            while(right<=high && (long long)nums[i]>2ll*nums[right]){
                right++;
            }
            ans = ans+(right-(mid+1));
        }
    }
    void mergesort(vector<int>& nums, int low, int high) {
        if (low >= high)
            return;
        int mid = low + (high - low) / 2;
        mergesort(nums, low, mid);
        mergesort(nums, mid + 1, high);
        countPair(nums,low,mid,high);

        merge(nums, low, mid, high);
    }
    int reversePairs(vector<int>& nums) { 
        int n = nums.size(); 
        mergesort(nums,0,n-1);
        return ans;
    }
};