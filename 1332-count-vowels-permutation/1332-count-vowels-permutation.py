class Solution:
    def countVowelPermutation(self, n: int) -> int:
        a , e , i , o , u = 1,1,1,1,1
        mod = 10**9 + 7
        for k in range (1,n):
            nexta =  e
            nexte = (a + i) % mod
            nexti = (a + e + o + u) % mod
            nexto = (i + u) % mod
            nextu = a

            a , e , i , o , u = nexta , nexte , nexti , nexto , nextu
        return (a+e+i+o+u) % mod




        