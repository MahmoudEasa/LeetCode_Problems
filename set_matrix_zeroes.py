class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        matrix_len = len(matrix)
        visited = []
        to_visit = []

        for i in range(matrix_len):
            matrix_le = len(matrix[i])

            for  j in range(matrix_le):
                if (matrix[i][j] == 0):
                    vist_key = f"{i}: {j}"
                    if vist_key in visited and vist_key not in to_visit:
                        continue

                    """ Go right """
                    for k in range((j + 1), matrix_le):
                        vist_key = f"{i}: {k}"
                        if matrix[i][k] == 0 and vist_key not in visited:
                            vist_key = f"{i}: {k}"
                            to_visit.append(vist_key)
                            continue
                        matrix[i][k] = 0
                        visited.append(vist_key)

                    """ Go left """
                    for k in range((j - 1), -1, -1):
                        matrix[i][k] = 0
                        vist_key = f"{i}: {k}"
                        visited.append(vist_key)


                    """ Go from top to buttom """
                    for k in range(matrix_len):
                        vist_key = f"{k}: {j}"
                        if matrix[k][j] == 0 and vist_key not in visited:
                            vist_key = f"{k}: {j}"
                            to_visit.append(vist_key)
                            continue
                        matrix[k][j] = 0
                        visited.append(vist_key)

