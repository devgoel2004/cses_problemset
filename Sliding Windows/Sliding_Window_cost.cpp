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
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    multiset<ll> left, right;
    auto balance = [&](){
        if(right.size()> left.size()){
            auto it = right.begin();
            leftSum += *it;
            rightSum -= *it;
            left.insert(*it);
            right.erase(it);
        }  
        else if(left.size() > right.size()+1){
            auto it = prev(left.end());
            leftSum -= *it;
            rightSum += *it;
            right.insert(*it);
            left.erase(it);
        }
    };
    vector<ll>ans;
    for(ll i=0;i<n;i++){
        if(left.size()==0 or *left.rbegin()>=a[i]){
            left.insert(a[i]);
            leftSum += a[i];
        }else{
            right.insert(a[i]);
            rightSum+= a[i];
        }
        balance();
        if(i>k-1){
            ll out = a[i-k];
            if(left.find(out)!=left.end()){
                leftSum -= out;
                left.erase(left.find(out));
            }else{
                rightSum -= out;
                right.erase(right.find(out));
            }
            balance();
        }
        if(i>=k-1){
            auto median = *left.rbegin();
            // ans.push_back(*median);
            ans.push_back(median * left.size() - leftSum + rightSum - right.size() * median );
        }
    }
    for(auto x:ans){
        cout<<x<<' ';
    }
    cout<<'\n';
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