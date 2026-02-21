class Solution(object):
    def generateRow(self,row):
        ans= 1
        temp = []
        temp.append(1)
        for col in range(1,row):
            ans = ans*(row-col)
            ans = ans//col
            temp.append(ans)
        return temp
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        ans=[]
        for i in range(1,numRows+1):
            ans.append(self.generateRow(i))
        return ans
        