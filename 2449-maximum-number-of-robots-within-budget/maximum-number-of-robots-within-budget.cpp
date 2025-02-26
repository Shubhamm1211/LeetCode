#define ll long long
class Solution {
public:
    ll n;
    bool solve(vector <int> &arr1, vector <int> &arr2, ll k, ll mid){
        ll i = 0, j = 0;
        ll sum = 0;
        priority_queue <pair <int,int>> pq;
        // pq.push({arr1[i],i});
        while(j < n){
            sum += arr2[j];
            pq.push({arr1[j],j});
            while (!pq.empty() && (pq.top().first + (j - i + 1) * sum) > k) {
                    sum -= arr2[i];
                    i++;
                    while (!pq.empty() && pq.top().second < i) {
                        pq.pop();
                    }
                }
            if (j - i + 1 >= mid) return true;
            j++;
        }
        return false;
    }
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long k) {
        n = chargeTimes.size();
        ll low = 0;
        ll high = n;
        int ans = 0;
        while(low <= high){
            ll mid = low + ((high - low) / 2);
            if(solve(chargeTimes, runningCosts, k, mid)){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};
