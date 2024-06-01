#include <bits/stdc++.h>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//      tree<int, (mapping), (comparison)(eg. less_equal,greater), rb_tree_tag, (policy for updating), (type of node update)>
#define fo(i,a,n) for(long long i = a; a<n?i<n:i>n;a<n?i+=1:i-=1)
#define endl "\n"
#define int long long
#define mp make_pair
#define pow2(x) (1ll<<(x))
#define pb push_back
#define eb emplace_back
#define meh {cout<<"NO"<<endl;return;}
#define yay {cout<<"YES"<<endl;return;}
#define ok(t) {cout<<t<<endl;return;}
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define vin(v) for(auto&x:v)cin>>x;
#define vout(v) for (auto x: v)cout<<x<<' ';cout<<endl;
#define f first
#define s second
void print(int t) {cout << t;} 
void print(string t) {cout << t;}
void print(char t) {cout << t;}
void print(double t) {cout << t;}
template <class T, class V> void print(pair <T, V> p);
template <class T> void print(vector <T> v);
template <class T> void print(set <T> v);
template <class T, class V> void print(map <T, V> v);
template <class T> void print(multiset <T> v);
template <class T, class V> void print(pair <T, V> p) {cout << "{"; print(p.first); cout << ","; print(p.second); cout << "}";}
template <class T> void print(vector <T> v) {cout << "[ "; for (T i : v) {print(i); cout << " ";} cout << "]\n";}
template <class T> void print(set <T> v) {cout << "[ "; for (T i : v) {print(i); cout << " ";} cout << "]\n";}
template <class T> void print(multiset <T> v) {cout << "[ "; for (T i : v) {print(i); cout << " ";} cout << "]\n";}
template <class T, class V> void print(map <T, V> v) {cout << "[ "; for (auto i : v) {print(i); cout << " ";} cout << "]\n";}
long long sqroot(long long a){long long b = (long long) sqrtl(a);if ((b + 1) * (b + 1) == a){b++;}return b;}
typedef vector<int> vi;
typedef vector<pair<int,int>> vpii;
typedef vector<vector<int>> vvi;
typedef map<int,int> mii;
typedef set<int> si;
typedef set<char> sc;

using ll = long long;
using llu = unsigned long long;
using ld = long double;

const int INF = 1000*1000*1000;
const int MAX = 200007;
const int MOD = 1000000007;

void solve() {


}

int32_t main() {
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
// solve();
}