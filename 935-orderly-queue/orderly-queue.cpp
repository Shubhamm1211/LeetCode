class Solution {
public:
    string orderlyQueue(string s, int k){
            string ans;
            ans = s;
        if (k > 1){
            sort(s.begin(), s.end());
            return (s);
        }
        else{
            string temp=s+s;
            for (int i=0;i<=s.size();i++){
                string temp2=temp.substr(i,s.size());
                ans = min(ans,temp2);
            }
            return ans;
        }
    }
};