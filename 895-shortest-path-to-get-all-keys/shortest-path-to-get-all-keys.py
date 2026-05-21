from collections import deque

class Solution:
    def shortestPathAllKeys(self, grid: List[str]) -> int:

        dirn = [(1,0), (-1,0), (0,1), (0,-1)]

        m = len(grid)
        n = len(grid[0])

        q = deque()
        vis = set()

        cnt = 0
        start_x = 0
        start_y = 0

        for i in range(m):
            for j in range(n):

                if 'a' <= grid[i][j] <= 'z':
                    cnt += 1

                if grid[i][j] == '@':
                    start_x = i
                    start_y = j

        final_mask = (1 << cnt) - 1

        q.append((start_x, start_y, 0, 0))
        vis.add((start_x, start_y, 0))

        while q:

            curr_x, curr_y, curr_mask, moves = q.popleft()

            if curr_mask == final_mask:
                return moves

            for dx, dy in dirn:

                new_x = curr_x + dx
                new_y = curr_y + dy

                if 0 <= new_x < m and 0 <= new_y < n:

                    ch = grid[new_x][new_y]

                    if ch == '#':
                        continue

                    elif ch == '.' or ch == '@':

                        if (new_x, new_y, curr_mask) not in vis:

                            vis.add((new_x, new_y, curr_mask))

                            q.append((new_x, new_y, curr_mask, moves + 1))

                    elif 'a' <= ch <= 'z':

                        idx = ord(ch) - ord('a')

                        new_mask = curr_mask | (1 << idx)

                        if (new_x, new_y, new_mask) not in vis:

                            vis.add((new_x, new_y, new_mask))

                            q.append((new_x, new_y, new_mask, moves + 1))

                    else:

                        idx = ord(ch.lower()) - ord('a')

                        if (curr_mask >> idx) & 1:

                            if (new_x, new_y, curr_mask) not in vis:

                                vis.add((new_x, new_y, curr_mask))

                                q.append((new_x, new_y, curr_mask, moves + 1))

        return -1