class HeapSort {
public:
    void swap(int &a, int &b){
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
    void heapAdjust(int *A, int n){
    	int temp;
        for (int i=n/2-1; i>=0; i--){
            if (2*i+2 > n-1){
                temp = 2*i+1; // n-1
            }else {
                temp = A[2*i+1]>A[2*i+2]?2*i+1:2*i+2;
            }
            if (A[temp] > A[i]){
                swap(A[i], A[temp]);
            }            
        }
    }
    
    int* heapSort(int* A, int n) {
        // write code here
        if (A==NULL || n<=1){
            return A;
        }
        for (int i=n; i>0; i--){
            heapAdjust(A, i);
            swap(A[0], A[i-1]);            
        }
        return A;
    }
};
