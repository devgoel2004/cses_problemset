#include <iostream>     // cin, std::cout
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
void init()
{
  #ifndef ONLINE_JUDGE
 
freopen("input.txt", "r", stdin);
 
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}
// code to do modular arthematic operations.
ll mod_mul(ll x, ll y, ll m){
    return (x%m*y%m)%m;
}
ll mod_sub(ll x, ll y, ll m){
    return (x%m - y%m + m)%m;
}
ll mod_add(ll x, ll y, ll m){
    return (x%m+y%m)%m;
}
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
struct Hashing{
    string s;
    ll n;
    ll primes;
    vector<ll> hashPrimes = {1000000009, 100000007};
    const ll base = 31;
    vector<vector<ll>> hashValues;
    vector<vector<ll>> powersOfBase;
    vector<vector<ll>> inversePowersOfBase;
    Hashing(string a){
        primes = hashPrimes.size();
        hashValues.resize(primes);
        powersOfBase.resize(primes);
        inversePowersOfBase.resize(primes);
        s = a;
        n = s.length(); 
        for(ll i = 0; i < hashPrimes.size(); i++) {
            powersOfBase[i].resize(n + 1);
            inversePowersOfBase[i].resize(n + 1);
            powersOfBase[i][0] = 1;
            for(ll j = 1; j <= n; j++){
                powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
            }
            inversePowersOfBase[i][n] = mminvprime(powersOfBase[i][n], hashPrimes[i]);
            for(ll j = n - 1; j >= 0; j--){
                inversePowersOfBase[i][j] = mod_mul(inversePowersOfBase[i][j + 1], base, hashPrimes[i]);
            } 
        }
        for(ll i = 0; i < hashPrimes.size(); i++) {
            hashValues[i].resize(n);
            for(ll j = 0; j < n; j++){
                hashValues[i][j] = ((s[j] - 'a' + 1LL) * powersOfBase[i][j]) % hashPrimes[i];
                hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) % hashPrimes[i];
            }
        }
    }
    vector<ll> substringHash(ll l, ll r){
        vector<ll> hash(primes);
        for(ll i = 0; i < primes; i++){
            ll val1 = hashValues[i][r];
            ll val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
            hash[i] = mod_mul(mod_sub(val1, val2, hashPrimes[i]), inversePowersOfBase[i][l], hashPrimes[i]);
        }
        return hash;
    }
};
class DisjointSet{
    public:
     vector<ll>rank,size,parent;
     DisjointSet(ll n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(ll i=0;i<=n;i++){
            parent[i]=i;
        }
     }
     ll findPar(ll node){
        if(parent[node]==node){
            return node;
        }
        return parent[node] = findPar(parent[node]);
     }
     void unionBySize(ll u, ll v){
        ll pu = findPar(u);
        ll pv = findPar(v);
        if(pu==pv) return;
        if(size[pu]<size[pv]){
            parent[pu] = pv;
            size[pv]+=size[pu];
        }else{
            parent[pv] = pu;
            size[pu]+=size[pv];
        }
     }
     void unionByRank(ll u, ll v){
        ll pu = findPar(u);
        ll pv = findPar(v);
        if(pu==pv) return;
        if(rank[pu]==rank[pv]){
            parent[pu]=pv;
            rank[pv]++;
        }
        else if(rank[pu]<rank[pv]){
            parent[pu] = pv;
        }
        else{
            parent[pv]=pu;
        }
     }
};
ll power(ll a, ll b){
    ll res = 1;
    while(b>0){
        if(b&1){
            res = (res%MOD * a%MOD)%MOD;
        }
        a = (a%MOD*a%MOD)%MOD;
        b>>=1;
    }
    return res;
}
bool isPowerOfTwo(ll n){
    if (n == 0)
        return false;
    ll x = n&(n-1);
    if(x==0){
        return true;
    }return false;
}
bool isLower(char s){
    if(s>=97 && s<=122){
        return true;
    }return false;
}
bool isUpper(char s){
    if(s>=65 && s<=90){
        return true;
    }
    return false;
}
bool isEven(ll x){
    return (!(x&1));
}
bool checkCaptial(string x){
    for(auto c:x){
        if(c>=65 && c<=90){
            return true;
        }
    }
    return false;
}
bool checkNumber(string x){
    for(auto c:x){
        if(c>=48 && c<=57){
            return true;
        }
    }
    return false;
}
bool checkVowel(string x){
    for(auto c:x){
        if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u'){
            return true;
        }
    }
    return false;
}
bool checkConsonant(string x){
    for(auto c:x){
        if(c!='a' and c!='e' and c!='i' and c!='o' and c!='u'){
            return true;
        }
    }
    return false;
}
ll nearestPowerOf2(ll number) {
    ll power = static_cast<ll>(std::log2(number));
    return static_cast<ll>(std::pow(2, power));
}
ll log_a_to_base_b(ll a, ll b){
    return log2(a)/log2(b);
}
ll nearestPowerOfX(ll number, ll x){
    ll lg = log(number)/log(x);
    ll a = pow(x,lg);
    ll b = pow(x,lg+1);
    if((number<a)<(b-number)){
        return a;
    }
    return b;
}
ll reverseDigits(ll num) { 
    ll rev_num = 0; 
    while (num > 0) { 
        rev_num = rev_num * 10 + num % 10; 
        num = num / 10; 
    } 
    return rev_num; 
} 
ll sgn(ll x){
    if(x>0) return 1;
    return -1;
}
bool checkPrime(ll x){
    if(x<2) return false;
    ll cnt=0;
    for(ll i=2;i*i<=x;i++){
        if(x%i==0) cnt++;
    }
    return cnt==0;
}
ll nearestUpperPowerOf2(ll N)
{
    ll a = log2(N);
    if (pow(2, a) == N)
        return N;
    return pow(2, a + 1);
}
ll nearestUpperPowerOfk(ll n, ll k){
     if (n <= 1) {
        return 1;
    }
    double logValue = log(n) / log(k);
 
    int exponent = ceil(logValue);
    
    return pow(k, exponent);
}
string toBinaryString(ll number) {
    if (number == 0) {
        return "0";
    }
    string binaryString = "";
    while (number > 0) {
        binaryString = (number % 2 == 0 ? "0" : "1") + binaryString;
        number /= 2;
    }
    return binaryString;
}
const ll maxN = 2e6+5;

vector<ll> isPrime(maxN + 1, true);
vector<ll> smallest_prime_factor(maxN+1,1e9);
void sieveOfEratosthenes() {
    isPrime[0] = false;
    isPrime[1] = false;    
    for (ll p = 2; p * p <= maxN; ++p) {
        if (isPrime[p]) {
            smallest_prime_factor[p] = p;
            for (ll i = p * p; i <= maxN; i += p) {
                isPrime[i] = false;
                smallest_prime_factor[i] = min(smallest_prime_factor[i],p);
            }
        }
    }
}
vector<ll>fact(maxN+1,1);
vector<ll>invfact(maxN+1,1);
void factorial(){
    for(ll i=1;i<=maxN;i++){
        fact[i] = (fact[i-1]%MOD * i%MOD)%MOD;
    }
}
void inversefactorial(){
    invfact[maxN] = power(fact[maxN],MOD-2);
    for(ll i=maxN-1;i>=0;i--){
        invfact[i] = (invfact[i+1]%MOD * (i+1)%MOD)%MOD;
    }
}
ll combination(ll n, ll k){
    if (k > n - k) k = n - k; 
    ll res = fact[n]%MOD;
    res = (res%MOD * invfact[k]%MOD)%MOD;
    res = (res%MOD * invfact[n - k]%MOD)%MOD;
    return res;
}
ll permutation(ll n, ll k){
    if(k>n){
        return 0;
    }
    ll res = fact[n]%MOD;
    res = (res%MOD * invfact[n-k]%MOD)%MOD;
    return res;
}
bool isPalindrome(vector<ll>&a){
    ll low=0,high = a.size()-1;
    while(low<high){
        if(a[low]==a[high]){
            low++;
            high--;
        }
        else{
            return false;
        }
    }
    return true;
}
ll countn(ll n){
    ll cnt=0;
    while(n){
        cnt++;
        n/=10;
    }
    return cnt;
}
ll powm(ll x, ll y){
    x%=M;
    if(y==0){
        return 1;
    }else if(y==1){
        return x;
    }
    ll p = powm(x*x,y/2);
    if(y%2){
        return p*x;
    }else{
        return p;
    }
}
void printSet(set<ll>&st){
    for(auto x:st){
        std::cout<<x<<' ';
    }
}
void print2DArray(vector<vector<ll>>&a){
    ll n = a.size();
    ll m = a[0].size();
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            std::cout<<a[i][j]<<' ';
        }
        std::cout<<'\n';
    }
} 
vector<ll>primeFactorization(ll n){
    vector<ll>ans;
    while(n%2==0){
        ans.push_back(2);
        n/=2;
    }
    for(ll i=3;i*i<=n;i+=2){
        while(n%i==0){
            ans.push_back(i);
            n/=i;
        }
    }
    if(n>2){
        ans.push_back(n);
    }
    return ans;
}
ll cielValue(ll x, ll y){
    if(x%y==0){
        return x/y;
    }return x/y+1;
}
 
void printArray(vector<ll>a){
    for(auto x:a){
        std::cout<<x<<' ';
    }
}
ll upperciel(ll x,ll y){
    if(x%y==0){
        return x/y;
    }
    return x/y+1;
}
ll lowerciel(ll x, ll y){
    return x/y;
}
bool setBit(ll k, ll i){
    return (k & (1LL << i)) != 0;
}
bool validate(ll x, ll y,ll n, ll m){
    return x>=0 and y>=0 and x<n and y<m;
}
ll ceil_log2(ll x){
    ll k =0;
    while((1<<k)<x)k++;
    return k;
}
bool isPalindromecheck(ll x,vector<ll>&a){
    ll n = a.size();
    ll i=0,j=n-1;
    while(i<j){
        if(a[i]==x){
            i++;
        }
        else if(a[j]==x){
            j--;
        }
        else if(a[i]==a[j]){
            i++;
            j--;
        }
        else if(a[i]!=a[j]){
            return false;
        }
    }
    return true;
}
//binary exponentiation
ll pw(ll a, ll b){
    if(b==0){
        return 1;
    }
    else if(b%2==0){
        ll temp = pw(a,b/2);
        return ((temp%MOD)*(temp%MOD))%MOD;
    }else{
        ll temp = pw(a,(b-1)/2);
        return ((temp%MOD)*(temp%MOD)*(a%MOD))%MOD;
    }
}
// Modulo inverse function
ll modulo_inverse(ll x){
    return pw(x,MOD-2)%MOD;
}
vector<ll>factors(ll x){
    vector<ll>fac;
    for(ll i=1;i*i<=x;i++){
        if(x%i==0){
            fac.push_back(i);
            if(i!=x/i){
                fac.push_back(x/i);
            }
        }
    }
    return fac;
}
ll digitsum(ll n){
    ll sum=0;
    while(n>0){
        sum += n%10;
        n/=10;
    }
    return sum;
}
ll modularInverse(ll x){
    ll b = M-2;
    ll res = 1;
    x=x%M;
    if(x==0){
        return 0;
    }
    while(b>0){
        if(b&1){
            res = ((res%M) * (x%M))%M;
        }
        b>>=1;
        x = ((x%M)*(x%M))%M;
    }
    return res;
}
ll binarySearch(vector<ll>&a, ll val){
    ll n = a.size();
    ll low=0,high=n-1;
    while(low<=high){
        ll mid = (high-low)/2+low;
        if(a[mid]==val){
            return mid;
        }else if(a[mid]<val){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return -1;
}
ll gcd(ll x, ll y){
    if(y==0){
        return x;
    }
    return gcd(y,x%y);
}
ll lcm(ll x,ll y){
    return (x/gcd(x,y))*y;
}
ll askInteger(){
   ll sum;
   cin>>sum;
   return sum;
}
string askString(){
    string s;
    cin>>s;
    return s;
}
char askChar(){
    char c;
    cin>>c;
    return c;
}
bool parity(char c, char d){
    if(c%2!=d%2){
        return true;
    }
    return false;
}
ll noDigits(ll k){
    ll cnt=0;
    while(k!=0){
        k/=10;
        cnt+=1;
    }
    return cnt;
}
void hareKrishna(){
    string s;
    cin>>s;
    string temp;
    cin>>temp;
    ll n = s.size();
    ll m = temp.size();
    Hashing hs = Hashing(s);
    Hashing hs2 = Hashing(temp);
    vector<ll>pattern_hash = hs2.substringHash(0,temp.size()-1);
    ll ans=0;
    for(ll i=0;i+m-1<n;i++){
        vector<ll>currHash = hs.substringHash(i,i+m-1);
        if(currHash == pattern_hash){
            ans+=1;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    // sieveOfEratosthenes();
    // factorial();
    // inversefactorial();
    // cin>>t;
    while(t--){
        hareKrishna();
    }
    return 0;
}