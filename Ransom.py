class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        l = {}
        for c in magazine:
            if c in l:
                l[c]+=1
            else:
                l[c]=1
        for c in ransomNote:
            if c in l and l[c]>0:
                l[c]-=1
            else:
                return False     
        return True
        
