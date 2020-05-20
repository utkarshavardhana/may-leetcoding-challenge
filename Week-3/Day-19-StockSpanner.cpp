class StockSpanner {
public:
    StockSpanner() {
        st = stack<int> ();
    }
    
    int next(int price) {
        m[counter] = {price, 1};
        if(st.empty() or m[st.top()].first > price) {
            st.push(counter);
            return m[counter++].second;
        }
        while(!st.empty() and m[st.top()].first <= price) {
            m[counter].second += m[st.top()].second;
            st.pop();
        }
        st.push(counter);
        return m[counter++].second;
    }
private:
    stack<int> st;
    unordered_map<int, pair<int, int>> m; // contains mapping of indices with {price and stock span}
    int counter = 0;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
