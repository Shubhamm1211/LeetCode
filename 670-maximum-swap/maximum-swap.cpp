class Solution {
public:
    string s ;
    int ans = 0 ;
    int maximumSwap(int num) {
        s = to_string(num);
        
        for(int i = 0 ;i < s.size(); i++){
            for(int j = 0 ;j < s.size(); j++){
                swap(s[i],s[j]);
                if(ans < stoi(s)){
                    ans = stoi(s);
                }
                swap(s[i],s[j]);
            }
        }
        return ans;
    }
};