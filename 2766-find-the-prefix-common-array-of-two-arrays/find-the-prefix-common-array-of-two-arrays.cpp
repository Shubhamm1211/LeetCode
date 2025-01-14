class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int> &a, vector<int> &b) {
        int n = a.size();
        vector <int> ans(n,0);
        set <int> st1, st2;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            st1.insert(a[i]);
            st2.insert(b[i]);
            if(a[i] == b[i]) cnt++;
            if(st2.find(a[i]) != st2.end() and a[i] != b[i]){
                cnt++;
            }
            if(st1.find(b[i]) != st1.end() and a[i] != b[i]){
                cnt++;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};