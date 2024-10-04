#define ll long long
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        int i = 0, j = n - 1;
        sort(begin(skill),end(skill));
        int sum = skill[0] + skill[n-1];
        ll ans = 0;
        while(i < j){
            if(skill[i] + skill[j] != sum){
                return -1;
            }
            else{
                ans += skill[i]*skill[j];
            }
            i++;
            j--;
        }
        return ans;
    }
};