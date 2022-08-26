class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mm;
        for(auto &ch : text) mm[ch]++;
        return min ( { mm['b'] , mm['a'] , mm['l']/2 , mm['o']/2 ,mm['n'] } ) ;
    }
};