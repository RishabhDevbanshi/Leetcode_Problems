class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int,greater<int>> s(begin(stones), end(stones));
  while (s.size() > 1) {
    auto w1 = *(s.begin());
    s.erase((s.begin()));
    auto w2 = *(s.begin());
    s.erase((s.begin()));
    if (w1 - w2 > 0) s.insert(w1 - w2);
  }
  return s.empty() ? 0 : *s.begin();
    }
};