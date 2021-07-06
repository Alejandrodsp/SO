#include <stdio.h>
#include <malloc.h>
#include <iostream>
#include "exemplos.h"
#include "minhaBiblioteca.h"

using namespace std;

int main()
{
    int n, *r, tId, escolha, pvs;
    struct Atrib a;

    r = (int *)malloc(sizeof(int));

    while (true) {

        cout << endl
        << "    1 - Fibonacci\n"
        << "    2 - Fatorial\n"
        << "    3 - Soma\n"
        << "    Outro - Sair\n"
        << "Escolha: ";
        cin >> escolha;

        if (escolha != 1 && escolha != 2 && escolha != 3)
            break;

        cout << endl
        << "Escolha a quantidade de pvs: ";
        cin >> pvs;

        cout << endl
        << "Escolha um valor para n: ";
        cin >> n;

        start(pvs);
        a.p = 0;
        a.c = n;

        if (escolha == 1) 
            tId = spawn(&a, fibo, &n);
        else if (escolha == 2)
            tId = spawn(&a, fat, &n);
        else
            tId = spawn(&a, soma, &n);
                        
        sync(tId, (void **)&r);

        finish();

        if (escolha == 1)
            printf("\nFibonacci(%d) = %d\n", n, *r);
        else if (escolha == 2)
            printf("\nFatorial(%d) = %d\n", n, *r);
        else
            printf("\nSoma(%d) = %d\n", n, *r);
            
    }

    free(r);
    return 0;
}

