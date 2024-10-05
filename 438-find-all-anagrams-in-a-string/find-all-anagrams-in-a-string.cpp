class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        int i = 0, j = 0;
        map<char,int> mp1 , mp2;
        vector<int> ans;
        for(auto x : p){
            mp1[x]++;
        }
        while(j < n1){
            // cout << "i = " << i << " " << "j = " << j << endl;
            // cout << "Map is: " << endl;
            // for(auto x : mp2){
            //     cout << x.first << " " << x.second << endl; 
            // }
            // cout << endl;
            mp2[s[j]]++;
            if(j - i + 1 == n2){
                if(mp1 == mp2){
                    ans.push_back(i);
                    // cout << "pushing in answer" << endl;
                }
                mp2[s[i]]--;
                if(mp2[s[i]] == 0) mp2.erase(s[i]);
                i++;
                j++;
                
            }
            else j++;
            
        }
        return ans;
    }
};