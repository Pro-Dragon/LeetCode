bool threeConsecutiveOdds(int* arr, int arrSize) {
    int i=0;
    while(i<arrSize-2){
        if(arr[i]%2&&arr[i+1]%2&&arr[i+2]%2){
           return 1;
        }
        i++;
    }
    return 0;
}