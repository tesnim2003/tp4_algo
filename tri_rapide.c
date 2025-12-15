// Question 4 - TRI RAPIDE (QUICK SORT)

int partition(int *arr, int n){
    int pivot = arr[n-1];
    int i = -1;

    for(int j = 0; j < n-1; j++){
        if(arr[j] <= pivot){
            i++;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }

    int t = arr[i+1];
    arr[i+1] = arr[n-1];
    arr[n-1] = t;

    return i+1;
}

void quickSort(int *arr, int n){
    if(n < 2) return;
    int pi = partition(arr, n);
    quickSort(arr, pi);
    quickSort(arr + pi + 1, n - pi - 1);
}