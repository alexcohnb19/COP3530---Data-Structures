int* selection_sort_array(int arr[], int size){
    int minIndex;
    int temp;
    for(int i = 0; i < size-1; i++){
        minIndex = i;
        for(int j = i+1; j < size; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        //swap(arr[minIndex],arr[i]);
    }


    // Add your code above this line. Do not modify any other code.
    /* save the sorted array in int arr[] and return the same array */
    return arr;
}