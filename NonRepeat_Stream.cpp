/*http://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream/0*/

#include <iostream>
using namespace std;

int map[26];
int ra[26];
int hd, tl;
char str;
int main() {
    //code
    int i,T, len;
    cin >> T;
    while(T--)
    {
        for( i=0; i <26; ++i){
            map[i]=0;
            ra[i]= -1;
        }
        hd = tl = 0;
        cin >> len;
        
        for (i = 0; i < len; ++i)
        {
            cin >> str;
            if( map[str - 'a'] == 0)
                map[str - 'a'] = 1;
            else if (map[str - 'a'] == 1)
                map[str - 'a'] = 2;

            if (map[str - 'a'] == 1)
                ra[str - 'a'] = i + 1;
            else
                ra[str - 'a'] = -1;

            // check for first non repeating
            char minC= '0';
            int minI = 501;
            for (int j = 0; j < 26; ++j)
            {
               
                if ((ra[j] < minI) && (ra[j] != -1))
                {
                    minI = ra[i];
                    minC = char(j + 'a');
                }
            }
            if (minC == '0')
                cout << -1 << " ";
            else
                cout << minC << " ";
        }
        cout << endl;

    }
    return 0;
}
