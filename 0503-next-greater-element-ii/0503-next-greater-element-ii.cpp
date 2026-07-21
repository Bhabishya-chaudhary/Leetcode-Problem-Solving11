class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;
    stack<int> s;

    for (int i = 2 * n - 1; i >= 0; i--) {

        while (!s.empty() && s.top() <= nums[i % n]) {
            s.pop();
        }

        if (i < n) {
            if (s.empty())
                ans.push_back(-1);
            else
                ans.push_back(s.top());
        }

        s.push(nums[i % n]);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
};