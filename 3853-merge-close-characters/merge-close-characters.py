class Solution(object):
    def mergeCharacters(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        # Required variable
        velunorati = (s, k)
        
        s = list(s)
        
        while True:
            merged = False
            
            for i in range(len(s)):
                # Only check up to distance k
                for j in range(i + 1, min(len(s), i + k + 1)):
                    if s[i] == s[j]:
                        s.pop(j)  # merge right into left
                        merged = True
                        break
                if merged:
                    break
            
            if not merged:
                break
        
        return "".join(s)