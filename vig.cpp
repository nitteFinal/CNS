#include <bits/stdc++.h>
using namespace std;

int main()
{

    string key, text;
    cout << "enter key:";
    cin >> key;
    cout << "enter text:";
    cin >> text;
    int keylen = key.length();
    int l = 0;
    string encrypt = "";
    while (key.length() < text.length())
    {
        key += key[l];
        l = (l + 1) % keylen;
    }
    for (int i = 0; i < text.length(); i++)
    {
        encrypt += (char)((text[i] - 'A' + key[i] - 'A') % 26 + 65);
    }

    string decrypt = "";

    for (int i = 0; i < text.length(); i++)
    {
        int res = (encrypt[i] - 'A') - (key[i] - 'A');
        if (res >= 0)
            decrypt += (char)(res % 26 + 65);
        else
        {
            res = 26 - abs(res) % 26;
            decrypt += (char)(res % 26 + 65);
        }
    }

    cout << key << endl
         << text << endl
         << encrypt << endl
         << decrypt << endl;

    // char mat[26][26];
    // int k = 0, m = 0;
    // for (int i = 0; i < 26; i++)
    // {
    //     for (int j = 0; j < 26; j++)
    //     {
    //         mat[i][j] = (char)(k + 65);
    //         k = (k + 1) % 26;
    //     }
    //     m++;
    //     k = m;
    // }
    // for (int i = 0; i < 26; i++)
    // {
    //     for (int j = 0; j < 26; j++)
    //     {
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
