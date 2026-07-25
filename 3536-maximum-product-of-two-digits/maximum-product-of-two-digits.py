class Solution(object):
    def maxProduct(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        m= sorted(str(n))
        return int(m[-1])*int (m[-2])