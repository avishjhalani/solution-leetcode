class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      vector<int>map(128,-1);
      int left =0 ;int right=0;
      int maxlen=0;
      while(right<s.size()){
        char cur = s[right];
        int index = map[cur];
        if(index!=-1 && index>=left ){
            left = index+1;
        }
        int window =right-left+1;
        maxlen = max(window , maxlen);
        map[cur] = right;
        right++;
      }
      return maxlen;
      
    }
};

//int left =0;
        // int max_length =0;
        // unordered_map<char,int> mp;
        // for(int i =0;i<s.length();i++){
        //     char c =s[i];
        //     mp[c] = mp[c]+1;
        //     while(mp[c]>1){
        //         char leftchar =s[left];
        //         mp[leftchar] = mp[leftchar]-1;
        //         left++;

        //     }
        //     max_length = max(max_length ,i-left+1);
        // }
        // return max_length;