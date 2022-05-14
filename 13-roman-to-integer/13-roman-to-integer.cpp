class Solution {
public:
    int romanToInt(string str) {
        int i=0;
        int res = 0;
        while(i<size(str))
        {
            if(str[i] == 'I')
            {
                if(i+1 < size(str))
                {
                    if(str[i+1] == 'I')
                    {
                        if(i+2 < size(str) and str[i+2] == 'I')
                        {
                            res = res + 3;
                            i += 3;
                        }
                        else
                        {
                            res = res + 2;
                            i+=2;
                        }
                    }
                    else if(str[i+1] == 'V')
                    {
                        res = res + 4;
                        i+=2;
                    }
                    else if(str[i+1] == 'X')
                    {
                        res = (res) +9;
                        i+=2;
                    }
                    else
                    {
                        res = (res) + 1;
                        i++;
                    }
                }
                else
                {
                    res = (res) + 1;
                    i++;
                }
            }
            else if(str[i] == 'X')
            {
                if(i+1<size(str) and str[i+1] == 'L')
                {
                    res = (res) + 40;
                    i+=2;
                }
                else if(i+1<size(str) and str[i+1] == 'C')
                {
                    res = (res) + 90;
                    i += 2;
                }
                else
                {
                    res = (res) + 10;
                    i++;
                }
            }
            else if(str[i] == 'C')
            {
                if(i+1<size(str) and str[i+1] == 'D')
                {
                    res = (res) + 400;
                    i += 2;
                }
                else if(i+1 < size(str) and str[i+1] == 'M')
                {
                    res = (res) + 900;
                    i += 2;
                }
                else
                {
                    res = (res) + 100;
                    i++;
                }
            }
            else if(str[i] == 'V')
                res = (res) + 5 , i++;
            else if(str[i] == 'L')
                res = (res) + 50 , i++;
            else if(str[i] == 'D')
                res = (res) + 500 , i++;
            else if(str[i] == 'M')
                res = (res) + 1000 , i++;
        }

	// print(res);
        return res;
    }
};