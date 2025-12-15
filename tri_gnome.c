// Question 2 - TRI GNOME

void gnome(int *vec, int n){
    int i = 0;
    while(i < n - 1){
        if(vec[i] <= vec[i+1]) i++;
        else {
            int t = vec[i];
            vec[i] = vec[i+1];
            vec[i+1] = t;
            if(i > 0) i--;
        }
    }
}