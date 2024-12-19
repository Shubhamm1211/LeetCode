class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector <int> cpy(begin(arr), end(arr));
        sort(begin(arr), end(arr));
        vector <int> pre1(n);
        pre1[0] = arr[0];
        for(int i = 1; i < n; i++){
            pre1[i] = pre1[i - 1] + arr[i];
        }
        vector <int> pre2(n);
        pre2[0] = cpy[0];
        for(int i = 1; i < n; i++){
            pre2[i] = pre2[i - 1] + cpy[i];
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(pre1[i] == pre2[i]) ans++;
        }
        return ans;
    }

};