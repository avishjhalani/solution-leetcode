class Solution(object):
    def smallestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s)
        count ={}

        for c in s:
            index = ord(c) - ord('a')
            count[index] = count.get(index, 0) + 1
        left =""
        mid =""
        for i in range (0,26):
            freq = count.get(i,0)

            if freq%2 == 1:
                mid += chr(ord('a')+i)
            left +=  chr(ord('a') + i) * (count.get(i, 0) // 2)
        
        right = left[::-1]

        return left+mid+right