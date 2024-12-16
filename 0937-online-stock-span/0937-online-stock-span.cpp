class StockSpanner {
private:
stack<pair<int,int>> st; //price,index
int index=-1;
public:
    StockSpanner() {}
    
    int next(int price) {
        index=index+1;
        while(!st.empty() && st.top().first<= price){
            st.pop();
        }
        int res=index - (st.empty() ? -1:st.top().second);
        st.push({price,index});

        return res;
    }   
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */