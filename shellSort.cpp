class ShellSort {
public:
    int* shellSort(int* A, int n) {
        // write code here
        if(A == NULL || n < 2) return A;
        int step = n / 2;
        while(step > 0)
            {
            for(int i = step;i < n;i += step)
                for(int j = i - step; j >= 0;j--)
                if(A[j + step] < A[j])
                  swap(A[j + step],A[j]);
                else
                  break;
             
            step /= 2;
        }
        return A;
    }
};
