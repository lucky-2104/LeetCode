class Solution:
    def longestPalindrome(self, s: str) -> str:

        res = ""
        resLen = 0
        for i in range(len(s)):
            #Odd length
            l = r = i
            while(l > -1 and r < len(s) and s[l] == s[r]):
                if(r-l+1 > resLen):
                    res = s[l:r+1]
                    resLen = r-l+1
                l = l-1
                r = r+1
            #For even length
            l = i 
            r = i+1
            while(l > -1 and r < len(s) and s[l] == s[r]):
                if(r-l+1 > resLen):
                    res = s[l:r+1]
                    resLen = r-l+1
                l = l-1
                r = r+1
        return res           
            
        