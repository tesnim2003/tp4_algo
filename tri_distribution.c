// Question 3 - TRI PAR DISTRIBUTION (RADIX / BASE 10)

#include <stdlib.h>


int cle(int x, int i){
    while(i-- > 0) x /= 10;
    return x % 10;
}


void TriAux(int *T, int n, int i){
    int count[10] = {0};
    int *out = malloc(sizeof(int) * n);

    for(int j = 0; j < n; j++){
        int d = cle(T[j], i);
        count[d]++;
    }

    for(int d = 1; d < 10; d++)
        count[d] += count[d-1];

    for(int j = n-1; j >= 0; j--){
        int d = cle(T[j], i);
        out[count[d] - 1] = T[j];
        count[d]--;
    }

    for(int j = 0; j < n; j++)
        T[j] = out[j];

    free(out);
}

// Question 3c: TriBase - applique TriAux pour tous les chiffres
void TriBase(int *T, int n, int k){
    for(int i = 0; i < k; i++)
        TriAux(T, n, i);
}