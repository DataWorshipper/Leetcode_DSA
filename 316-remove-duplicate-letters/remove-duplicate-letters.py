class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        n=len(s)
        st=[]
        i=0
        seen=set()
        freq=Counter(s)
        while i<n:
            freq[s[i]]-=1
            if s[i] in seen:
                i+=1
                continue
            while len(st)>0 and st[-1]>s[i] and  freq[st[-1]]>0:
                
                seen.remove(st.pop())

            st.append(s[i])
            seen.add(s[i])
            i+=1
        return ''.join(st)
