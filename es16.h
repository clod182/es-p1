#ifndef ES_16_H
#define ES_16_H

struct oggetto {
    int peso;
    int valore;
};

struct moneta {
    int valore;
    int quantita;
};

int zaino(struct oggetto v[], int n, int p);
int combinazioni_monete(struct moneta m[], int n, int somma);

#endif
