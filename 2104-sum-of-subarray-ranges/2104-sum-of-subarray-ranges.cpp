class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        auto contribution = [&](bool isMax) {
            vector<int> left(n), right(n);
            stack<int> st;

            // Previous greater/smaller
            for (int i = 0; i < n; i++) {
                while (!st.empty() &&
                       (isMax ? nums[st.top()] <= nums[i]
                              : nums[st.top()] >= nums[i]))
                    st.pop();

                left[i] = st.empty() ? i + 1 : i - st.top();
                st.push(i);
            }

            while (!st.empty()) st.pop();

            // Next greater or equal / smaller or equal
            for (int i = n - 1; i >= 0; i--) {
                while (!st.empty() &&
                       (isMax ? nums[st.top()] < nums[i]
                              : nums[st.top()] > nums[i]))
                    st.pop();

                right[i] = st.empty() ? n - i : st.top() - i;
                st.push(i);
            }

            long long sum = 0;
            for (int i = 0; i < n; i++)
                sum += 1LL * nums[i] * left[i] * right[i];

            return sum;
        };

        return contribution(true) - contribution(false);
    }
};