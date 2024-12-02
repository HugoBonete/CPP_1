#include <iostream>

using namespace std;

float Csuma(int *xvect, float *p, int k)
{
    int suma = 0;
    for(int i = 0; i <= k; i++)
    {
        if (xvect[i] == 1)
        {
            suma += p[i];
        }
    }
    return suma;
}

void mochila(float m, float *p, float *v, int *xvect, int k, int *xopt, float &vopt, int n)
{
    int i;
    float peso, valor;
    if(k <= n)
    {
        for (i = 0; i <= 1; i++)
        {
            xvect[k] = i;
            peso = Csuma(xvect, p, k);
            if(peso <= m)
            {
                if(k == n)
                {
                    valor = Csuma(xvect, v, k);
                    if(valor > vopt)
                    {
                        for(int u = 1; u <= n; u++)
                        {
                            xopt[u] = xvect[u];
                        }
                        vopt = valor;
                    }
                }else
                {
                    mochila(m, p, v, xvect, k+1, xopt, vopt, n);
                }
            }
        }
    }
    cout << "\n";
        for(int i = 1; i <= n; i++)
        {
            cout << xopt[i] << " ";
        }
        cout << vopt;  
}

int main()
{
    float *p, *v;
    float vopt = 0;
    int m, peso, valor, n, *xvect, *xopt, k = 1;

    cout << "Introduzca el peso maximo de la mochila: \n";
    cin >> m;
    cout << "Introduzca el numero total de objetos: \n";
    cin >> n;

    xvect = new int [n + 1];
    xopt = new int[n + 1];
    p = new float[n + 1];
    v = new float[n + 1];

    for(int j = 1; j <= n; j++)
    {
        cout << "Introduzca el peso del objeto numero " << j << "\n";
        cin >> peso;
        p[j] = peso;
    }
    for(int s = 1; s <= n; s++)
    {
        cout << "Introduzca el valor del objeto numero " << s << "\n";
        cin >> valor;
        v[s] = valor;
    }
    for(int i = 0; i <= n; i++)
    {
        xopt[i] = 0;
        xvect[i] = 0;
    }

    for(int y = 1; y <= n; y++)
    {
        cout << "\nObjeto numero: " << y << "\n";
        cout << "Tiene un peso de: " << p[y] << "\n";
        cout << "Tiene un valor de: "<< v[y] << "\n";
    }

    mochila(m, p, v, xvect, k, xopt, vopt, n);
    cout << "\nEl Voptimo es: " << vopt << "\n";

    for(int r = 1; r <= n; r++)
    {
        if(xopt[r] == 1)
        {
            cout << xopt[r] << ", ";
        }else
        {
            cout << "0, ";
        }
    }

    return 0;
}