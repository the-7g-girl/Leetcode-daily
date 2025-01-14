class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        n = len(A)
        la = []
        lb = []
        C = []
        count = 0
        for i in range(n):
            la.append(A[i])
            lb.append(B[i])
            if A[i] == B[i]:
                count += 1
            else:
                if A[i] in lb:
                    count += 1
                if B[i] in la:
                    count += 1

            C.append(count)
        return C
