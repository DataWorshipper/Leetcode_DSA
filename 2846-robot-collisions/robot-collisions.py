class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        
        arr=[]
        n=len(positions)
        for i in range(n):
            arr.append((positions[i],healths[i],directions[i],i))
        arr.sort(key=lambda x:x[0])
        st=[]
        for pos,health,direction,idx in arr:
            if len(st)==0:
                st.append((pos,health,direction,idx))
                continue
            while st and st[-1][2]=='R' and direction=='L':
                p,h,d,i=st[-1]
                if h<health:
                    st.pop()
                    health-=1
                    
                    
                elif h==health:
                    health=0
                    st.pop()
                    break
                    
                else:
                    health=0
                    st.pop()
                    st.append((p,h-1,d,i))
                    break
            if health>0:
                st.append((pos,health,direction,idx))
        
            
            

        st.sort(key=lambda x:x[3])
        ans=[]
        for pos,health,direction,idx in st:
            ans.append(health)
        return ans

            
        