class Solution:
    def minInsertions(self, s: str) -> int:
        n=len(s)
        st=[]
        cnt=0
        i=0
        while i<n:
            if s[i]=='(':
                st.append('(')
                i+=1
            else:
                if len(st)==0:
                    if i+1!=n  and s[i+1]==')':
                        cnt+=1
                        i+=2
                    elif (i + 1 != n and s[i + 1] == '(') or i + 1 == n:
                        cnt+=2
                        i+=1
                else:
                    if i+1!=n and s[i+1]==')':
                        st.pop()
                        i+=2
                    elif (i+1!=n and s[i+1]=='(') or i+1==n:
                        st.pop()
                        cnt+=1
                        i+=1
        cnt1=0
        while st:
            cnt1+=1
            st.pop()
        return cnt+2*cnt1
                    


        