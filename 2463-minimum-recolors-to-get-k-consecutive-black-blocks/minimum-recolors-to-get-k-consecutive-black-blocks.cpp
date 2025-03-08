class Solution {
public:
    int minimumRecolors(string s, int k) {
        int n = s.size();
        int cnt = 0;
        vector <int> temp(n);
        for(int i = 0; i < n; i++){
            if(s[i] == 'W'){
                cnt++;
            }
            temp[i] = cnt;
            cout << temp[i] << " ";
        }
        cout << endl;
        int mini = INT_MAX;
        for(int i = 0; i <= n - k; i++){
            int diff = (i == 0) ? temp[i + k - 1] : temp[i + k - 1] - temp[i - 1];
            if(diff < mini){
                cout << i << endl;
            }
            mini = min(mini, diff);
        }
        return mini;
    }
};