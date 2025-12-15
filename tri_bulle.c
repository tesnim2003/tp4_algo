// Question 1a - TRI A BULLES

void bull(int *vec, int n){
    int stop = 0;
    while(stop == 0){
        int swap = 0;
        for(int i = 0; i < n - 1; i++){
            if(vec[i] > vec[i+1]){
                int y = vec[i];
                vec[i] = vec[i+1];
                vec[i+1] = y;
                swap = 1;
            }
        }
        if(swap == 0) stop = 1;
    }
}