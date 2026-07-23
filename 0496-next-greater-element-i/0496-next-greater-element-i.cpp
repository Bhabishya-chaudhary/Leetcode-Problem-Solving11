class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      int n = nums2.size();
      vector<int> st;
      unordered_map<int, int> map;

      for(int i=n-1; i>=0; i--){
         int curr = nums2[i];
        while(!st.empty() && st.back()<=curr){
          st.pop_back();
        }
        if(st.empty()){
          map[curr]=-1;
        }
        else{
          map[curr]=st.back();
        }
        st.push_back(curr);
      }
      vector<int> ans;

      for(int i=0; i<nums1.size(); i++){
        ans.push_back(map[nums1[i]]);
      }
      return ans;
    }
};