class Solution {
public:
    // bool check(string s){
    //     stack <char> st;
    //     for(int i = 0; i < s.size(); i++){
    //         if(s[i] == '('){
    //             st.push(s[i]);
    //         }
    //         else{
    //             if(st.empty()){
    //                 return false;
    //             }
    //             else{
    //                 st.pop();
    //             }
    //         }
    //     }
    //     if(st.empty()){
    //         return true;
    //     }
    //     return false;
    // }
    bool canBeValid(string s, string locked) {
        // if(check(s)){
        //     return true;
        // }
        if(s.size() == 1){
            return false;
        }
        if(s.size() & 1) return false;
        int n = s.size();
        int last = -1;
        stack <int> open;
        stack <int> free;
        for(int i = 0; i < n; i++){
            if(locked[i] == '0'){
                free.push(i);
            }
            else if(locked[i] == '1' and s[i] == '('){
                open.push(i);
            }
            else if(locked[i] == '1' and s[i] == ')'){
                if(!open.empty() and open.top() < i){
                    open.pop();
                    continue;
                }
                if(!free.empty() and free.top() < i){
                    free.pop();
                }
                else return false;
            }
        }
        while(!open.empty() and !free.empty() and open.top() < free.top()){
            open.pop();
            free.pop();
        }
        if(!open.empty()) return false;
        return true;
    }
};