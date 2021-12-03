#include<bits/stdc++.h>
using namespace std;
//Welcome To Hridoy's Code
#define   ll                  long long
#define   ull                 unsigned long long
#define   pb                  push_back
#define   em                  emplace_back
#define   ff                  first
#define   ss                  second
#define   endl                "\n"
#define   all(v)              (v.begin(), v.end())
#define   rall(v)             (v.rbegin(), v.rend())
#define   pi                  acos(-1.0)
#define   LCM(LCM_X,LCM_Y)    (LCM_X/__gcd(LCM_X,LCM_Y))*LCM_Y
#define   FastRead   ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
const int MOD = (int)1e9+7;
const int MAX = 1e6;
double power (int b, int p)
{
    double ret = 1;

    for ( int i = 1; i <= p; i++ )
        ret *= b;

    return ret;
}

int main ()
{
    FastRead
    int stones;
    int cases = 0;

    while ( scanf ("%d", &stones) && stones ) {
        int x [200 + 10];
        int y [200 + 10];

        for ( int i = 0; i < stones; i++ ) scanf ("%d %d", &x [i], &y [i]);

        double d [200 + 10] [200 + 10];

        for ( int i = 0; i < stones; i++ ) {
            for ( int j = i + 1; j < stones; j++ )
                d [i] [j] = d [j] [i] =sqr(power (x [i] - x [j], 2) + power (y [i] - y [j], 2));
        }

        for ( int k = 0; k < stones; k++ ) {
            for ( int i = 0; i < stones; i++ ) {
                for ( int j = 0; j < stones; j++ )
                    d [i] [j] = min (d [i] [j], max (d [i] [k], d [k] [j]));
            }
        }

        printf ("Scenario #%d\n", ++cases);
        printf ("Frog Distance = %.3lf\n\n", d [0] [1]);

    }

    return 0;
}
