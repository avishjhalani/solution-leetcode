class Solution {
public:
    int mergeSort(int low, int high, vector<int>& nums, vector<int>& temp) {
        if(low >= high) return 0;
        int n = nums.size();
        int mid = low + (high - low) / 2;
        int cnt = 0;
        cnt += mergeSort(low, mid, nums, temp);
        cnt += mergeSort(mid + 1, high, nums, temp);

        int j = mid + 1;
        for(int i = low; i <= mid; i++) {
            while(j <= high && (long long)nums[i] > 2LL * nums[j]) j++;
            cnt +=(j - (mid + 1)); 
        }

        int left = low, right = mid + 1, k = low;
        while(left <= mid && right <= high) {
            if(nums[left] <= nums[right]) temp[k++] = nums[left++];
            else temp[k++] = nums[right++];
        } 
        while(left <= mid) temp[k++] = nums[left++];
        while(right <= high) temp[k++] = nums[right++];
        for(int i = low; i <= high; i++) nums[i] = temp[i];
        return cnt;

    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n, 0);
        return mergeSort(0, n - 1, nums, temp);
    }
};