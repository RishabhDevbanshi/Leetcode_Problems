class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //When our maxHeap is empty then just push the number inside it or when the number is less than top of th maxHeap then push it inside maxHeap.
        if(maxHeap.empty() || num < maxHeap.top()){
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);
        }
        
        //Size is not same
        //There are two cases arises:
        //Case 1: size of maxHeap > size of minHeap i.e. Differences between their size is 2
        if(maxHeap.size() > minHeap.size()+1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        //Case 2: size of minHeap > size of maxHeap
        else if(minHeap.size() > maxHeap.size()+1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        
    }
    
    double findMedian() {
        //When minHeap and maxHeap have same size then there are two middle elements so by taking average of two, we get our median
        if(maxHeap.size() == minHeap.size())
            return (maxHeap.top() + minHeap.top())/2.0;
    //If maxHeap has one more element than minHeap then it's our median;
        else if(maxHeap.size() > minHeap.size())
            return maxHeap.top();
    
    //If minHeap has one more element than maxHeap then it's our median
        return minHeap.top();
    }
};