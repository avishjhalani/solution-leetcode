class Solution(object):
    def setZeroes(self, arr):
        n = len(arr)
        m = len(arr[0])
        col1 = 1

        # Step 1: mark rows & columns
        for i in range(n):
            for j in range(m):
                if arr[i][j] == 0:
                    arr[i][0] = 0
                    if j != 0:
                        arr[0][j] = 0
                    else:
                        col1 = 0

        # Step 2: update inner matrix
        for i in range(1, n):
            for j in range(1, m):
                if arr[i][0] == 0 or arr[0][j] == 0:
                    arr[i][j] = 0

        # Step 3: handle first row
        if arr[0][0] == 0:
            for j in range(m):
                arr[0][j] = 0

        # Step 4: handle first column
        if col1 == 0:
            for i in range(n):
                arr[i][0] = 0
