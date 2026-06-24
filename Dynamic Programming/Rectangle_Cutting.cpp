#include <iostream>     // cin, cout
#include <vector>       // vector
#include <array>        // array
#include <deque>        // deque
#include <queue>        // queue, priority_queue
#include <stack>        // stack
#include<unordered_set>
#include <set>          // set, multiset
#include <map>          // map, multimap
#include <unordered_set>
#include <unordered_map>
#include <algorithm>    // sort, reverse, lower_bound, upper_bound
#include <numeric>      // accumulate, gcd
#include <cmath>        // sqrt, pow
#include <cstring>      // memset
#include <string>       // string
#include <climits>      // INT_MAX, LLONG_MAX
#include <limits>       // numeric_limits
#include <iomanip>      // setprecision
#include <cassert>      // assert
#include <functional>   // greater, less
#include <bitset>       // bitset
#include <tuple>        // tuple
#include <random>       // random numbers
#include <chrono>       // time (useful for hacks)
#include<math.h>
#include <numeric>
#include<algorithm>
using namespace std;
#define pb push_back
#define ll long long
#define endl '\n'
#define F first
#define S second
#define range(a,i,n) for(int i=a;i<n;i++)
#define e end
#define INF INT64_MAX
#define mx(a) *max_element(a.begin(),a.end())
#define mn(a) *min_element(a.begin(),a.end())
const int dx[4] = { -1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const int MOD = 1e9+7;
char characterArray[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','P','Q','R','S','T','U','V','W','X','Z'};
char vowelArray[]={'A','E','I','O','U'};
const ll M = 1e9+7;
int delRow[]={-1,0,+1,0};
int delCol[]={0,-1,0,+1};
void init()
{
  #ifndef ONLINE_JUDGE
 
freopen("input.txt", "r", stdin);
 
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}
void hareKrishna() {
    ll n,m;
    cin>>n>>m;
    if(n>m){
        swap(n,m);
    }
    if(n==m){
        cout<<0<<'\n';
        return;
    }
    vector<vector<ll>>dp(n+1, vector<ll>(m+1,LLONG_MAX));
    for(ll i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(ll j=0;j<=m;j++){
        dp[0][j]=0;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(i==j){
                dp[i][j]=0;
                continue;
            }
            for(ll k=1;k<i;k++){   
                dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i-k][j]);
            }
            for(ll k=1;k<=j;k++){
                dp[i][j] = min(dp[i][j], 1+ dp[i][k] +  dp[i][j-k]);
            }
        }
    }
    cout<<dp[n][m]<<'\n';
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cout.precision(6); cout.setf(ios::fixed);
    cout.tie(NULL);
    ll t=1;
    // cin>>t;  
    while(t--){
        hareKrishna();
        // jaiShreeRam();
    }
    return 0;
}