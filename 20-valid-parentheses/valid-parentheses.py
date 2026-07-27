class Solution:
    def isValid(self, s: str) -> bool:
        st=[]
        for c in s:
            if c=='(' or c=='{' or c=='[':
                st.append(c)
            else:
                if len(st)==0:
                    return False
                ch=st[-1]
                if c==')' and ch=='(' or c=='}' and ch=='{' or c==']' and ch=='[':
                    st.pop()
                else:
                    return False
        
        return len(st)==0
        