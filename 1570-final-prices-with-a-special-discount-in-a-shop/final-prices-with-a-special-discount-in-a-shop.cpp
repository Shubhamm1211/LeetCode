class Solution {
public:
    vector<int> finalPrices(vector<int>& v) {
        int n = v.size();
        for(int i = 0; i < n - 1; i++){
            int curr = v[i];
            int j = i + 1;
            for(; j < n - 1; j++){
                if(v[j] <= v[i]) break;
            }
            if(v[i] >= v[j]) v[i] -= v[j];
        }
        return v;
    }
};