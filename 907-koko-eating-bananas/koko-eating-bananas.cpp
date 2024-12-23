class Solution {
public:
    int check(vector <int> v, int k){
        int sum = 0;
        for(int i = 0; i < v.size(); i++){
            sum += ceil(v[i] / (k * 1.0));
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = *max_element(begin(piles), end(piles));
        while(low < high){
            int mid = low + (high - low) / 2;
            if(check(piles,mid) <= h){
                high = mid ;
            }
            else low = mid + 1;
        }
        return low;
    }
};