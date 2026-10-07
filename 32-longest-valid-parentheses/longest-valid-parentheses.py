class Solution:
    def longestValidParentheses(self, s: str) -> int:
        n=len(s)
        st=[-1]
        mn=0
        for i in range(n):

            if s[i]=='(':
                st.append(i)
            
            else:
                st.pop()
                if len(st)==0:
                    st.append(i)
                else:
                    mn=max(mn,i-st[-1])
                    
        return mn



        