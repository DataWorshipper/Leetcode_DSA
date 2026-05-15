class Solution:
    def countRoutes(self, locations: List[int], start: int, finish: int, fuel: int) -> int:

        n=len(locations)
        dp=[[-1]*(fuel+1) for _ in range(n)]
        MOD=10**9+7
        def f(i:int,fuel_left:int,start:int,finish:int,locations:List[int])->int:
            ans = 1 if i == finish else 0
            if fuel_left<=0 and i!=finish:
                return 0
            
            if dp[i][fuel_left]!=-1:
                return dp[i][fuel_left]
            
            for index,city in enumerate(locations):
                f2=fuel_left-abs(locations[i]-city)
                if locations[i]!=city and f2>=0:
                    ans=(ans+f(index,fuel_left-abs(locations[i]-city),start,finish,locations))%MOD
                
            dp[i][fuel_left]=ans%MOD
            return ans%MOD
        
        return  f(start,fuel,start,finish,locations)
      
        
    


            



        
