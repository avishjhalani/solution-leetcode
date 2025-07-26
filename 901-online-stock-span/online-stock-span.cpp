class StockSpanner {
public:
    stack<pair<int, int>> st; 
    int counter = 0;

    StockSpanner() {}

    int next(int price) {
        while (!st.empty() && st.top().first <= price)
            st.pop();

        int span;
        if (st.empty())
            span = counter + 1;
        else
            span = counter - st.top().second;

        st.push({price, counter});
        counter++;
        return span;
    }
};