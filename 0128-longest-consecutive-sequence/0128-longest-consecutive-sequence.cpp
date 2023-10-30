class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
  sort(arr.begin(), arr.end());
        int n = arr.size();
        if (n == 0) return 0;
        int maxCnt = 1;
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1] + 1) {
                cnt++;
            }
            else if (arr[i] != arr[i - 1]) {
                cnt = 1;
            }
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
};