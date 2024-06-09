class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {
    stack<int> indices;
    int max_area = 0;
    int n = heights.size();
    
    for (int i = 0; i <= n; ++i) {
        while (!indices.empty() && (i == n || heights[indices.top()] >= heights[i])) {
            int height = heights[indices.top()];
            indices.pop();
            int width = indices.empty() ? i : i - indices.top() - 1;
            max_area = max(max_area, height * width);
        }
        indices.push(i);
    }
    
    return max_area;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> height(m, 0);
    int max_area = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            height[j] = (matrix[i][j] == '0') ? 0 : height[j] + 1;
        }
        max_area = max(max_area, largestRectangleArea(height));
    }
    
    return max_area;
}
};