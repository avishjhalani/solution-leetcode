class Solution {
  public int numTrees(int n) {
        int[] num = new int[n+1];
        for(int i=0;i<=n;i++){
            num[i]=1;
        }
        for(int nodes=2;nodes<=n;nodes++){
            int total =0;
            for(int root=1;root<=nodes;root++){
                total+=num[root-1]*num[nodes-root];
            }
            num[nodes]=total;
        }
        return num[n];
    }  
}