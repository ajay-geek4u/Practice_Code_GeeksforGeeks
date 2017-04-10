
/* http://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1 
Count distinct elements in every window*/
#include <iostream>
#include <string>
//#include <map>
using namespace std;
int nl[101];
int n, k;
int l[101];

int main()
{
    int t, tmp;
    cin >> t;
    while (t--)
    {
        //init map
        for (int j = 0; j <= 100; ++j)
            nl[j] = 0;

        cin >> n >> k;
        int dCnt = 0;
        for (int i = k - 1; i < n; ++i)
        {
            // Input list
            l[i] = tmp;
            if (i < k - 1)
            {
                nl[tmp]++;
                continue;
            }

            // checking for first k window
            if (i == k - 1)
            {
                nl[tmp]++;
                for (int ki = 0; ki <= 100; ++ki)
                {
                    if (nl[ki] > 0)
                        dCnt++;
                }

                cout << dCnt << " ";
                continue;
            }
            // from k+1th input
            // taking care of the new input
            if (nl[tmp] == 0)// new entry
            {
                dCnt++;
            }
            nl[tmp]++;


            //taking care of the entry not part of k window
            if (nl[l[i - k]] == 1) // if it was contributing to distinct list
            {
                dCnt--;
            }
            nl[l[i - k]]--;


            cout << dCnt << " ";
        }
        cout << endl;
    }
    return 0;
}


/*You are required to complete below method */
void countDistinct(int A[], int k, int n)
{

    //Your code here
    int nl[101];
    int dCnt = 0;
    for (int j = 0; j <= 100; ++j)
        nl[j] = 0;
    for (int i = 0; i < n; ++i)
    {
        // Input list

        if (i < k - 1)
        {
            nl[A[i]]++;
            continue;
        }

        // checking for first k window
        if (i == k - 1)
        {
            nl[A[i]]++;
            for (int ki = 0; ki <= 100; ++ki)
            {
                if (nl[ki] > 0)
                    dCnt++;
            }

            cout << dCnt << " ";
            continue;
        }
        if (nl[A[i]] == 0)// new entry
        {
            dCnt++;
        }
        nl[A[i]]++;


        //taking care of the entry not part of k window
        if (nl[A[i - k]] == 1) // if it was contributing to distinct list
        {
            dCnt--;
        }
        nl[A[i - k]]--;


        cout << dCnt << " ";
    }

}
