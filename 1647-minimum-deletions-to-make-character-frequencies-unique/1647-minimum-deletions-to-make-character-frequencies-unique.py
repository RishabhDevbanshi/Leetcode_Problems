class Solution:
    def minDeletions(self, s: str) -> int:
        freq = [0]*26
        for ch in s:
            freq[ord(ch) - 97] += 1
        
        # print(freq)
        
        freq.sort(reverse=True)
        cnt = 0
        maxi = freq[0]
        for i in range(1,26):
            if freq[i] == 0:
                continue
            if freq[i] < maxi:
                maxi = freq[i]
            else:
                maxi = max(0,maxi-1)
                cnt += freq[i] - maxi
                freq[i] = maxi
                
        return cnt
        
        
        