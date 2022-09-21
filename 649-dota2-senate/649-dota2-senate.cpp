class Solution {
public:
    string predictPartyVictory(string senate) {
        set<int> r,d;

        for(int i=0;i<size(senate);i++)
        {
            if(senate[i] == 'R') r.insert(i);
            else d.insert(i);
        }

        while(size(r) and size(d))
        {
            for(int i=0;i<size(senate);i++)
            {
                 if(senate[i] == 'R' and r.find(i) != r.end() and size(d))
                 {
                    if(d.upper_bound(i) != d.end())
                        d.erase(d.upper_bound(i));
                    else d.erase(d.begin());
                 }
                 else if(senate[i] == 'D' and d.find(i) != d.end() and size(r))
                 {
                    if(r.upper_bound(i) != r.end())
                        r.erase(r.upper_bound(i));
                    else r.erase(r.begin());
                 } 
            }
        }

        return size(r) ? "Radiant" : "Dire";
    }
};