// Question 1b - TRI A BULLES OPTIMISE

void optbull(int *vec, int n){
    int stop = 0;
    int m = n - 1;
    while(stop == 0){
        int swap = 0;
        for(int i = 0; i < m; i++){
            if(vec[i] > vec[i+1]){
                int y = vec[i];
                vec[i] = vec[i+1];
                vec[i+1] = y;
                swap = 1;
            }
        }
        m--;
        if(swap == 0) stop = 1;
    }
}