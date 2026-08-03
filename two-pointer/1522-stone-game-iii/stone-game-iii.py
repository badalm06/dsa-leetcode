class Solution:
    def solve(self,idx,nums,dp):
        n=len(nums)
        if idx>=n:
            return 0
        if dp[idx]!=float('-inf'):
            return dp[idx]
        maxi=float('-inf')
        sm=0
        for i in range(3):
            if i+idx<n:
                sm+=nums[i+idx]
                maxi=max(maxi,sm-self.solve(i+idx+1,nums,dp))
        dp[idx]=maxi
        return dp[idx]

    def stoneGameIII(self, nums: List[int]) -> str:
        n=len(nums)
        dp=[float('-inf')]*(n+1)
        ans=self.solve(0,nums,dp)
        if ans==0:
            return "Tie"
        elif ans>0:
            return "Alice"
        else:
            return "Bob"
        