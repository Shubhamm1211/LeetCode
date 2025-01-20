class Solution {
public:
    int bs(vector<pair<int, int>>& temp, int tar) {
        int i = 0, j = temp.size() - 1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (temp[mid].first == tar) {
                return temp[mid].second;
            } else if (temp[mid].first < tar) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return -1;
    }

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        map<int, pair<int, int>> mp;
        int n = arr.size();
        int nn = mat.size();
        int mm = mat[0].size();

        vector<pair<int, int>> temp;
        for (int i = 0; i < n; i++) {
            temp.push_back({arr[i], i});
        }
        sort(begin(temp), end(temp));

        for (int i = 0; i < nn; i++) {
            for (int j = 0; j < mm; j++) {
                int ind = bs(temp, mat[i][j]);
                if (ind != -1) {
                    mp[mat[i][j]] = {i, j};
                }
            }
        }
        vector<int> r(nn, 0), c(mm, 0);
        for (int i = 0; i < n; i++) {
            int val = arr[i];
            int mr = mp[val].first;
            int mc = mp[val].second;
            r[mr]++;
            c[mc]++;
            if (r[mr] == mm or c[mc] == nn) {
                return i;
            }
        }
        return -1;
    }
};
