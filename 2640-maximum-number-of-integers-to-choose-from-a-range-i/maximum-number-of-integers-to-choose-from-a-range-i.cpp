class Solution {
public:
    int maxCount(vector<int>& v, int n, int maxSum) {
        map<int,int> mp;
        for(int i = 0; i < v.size(); i++){
            mp[v[i]]++;
        }
        int sum = 0, cnt = 0;
        for(int i = 1; i <= n; i++){
            if(mp.find(i) == mp.end()){
                sum += i;
                if(sum > maxSum) break;
                cnt++;
            }
        }
        return cnt;
    }
};