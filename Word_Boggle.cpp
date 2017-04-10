#include <iostream>
#include <string>
#include <map>
using namespace std;

map <string, bool> l;

char g[8][8];
int t, dl, m, n;
bool sC[11];

int v[8][8];
char cStr[50];
int cPtr;


bool check(int i, int j)
{
    if (i >= 0 && i < n)
    {
        if (j >= 0 && j < m)
            return 1;
    }
    return 0;
}

void cWord(int cLen, map<string, bool>::iterator itr )
{
    if ((itr->first).length() == cLen)
    {
        for (int i = 0; i < cLen; ++i)
        {
            if (cStr[i] != (itr->first)[i]) // no match
                break;
            if (i == cLen - 1) // string match
                itr->second = 1;
        }
    }

}

void cDfs(int i, int j, map<string, bool>::iterator itr )
{
    v[i][j] = 1;

    cStr[cPtr++] = g[i][j];

    //check
    cWord(cPtr, itr);

    if (cPtr < itr->first.length())
    {
        //traverse 8 neighbours
        if (!v[i - 1][j] && check(i - 1, j))
            cDfs(i - 1, j, itr);
        if (!v[i][j - 1] && check(i, j - 1))
            cDfs(i, j - 1, itr);
        if (!v[i + 1][j] && check(i + 1, j))
            cDfs(i + 1, j, itr);
        if (!v[i][j + 1] && check(i, j + 1))
            cDfs(i, j + 1, itr);
        if (!v[i - 1][j - 1] && check(i - 1, j - 1))
            cDfs(i - 1, j - 1, itr);
        if (!v[i - 1][j + 1] && check(i - 1, j + 1))
            cDfs(i - 1, j + 1, itr);
        if (!v[i + 1][j - 1] && check(i + 1, j - 1))
            cDfs(i + 1, j - 1, itr);
        if (!v[i + 1][j + 1] && check(i + 1, j + 1))
            cDfs(i + 1, j + 1, itr);

    }
    // rollback
    cPtr--;
    v[i][j] = 0;
}


void wDfs(char c, map<string, bool>::iterator itr )
{
    for (int k = 0; k < n; k++)
    {
        for (int q = 0; q < n; q++)
        {
            v[k][q] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (c == g[i][j])
            {
                cPtr = 0;
                cDfs(i, j, itr);
            }
        }
    }

}

int main()
{

    cin >> t;
    string tmp;
    while (t--)
    {
        cin >> dl;
        for (int i = 0; i < dl; ++i)
        {
            cin >> tmp;
            l[tmp] = 0;
        }

        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> g[i][j];
            }
        }
        map<string, bool>::iterator itr = l.begin();
        //dfs and word check
        for (int i = 0; i < dl && itr != l.end(); ++i, ++itr)
        {
            wDfs((itr->first)[0], itr);
        }

        //print found words
        bool ch = 0;
        for (itr = l.begin(); itr != l.end(); itr++)
        {
            if (itr->second == 1)
            {
                ch = 1;
                cout << itr->first << " ";
            }
        }
        if(!ch)
            cout<< -1;

        l.clear();
        cout<< endl;
    }

    return 0;
}
