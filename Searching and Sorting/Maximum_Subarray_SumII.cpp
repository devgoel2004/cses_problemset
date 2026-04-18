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
using namespace std;
#define pb push_back
#define ll long long
#define endl '\n'
#define F first
#define S second
#define range(a,i,n) for(int i=a;i<n;i++)
#define e end
#define INF INT64_MAX
// #define decimal cout<<setprecision(15)<<fixed
void decimal(ll x){
    cout<<setprecision(x)<<fixed;
}bool check(ll mid, vector<ll>& a, ll k){
    ll sum = 0;
    for(ll i = 0; i < a.size(); i++){
        sum += mid / a[i];
        if(sum >= k) return true;
    }
    return false;
}
ll leftSum=0, rightSum=0;

void hareKrishna(){
    ll n,a,b;
    cin>>n>>a>>b;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<ll> pref(n+1,0);
    // pref[0] = arr[0];
    for(ll i=0;i<n;i++){
        pref[i+1] = pref[i] + arr[i];
    }
    deque<ll>dq;
    ll k = b-a+1;
    ll ans= LLONG_MIN;
    for(ll i=a;i<=n;i++){
        if(!dq.empty() and dq.front()<i-b){
            dq.pop_front();        
        }
        while(!dq.empty() and pref[dq.back()]>= pref[i-a]){
            dq.pop_back();
        }
        dq.push_back(i-a);
        ans = max(ans, pref[i] - pref[dq.front()]);
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    // cin >> t;
    while(t--){
        hareKrishna();
    }

    return 0;
}