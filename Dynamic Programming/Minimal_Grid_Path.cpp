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
    int n;
    cin>>n;
    vector<string>a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<string>>dp(n+1, vector<string>(n+1));
    dp[0][0]=string(1,a[0][0]);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 and j==0){
                continue;
            }
            string right="",down="";
            if(i-1>=0){
                down = dp[i-1][j] + a[i][j];
            }
            if(j-1>=0){
                right = dp[i][j-1] + a[i][j];
            }
            if(right.empty()){
                dp[i][j] = down;
            }
            else if(down.empty()){
                dp[i][j] = right;
            }
            if(down!="" and right != ""){
                dp[i][j] = min(down, right);
            }
        }
    }
    cout<<dp[n-1][n-1]<<'\n';
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