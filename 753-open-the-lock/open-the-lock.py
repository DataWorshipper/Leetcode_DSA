class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        if '0000' in deadends and target!='0000':
            return -1
        q=deque()
        q.append(('0000',0))
        vis=set()
        vis.add('0000')
        while q:
            curr_lock,num=q.popleft()
            if curr_lock==target:
                return num
            for i in range(4):
                    s1=""
                    s2=""
                    number=int(curr_lock[i])
                    up=(number+1)%10
                    down=(number-1+10)%10
                    s1=curr_lock[:i]+str(up)+curr_lock[i+1:]
                    s2=curr_lock[:i]+str(down)+curr_lock[i+1:]
                    if s1 not in deadends:
                        if s1 not in vis:
                            vis.add(s1)
                            q.append((s1,num+1))
                    if s2 not in deadends:
                        if s2 not in vis:
                            vis.add(s2)
                            q.append((s2,num+1))
        return -1







        