class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        st=[]
        n=len(asteroids)
        for sz in asteroids:
            if len(st)==0:
                st.append(sz)
                continue
            while st and st[-1]>0 and sz<0:
                s=abs(st[-1])
                sz_abs=abs(sz)
                if s<sz_abs:
                    st.pop()
                    
                elif sz_abs<s:
                    sz=0
                    break
                else:
                    sz=0
                    st.pop()
                    break
            if sz!=0:
                st.append(sz)
        return st

        