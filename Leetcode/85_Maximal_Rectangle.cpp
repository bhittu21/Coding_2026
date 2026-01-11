int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0) return 0;

    int cols = matrixColSize[0];
    int height[cols];
    int stack[cols + 1];
    int maxArea = 0;

    for (int j = 0; j < cols; j++) height[j] = 0;

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1') height[j]++;
            else height[j] = 0;
        }

        int top = -1;
        for (int j = 0; j <= cols; j++) {
            int h = (j == cols) ? 0 : height[j];
            while (top != -1 && height[stack[top]] > h) {
                int hh = height[stack[top--]];
                int width = (top == -1) ? j : j - stack[top] - 1;
                int area = hh * width;
                if (area > maxArea) maxArea = area;
            }
            stack[++top] = j;
        }
    }

    return maxArea;
}