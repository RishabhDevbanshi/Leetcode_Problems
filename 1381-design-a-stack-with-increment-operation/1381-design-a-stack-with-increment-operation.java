class CustomStack {
    int[] arr;
    int idx = 0;
    int count = -1;
    int n;

    public CustomStack(int maxSize) {
        n = maxSize;
        arr = new int[n];
        for(int i=0;i<n;i++)
            arr[i] = 0;
    }

    public void push(int x) {
        if (count < n - 1) {
            arr[++count] = x;
        }
    }

    public int pop() {
        if (count > -1) {
            count--;
            return arr[count + 1];
        }
        return -1;
    }

    public void increment(int k, int val) {
        int temp = 0;
        while (temp <= count && k-- > 0) {
            arr[temp] = arr[temp] + val;
            temp++;
        }
    }
}
