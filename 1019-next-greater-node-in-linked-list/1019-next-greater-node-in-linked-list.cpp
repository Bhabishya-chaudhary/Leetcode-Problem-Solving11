class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {

        vector<int> nums;

        // Linked List -> Vector
        while (head != nullptr) {
            nums.push_back(head->val);
            head = head->next;
        }

        int n = nums.size();
        vector<int> ans(n, 0);
        stack<int> st;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Remove smaller or equal elements
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            // If stack is not empty, top is next greater
            if (!st.empty()) {
                ans[i] = st.top();
            }

            // Put current element into stack
            st.push(nums[i]);
        }

        return ans;
    }
};