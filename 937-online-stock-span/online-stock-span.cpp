class StockSpanner {
public:
    stack <pair <int,int> > st;
    StockSpanner() {

    }
    int next(int price) {
        if(st.empty() or st.top().first > price){
            st.push({price, 1});
            return 1;
        }
        else{
            int ans = 0;
            while(!st.empty() and st.top().first <= price){
                ans += st.top().second;
                st.pop();
            }
            st.push({price,ans + 1});
            return ans + 1;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */