#include <iostream>

using namespace std;


void citire(int (&M)[5][5])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cout << "M[" << i << "][" << j << "]=";
            cin >> *(M+i*n+j);
        }
}

void afisare()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cout << *(M + i*m + j) << endl;
        }
}
int main()
{
    int n, m;
    cout << "Introduceti numarul de linii: ";
    cin >> n;
    cout << "Introduceti numarul de coloane: ";
    cin >> m;
    int *M = new int[n * m];
    citire(M);
}