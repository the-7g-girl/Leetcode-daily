class Solution:
    def isvalid(self, x, y, rows, cols):
        return 0 <= x < rows and 0 <=y < cols
    def orangesRotting(self, grid: List[List[int]]) -> int:
        visited = grid
        rows, cols = len(grid), len(grid[0])
        from collections import deque
        q = deque()
        fresh = 0
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 2:
                    q.append((r,c))
                elif grid[r][c] == 1:
                    fresh += 1

        if fresh == 0:
            return 0
        if not q:
            return -1
        

        ways = [(0,1), (0,-1), (1, 0), (-1,0)]
        minutes = 0
        while q:
            size = len(q)
            minutes += 1
            while size > 0:
                x, y = q.popleft()
                size -= 1
                for dx, dy in ways:
                    x_new, y_new = x+dx, y+dy
                    if self.isvalid(x_new, y_new, rows, cols) and visited[x_new][y_new] == 1:
                        visited[x_new][y_new] = 2
                        fresh -= 1
                        q.append((x_new, y_new))
        if fresh == 0:
            return minutes - 1
        return -1


        