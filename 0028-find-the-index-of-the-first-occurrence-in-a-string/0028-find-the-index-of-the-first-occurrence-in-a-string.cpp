class Solution {
public:
    int strStr(string A, string B) {
        if(size(B) > size(A))
            return -1;

        deque<char> q,qq;
        for(char ch : B)
            qq.push_back(ch);

        // cout << size(qq) << "\n";
        // disp(qq);

        int i=0 , sz = size(B);
        while(i<sz)
            q.push_back(A[i++]);

        // disp(qq);

        if(q == qq)
            return 0;

        // disp(q);

        int res = 0;

        while(i<size(A))
        {
            q.pop_front();
            q.push_back(A[i++]);
            res++;

            // disp(q);

            if(q == qq)
                return  res;
        }

        // cout << "here\n";

        return -1;

    }
};