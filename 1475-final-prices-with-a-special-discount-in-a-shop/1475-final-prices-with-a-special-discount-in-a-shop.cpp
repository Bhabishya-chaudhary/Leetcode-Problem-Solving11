class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;

        for (int i = prices.size() - 1; i >= 0; i--) {

            // Remove all greater elements
            while (!st.empty() && st.top() > prices[i]) {
                st.pop();
            }

            // Apply discount if available
            if (!st.empty()) {
                prices[i] = prices[i] - st.top();
            }

            // Push the original price
            st.push(prices[i] + (st.empty() ? 0 : st.top())); // Not recommended
        }

        return prices;
    }
};