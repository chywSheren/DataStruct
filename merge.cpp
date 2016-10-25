class MergeSort {
public:
    int* mergeSort(int* A, int n) {
        // write code here
        myMergeSort(A,0,n-1);
        return A;
    }
     
    void myMergeSort(int* A, int left, int right){
        if(left>=right){
            return;
        }else{
            int mid=(left+right)/2;
            myMergeSort(A, left, mid);
            myMergeSort(A, mid+1, right);
            merge(A, left, mid, right);
        }
    }
     
    void merge(int* A, int left, int mid, int right){
        int i=left, j=mid+1, k=0;
        int* temp = new int[right-left+1];
        while(i<=mid && j<=right){
            if(A[i]<=A[j]){
                temp[k++]=A[i++];
            }else{
                temp[k++]=A[j++];
            }
        }
        while(i<=mid){
            temp[k++]=A[i++];
        }
        while(j<=right){
            temp[k++]=A[j++];
        }
        for(i=0;i<k;i++){
            A[left+i]=temp[i];
        }
    }
};
