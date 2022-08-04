#include <bits/stdc++.h>
using namespace std;

int calc_d(int e, int phi)
{
    int i = 0;
    for (i = 1; i <= phi; i++)
    {
        if (((e * i) % phi) == 1)
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    long int p, q;
    cout << "enter two large prime numbers : ";
    cin >> p;
    cin >> q;
    long int n = p * q;
    long int phi = (p - 1) * (q - 1);
    cout << "enter the vaue for e : ";
    int e;
    cin >> e;
    int d = calc_d(e, phi);
    cout << "Public key : {" << e << "," << n << "}" << endl;
    cout << "Private key : {" << d << "," << n << "}" << endl;
    cout << "enter the msg to be encrypted : ";
    int msg;
    cin >> msg;
    long ct = (long)(pow(msg, e)) % n;
    long pt = (long)(pow(ct, d)) % n;
    cout << "encrypted text : " << ct << endl
         << "decrypted text : " << pt << endl;
}