class Solution {
public:
    string intToRoman(int num) {
        int level  = 0;
        
        string res = "";
        
        while(num)
        {
            int dig = num%10;
            num /= 10;
            
            if(level == 0)
            {
                if(dig < 4)
                {
                    while(dig--)
                        res += 'I';
                }
                else if(dig == 4)
                {
                    res += "IV";
                }
                else if(dig == 5)
                {
                    res += "V";
                }
                else if(dig < 9)
                {
                    res += "V";
                    dig -= 5;
                    while(dig--)
                        res += 'I';
                }
                else if(dig == 9)
                {
                    res += "IX";
                }
            }
            else if(level == 1)
            {
                if(dig < 4)
                {
                    while(dig--)
                        res = "X" + res;;
                }
                else if(dig == 4)
                {
                    res = "XL" + res;
                }
                else if(dig == 5)
                {
                    res = "L" + res;
                }
                else if(dig < 9)
                {
                    string tmp = "L";
                    dig -= 5;
                    while(dig--)
                        tmp += 'X';
                    res = tmp +  res;
                }
                else if(dig == 9)
                {
                    res = "XC" + res;
                }
            }
            else if(level == 2)
            {
                if(dig < 4)
                {
                    while(dig--)
                        res = "C" + res;
                }
                else if(dig == 4)
                {
                    res = "CD" + res;
                }
                else if(dig == 5)
                {
                    res = "D" + res;
                }
                else if(dig < 9)
                {
                    string tmp = "D";
                    dig -= 5;
                    while(dig--)
                        tmp += 'C';
                    res = tmp + res;
                }
                else if(dig == 9)
                {
                    res = "CM" + res;
                }
            }
            else
            {
                while(dig--)
                    res = 'M' + res;
            }
            
            ++level;
        }
        
        return res;
    }
};