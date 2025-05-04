class Solution {
    public int maxProduct(int n) {
        String numberStr = String.valueOf(n);
        int result=0;
        int res=0;
int[] digits = new int[numberStr.length()];

for (int i = 0; i < numberStr.length(); i++) {
    digits[i] = Character.getNumericValue(numberStr.charAt(i));
}
for(int i =0 ;i <digits.length;i++){
    for(int j =i+1;j<digits.length;j++){
      result = digits[i]*digits[j];
      res =Math.max(res,result);
    }
}
return res;
    }
}