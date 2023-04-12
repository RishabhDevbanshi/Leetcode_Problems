class Solution {
public:
    string simplifyPath(string path) {
            deque<string> q;

            stringstream ss(path);
            string word;

            while (getline(ss, word, '/'))
            {
                  // cout << word << " ";
                  if (word == "..")
                  {
                        if (!q.empty()) q.pop_back();
                  }
                  else if (word == "." || size(word) == 0)
                  {
                        continue;
                  }
                  else q.push_back(word);
            }

            word = "/";

            while (!q.empty())
            {
                  // cout << q.front() << " ";
                  word += q.front();
                  word += '/';
                  q.pop_front();
            }

            if (size(word) > 1)
                  word.pop_back();

            return word;
      }
};