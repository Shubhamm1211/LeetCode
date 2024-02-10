class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxi=0;
        int start=0;
        int end=0;
        set<char>st;
        while(start<n){
            auto it=st.find(s[start]);
            if(it==st.end()){
                maxi=max(maxi,start-end+1);
                st.insert(s[start]);
                start++;
            }
            else{
                st.erase(s[end]);
                end++;
            }
        }
        return maxi;
    }
};