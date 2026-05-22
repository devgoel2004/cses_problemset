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
vector<ll>fact(1e6+1,1);
vector<ll>invfact(1e6+1,1);
void printArray(vector<ll>&v){
    for(auto x:v){
        cout<<x<<' ';
    }
    cout<<'\n';
}

// function to find the modulo inverse
ll mminvprime(ll x, ll m){
    ll b = m-2;
    ll res = 1;
    while(b>0){
        if(b&1){
            res = (res%m * x%m)%m;
        }
        x = (x%m*x%m)%m;
        b>>=1;
    }
    return res;
}
// Hashing to store the unique integer for each and every string.
struct Hashing{
    // ll n;
    vector<ll>hash;
    vector<ll>powers;
    vector<ll>inversePowers;
    vector<ll>pref;
    ll p = 31;

    Hashing(string s){
        ll n = s.size();
        hash.resize(n,0);
        powers.resize(n+1,1);
        inversePowers.resize(n+1,1);
        pref.resize(n,0);
        for(ll i=1;i<=n;i++){
            powers[i] = (powers[i-1]%M * p%M)%M;
        }
        inversePowers[n] = mminvprime(powers[n],M);
        for(ll i=n-1;i>=0;i--){
            inversePowers[i] = (inversePowers[i+1]%M*p%M)%M;
        }
        for(ll i=0;i<n;i++){
            hash[i] = ((s[i]-'a'+1)*powers[i])%M;
        }
        pref[0]=hash[0];
        for(ll i=1;i<n;i++){
            pref[i] = (pref[i-1]%M + hash[i]%M)%M;
        }
    }
    ll substringHash(ll l, ll r){
        ll val1 = pref[r];
        ll val2 = l>0?pref[l-1] : 0LL;
        ll temp = (val1%M - val2%M + M)%M;
        ll hash_value = (temp%M * inversePowers[l]%M)%M;
        return hash_value;
    }
    ll combineSubstringHash(ll l1, ll r1, ll l2, ll r2){
        ll hash1 = substringHash(l1,r1);
        ll hash2 = substringHash(l2,r2);
        ll hash = (hash1%M + (powers[r1-l1+1]%M * hash2%M)%M)%M;
        return hash;
    }
    ll RotatedShiftHash(ll shift, ll l, ll r, string s){
        ll n = s.size();
        ll newL = l+shift;
        ll newR = r+shift;
        ll leftHash = hash[newL];
        ll rightHash = 0;
        // there are two cases where newR<=n-1 or newR >= n
        if(newR<=n-1){
            return substringHash(newL, newR);
        }else{
            return combineSubstringHash(newL, n-1, 0, newR%n);
        }
    }
};
char charAtIndexInShift(string s, ll index, ll shift, ll n){
    return s[(index+shift)%n];
}
// to find the smallest shift that is used to find position at which lexicographically is smallest.
bool isSmallestShift(ll shift1, ll shift2, string &s, ll n, Hashing &hs){
    if(hs.RotatedShiftHash(shift1,0,n,s)== hs.RotatedShiftHash(shift2,0,n,s)){
        return false;
    }
    ll start = 0, end = n-1;
    ll position=n-1;
    while(start<=end){
        ll mid = start+(end-start)/2;
        if(hs.RotatedShiftHash(shift1,0,mid,s) == hs.RotatedShiftHash(shift2,0,mid,s)){
            start = mid+1;
        }else{
            position = mid;
            end = mid-1;
        }
    }
    return charAtIndexInShift(s,position,shift1,n) < charAtIndexInShift(s,position,shift2,n);
}
void hareKrishna(){
    string s;
    cin>>s;
    ll n = s.size();
    Hashing hs = Hashing(s);
    ll best_shift = 0;
    for(ll i=0;i<n-1;i++){
        if(isSmallestShift(i,best_shift,s,n,hs)){
            best_shift = i;
        }
    }
    string prefix = s.substr(0,best_shift);
    string suffix = s.substr(best_shift, n- best_shift);
    string ans = suffix + prefix;
    cout<<ans<<'\n';
}
int main(){
    hareKrishna();
    return 0;
}