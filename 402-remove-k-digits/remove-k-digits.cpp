#define ll long long
class Solution {
public:
    string removeKdigits(string nums, int k) {
        ll n = nums.size();
        stack <char> st;
        for(auto &x : nums){
            while(!st.empty() and (st.top() > (x)) and k){
                st.pop();
                k--;
            }
            if(st.empty() && x == '0'){
                continue;
            }
            st.push(x);
        }
        string ans = "";
        while(k > 0 and !st.empty()){
            st.pop();
            k--;
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(begin(ans), end(ans));
        if(ans.size() == 0) return "0";
        return ans;
    }
};
