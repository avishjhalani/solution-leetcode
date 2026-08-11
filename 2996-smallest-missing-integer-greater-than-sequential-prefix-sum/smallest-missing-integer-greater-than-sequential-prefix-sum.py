class Solution(object):
    def missingInteger(self, nums):
        n =len(nums)
        my_set =set(nums)
        sum =nums[0]
        for i in range(1,n):
            if nums[i]==nums[i-1]+1:
                sum+=nums[i]
            else:
                break
        while sum in my_set:
            sum+=1
        
        return sum
        """
        :type nums: List[int]
        :rtype: int
        """
        