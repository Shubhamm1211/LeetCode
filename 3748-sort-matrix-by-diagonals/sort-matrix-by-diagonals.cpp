class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int start = n - 2;
        while(start >= 0){
            int r = start;
            int c = 0;
            vector <int> temp;
            while(r < n and c < n){
                temp.push_back(grid[r][c]);
                r++;
                c++;
            }
            sort(rbegin(temp), rend(temp));
            r = start;
            c = 0;
            int i = 0;
            while(r < n and c < n){
                grid[r][c] = temp[i];
                i++;
                r++;
                c++;
            }
            start--;
        }
        start = n - 2;
        while(start > 0){
            int r = 0;
            int c = start;
            vector <int> temp;
            while(r < n and c < n){
                temp.push_back(grid[r][c]);
                r++;
                c++;
            }
            sort(begin(temp), end(temp));
            r = 0;
            c = start;
            int i = 0;
            while(r < n and c < n){
                grid[r][c] = temp[i];
                i++;
                r++;
                c++;
            }
            start--;
        }
        return grid;
    }
};