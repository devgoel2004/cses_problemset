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

void hareKrishna(){
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];

    ll low = 1;
    ll high = (*min_element(a.begin(), a.end())) * k;
    ll ans = high;

    while(low <= high){
        ll mid = low + (high - low) / 2;

        if(check(mid, a, k)){
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
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