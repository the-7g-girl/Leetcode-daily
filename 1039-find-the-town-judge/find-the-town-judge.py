class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        graph = [[0 for _ in range(n)] for _ in range(n)]
        for t in trust:
            graph[t[1]-1][t[0]-1] = 1
        for i in range(n):
            if sum(graph[i]) == n-1 and sum(row[i] for row in graph) == 0:
                return i+1
        return -1
