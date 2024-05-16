class Solution:
    def dailyTemp(self, temps:List[int]) -> List[int]:
        res = [0] * len(temps)
        stack = []
        
        for i, t in enumerate(temps):
            while stack > stack[-1][0]:
                res[stackInd] = (i - stackInd)
            stack.append([t,i])    
            return res