void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int i, j, *matrixCols;
    int *matrixRows = (int*)malloc(matrixSize * sizeof(int));


    if (!matrixRows)
        return;

    matrixCols = (int*)malloc(matrixColSize[0] * sizeof(int));
    if (!matrixCols)
    {
        free(matrixRows);
        return;
    }

    for (i = 0; i < matrixSize; i++)
    {
        for (j = 0; j < matrixColSize[i]; j++)
            if (matrix[i][j] == 0)
            {
                matrixCols[j] = 1;
                matrixRows[i] = 1;
            }
    }

    for (i = 0; i < matrixSize; i++)
        for (j = 0; j < matrixColSize[i]; j++)
            if (matrixCols[j] == 1 || matrixRows[i] == 1)
                matrix[i][j] = 0;

    free(matrixRows);
    free(matrixCols);
}
