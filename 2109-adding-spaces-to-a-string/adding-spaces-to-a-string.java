class Solution {
    public String addSpaces(String s, int[] spaces) {
         StringBuilder str=new StringBuilder();
       int start=0;
       for(int space:spaces){
        str.append(s,start,space).append(" ");
        start=space;
       }
       str.append(s.substring(start));
       return str.toString();

    }
}