class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int n=bits.length;
        int m =0;
        while (m<n-1) {
            if(bits[m]==1){
                m+=2;
            }
            else{
                m+=1;
            }
            
        }
        return m==n-1;
    }
}