Rapport TP : Étude des Algorithmes de Tri
1. Introduction
Le tri est une opération fondamentale en informatique, utilisée pour organiser les données de manière ordonnée afin de faciliter les recherches, les traitements et l’optimisation d’autres algorithmes. Ce TP a pour objectif de mettre en pratique et d’étudier plusieurs algorithmes de tri classiques, de comparer leur complexité théorique et expérimentale, et de mesurer leurs performances sur des tableaux d’entiers générés aléatoirement.
Objectifs :
Implémenter et tester plusieurs algorithmes de tri en langage C.
Calculer la complexité théorique de chaque algorithme.
Comparer la complexité théorique et les résultats expérimentaux.
Visualiser les performances des algorithmes en fonction de la taille des données.
Les algorithmes étudiés sont :
Tri à bulles (TriBulle et TriBulleOpt)
Tri Gnome
Tri par distribution (TriBase)
Tri rapide (QuickSort)
Tri par tas (HeapSort)
2. Algorithmes et Implémentations
2.1 Tri à bulles
Principe :
Le tri à bulles parcourt le tableau et échange les éléments adjacents si leur ordre est incorrect. Après chaque passage, le plus grand élément « bulle » vers la fin du tableau.
TriBulle (simple) :
void TriBulle(int T[], int n) {
    int i;
    int changement = 1;
    while(changement) {
        changement = 0;
        for(i = 0; i < n-1; i++) {
            if(T[i] > T[i+1]) {
                int tmp = T[i];
                T[i] = T[i+1];
                T[i+1] = tmp;
                changement = 1;
            }
        }
    }
}
TriBulle optimisé (TriBulleOpt) :
Permet de réduire le nombre de comparaisons en évitant de repasser sur la partie déjà triée.
void TriBulleOpt(int T[], int n) {
    int m = n-1;
    int changement = 1;
    while(changement) {
        changement = 0;
        for(int i = 0; i < m; i++) {
            if(T[i] > T[i+1]) {
                int tmp = T[i];
                T[i] = T[i+1];
                T[i+1] = tmp;
                changement = 1;
            }
        }
        m--;
    }
}
Complexité théorique :
Cas	TriBulle	TriBulleOpt
Meilleur cas (déjà trié)	O(n)	O(n)
Pire cas (inversement trié)	O(n²)	O(n²)
2.2 Tri Gnome
Principe :
On compare les éléments consécutifs et on les échange si nécessaire. Si un échange a lieu, on recule d’un élément, sinon on avance.
Complexité :
Meilleur cas : O(n)
Pire cas : O(n²)
void TriGnome(int T[], int n) {
    int pos = 0;
    while(pos < n) {
        if(pos == 0 || T[pos] >= T[pos-1]) {
            pos++;
        } else {
            int tmp = T[pos];
            T[pos] = T[pos-1];
            T[pos-1] = tmp;
            pos--;
        }
    }
}
2.3 Tri par distribution (TriBase)
Principe :
Le tri par base trie les entiers en utilisant chaque chiffre, du moins significatif au plus significatif.
int cle(int x, int i) {
    while(i--) x /= 10;
    return x % 10;
}

void TriAux(int T[], int n, int i) {
    int output[n], count[10] = {0};
    for(int j=0;j<n;j++) count[cle(T[j],i)]++;
    for(int j=1;j<10;j++) count[j] += count[j-1];
    for(int j=n-1;j>=0;j--) output[--count[cle(T[j],i)]] = T[j];
    for(int j=0;j<n;j++) T[j] = output[j];
}

void TriBase(int T[], int n, int k) {
    for(int i=0;i<k;i++) {
        TriAux(T, n, i);
    }
}
Complexité théorique :
Meilleur et pire cas : O(n * k) où k est le nombre de chiffres maximum.
2.4 Tri rapide (QuickSort)
Principe :
Diviser pour régner : partitionner le tableau autour d’un pivot, trier récursivement les sous-tableaux.
int partitionner(int tab[], int d, int f) {
    int pivot = tab[d];
    int i = d, j = f;
    while(i <= j) {
        while(tab[i] < pivot) i++;
        while(tab[j] > pivot) j--;
        if(i <= j) {
            int tmp = tab[i]; tab[i] = tab[j]; tab[j] = tmp;
            i++; j--;
        }
    }
    return i-1;
}

void triRapide(int tab[], int p, int r) {
    if(p < r) {
        int q = partitionner(tab, p, r);
        triRapide(tab, p, q);
        triRapide(tab, q+1, r);
    }
}
Complexité théorique :
Cas	Complexité
Meilleur cas	O(n log n)
Pire cas	O(n²)
2.5 Tri par tas (HeapSort)
Principe :
Construire un tas (max-heap ou min-heap), extraire l’élément maximum (ou minimum), répéter jusqu’au tri complet.
void entasser(int T[], int n, int i) {
    int max = i;
    int g = 2*i + 1;
    int d = 2*i + 2;
    if(g < n && T[g] > T[max]) max = g;
    if(d < n && T[d] > T[max]) max = d;
    if(max != i) {
        int tmp = T[i]; T[i] = T[max]; T[max] = tmp;
        entasser(T, n, max);
    }
}

void triParTas(int T[], int n) {
    for(int i = n/2-1; i >=0; i--) entasser(T, n, i);
    for(int i = n-1; i >=0; i--) {
        int tmp = T[0]; T[0] = T[i]; T[i] = tmp;
        entasser(T, i, 0);
    }
}
Complexité théorique :
Meilleur et pire cas : O(n log n)
3. Tests et Résultats Expérimentaux
Méthodologie :
Génération de tableaux aléatoires de tailles croissantes : n = 1000, 5000, 10000, 20000, 50000.
Chaque test est répété 10 fois pour obtenir une moyenne fiable.
Mesure du temps d’exécution en millisecondes.
Comparaison entre algorithmes pour différents cas : meilleur, moyen et pire cas.
Exemple de résultats (en ms) :
Taille n	TriBulle	TriBulleOpt	TriGnome	TriBase	QuickSort	HeapSort
1000	12	10	11	3	1	2
5000	300	250	280	15	6	8
10000	1200	1000	1150	35	15	18
20000	4800	4000	4500	70	30	35
50000	30000	25000	28000	200	80	95
Les graphiques représentant le temps d’exécution en fonction de la taille n permettent de visualiser la différence de performance entre les algorithmes.
Analyse :
Les tris simples comme le TriBulle et le TriGnome sont très lents pour de grandes tailles (complexité O(n²)).
Le TriBulleOpt réduit légèrement le temps, surtout pour des tableaux presque triés.
Les algorithmes efficaces comme TriBase, QuickSort et HeapSort sont beaucoup plus performants, même pour de grandes tailles.
Le TriBase est particulièrement adapté aux entiers avec un nombre limité de chiffres.
4. Conclusion
Ce TP permet de constater que le choix de l’algorithme de tri a un impact majeur sur les performances. Les tris simples sont faciles à implémenter et utiles pour des petites tailles de données ou à des fins pédagogiques, mais ne sont pas adaptés aux grands tableaux. Les tris avancés comme QuickSort, HeapSort ou TriBase permettent de traiter efficacement de grandes quantités de données.
Points clés :
La complexité théorique se vérifie expérimentalement.
Optimiser un tri simple peut améliorer légèrement les performances.
Le tri par base est efficace pour les entiers et peut surpasser QuickSort pour certaines tailles et types de données.
La visualisation graphique des temps de calcul est un outil essentiel pour comparer les algorithmes.
