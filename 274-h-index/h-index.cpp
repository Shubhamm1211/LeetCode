class Solution {
public:
    int hIndex(vector<int>& v) {
        sort(begin(v),end(v));
        int n = v.size();
        int maxi = INT_MIN;
        for(int i = 0; i <= v.back(); i++){
            int elem = i, cnt = 0;
            for(int j = 0; j < n; j++){
                if(v[j] >= elem){
                    cnt++;
                }
            }
            if(cnt >= elem){
                maxi = max(maxi, elem);;
            }
        }
        if(maxi == INT_MIN) return 1;
        return maxi;
    }
};