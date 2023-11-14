class Solution {
public:
  int minOperations(vector<int>& A) {
    const int n = A.size();
    sort(begin(A), end(A));
    A.erase(unique(begin(A), end(A)), end(A));    
    int ans = INT_MAX;
    for (int i = 0, j = 0, m = A.size(); i < m; ++i) {
      while (j < m && A[j] < A[i] + n) ++j;
      ans = min(ans, n - (j - i));
    }
    return ans;
  }
};