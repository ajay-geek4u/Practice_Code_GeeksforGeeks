//easiest ones
#include <iostream>
using namespace std;
//bool g[41][41];

int main() {
	//code
	int T;
	cin >> T;
	while(T--)
	{
	   int r, c, i, j, v;
	   cin >> r >> c;
	   int iCnt = -1, gCnt=0, cnt;
	   
	   for( i=0 ;i < r; ++i)
	   {
	       cnt = 0;
	       for(j=0; j < c; ++j)
	       {
	           cin >> v;
	           if(v)
	            cnt ++;
	   
	       }
	       
	       if(cnt > gCnt)
	       {
	           gCnt = cnt;
	           iCnt = i;
	       }
	   }
	   cout<<iCnt<<endl;
	}
	return 0;
}
