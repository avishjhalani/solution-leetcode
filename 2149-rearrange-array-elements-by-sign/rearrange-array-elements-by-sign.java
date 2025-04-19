class Solution {
    public int[] rearrangeArray(int[] arr) {
      int n = arr.length/2;
        int pos[]=new int[n];
        int neg[]=new int[n];
        int res[]=new int[arr.length];
        int posindex=0;int negindex=0;
        for(int i =0;i<arr.length;i++){
            if(arr[i]>0){
                pos[posindex++]=arr[i];
            }
            else{
                neg[negindex++]=arr[i];
            }
        }
        int j=0;
        for(int i =0;i<n;i++){
            res[j++]=pos[i];
            res[j++]=neg[i];
        }
        return res;
    }
}