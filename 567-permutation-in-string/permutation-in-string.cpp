class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> mp1 , mp2;
        int n1 = s1.size();
        int n2 = s2.size();
        for(auto x : s1){
            mp1[x]++;
        }
        int i = 0, j = 0;
        while(j < n2){
            mp2[s2[j]]++;
            if(j - i + 1 == n1){
                if(mp1 == mp2){
                    return true;
                }
                else{
                    mp2[s2[i]]--;
                    j++;
                    if(mp2[s2[i]] == 0) mp2.erase(s2[i]);
                    i++;
                }
            }
            else j++;
        }
        return false;
    }
};