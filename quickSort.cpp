class QuickSort {
public:
    int partition(int* A,int left,int right)
    {
        int ch=left-1;
        int piv=A[right];
        for(int i=left;i<=right;i++)
        {
            if(A[i]<piv)
            {
                int tmp=A[i];
                A[i]=A[++ch];
                A[ch]=tmp;
            }          
        }
        int tmp=A[right];
        A[right]=A[ch+1];
        A[ch+1]=tmp;
        return ch+1;
    }
    void quicksort(int* A,int left,int right)
    {
        if(left<right)
        {
            int mid=partition(A,left,right);
            quicksort(A,left,mid-1);
            quicksort(A,mid+1,right);
        }
    }
    int* quickSort(int* A, int n) {
        // write code here
        quicksort(A,0,n-1);
        return A;
    }
};
