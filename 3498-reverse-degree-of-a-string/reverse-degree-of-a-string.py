class Solution(object):
    def reverseDegree(self, s):
        n = len(s)
        ans =0
        for i in range(n):
            ans +=(ord('z')-ord(s[i])+1)*(i+1)
        return ans
        