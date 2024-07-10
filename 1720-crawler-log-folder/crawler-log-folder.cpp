class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<int>st;
        st.push(12);
        int n=logs.size();
        for(int i=0;i<n;i++){
            if(logs[i]=="../"){
                if(!st.empty() and st.top()!=12){
                    st.pop();
                }
            }
            else if(logs[i]=="./"){
                continue;
            }
            else{
                st.push(1);
            }
        }
        return st.size()-1;
    }
};