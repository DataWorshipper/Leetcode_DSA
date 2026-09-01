

class Solution:
    def minMoves(self, classroom: list[str], energy: int) -> int:
        m, n = len(classroom), len(classroom[0])

        litter = {}
        sr = sc = 0
        cnt = 0

        for i in range(m):
            for j in range(n):
                if classroom[i][j] == 'L':
                    litter[(i, j)] = cnt
                    cnt += 1
                elif classroom[i][j] == 'S':
                    sr, sc = i, j

        full = (1 << cnt) - 1

        q = deque()
        q.append((sr, sc, energy, 0, 0))

        vis = defaultdict(int)
        vis[(sr, sc, energy, 0)] = 1

        while q:
            r, c, e, mask, moves = q.popleft()

            if mask == full:
                return moves

            if e == 0:
                continue

            for dr, dc in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                nr, nc = r + dr, c + dc

                if nr < 0 or nr >= m or nc < 0 or nc >= n:
                    continue

                if classroom[nr][nc] == 'X':
                    continue

                ne = e - 1
                nmask = mask

                if classroom[nr][nc] == 'L':
                    nmask |= 1 << litter[(nr, nc)]

                if classroom[nr][nc] == 'R':
                    ne = energy

                state = (nr, nc, ne, nmask)

                if not vis[state]:
                    vis[state] = 1
                    q.append((nr, nc, ne, nmask, moves + 1))

        return -1