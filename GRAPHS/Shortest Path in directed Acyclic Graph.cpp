
#include <bits/stdc++.h>
#define ull unsigned ll
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second1
#define nui 100
#define pi 3.1415926535897932384626
#define nu 1e18
#define INF 100000000000
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#define F1(i,a,n) for(int i=a;i<n;i++)
#define B(i,a,n) for(ll i=n-1;i>=a;i--)
#define tc int t;cin>>t;while(t--)
#define tcf ll t;cin>>t;for(int w=1;w<=t;w++)
#define Ans(a,b) cout<<"Case #"<<a<<": "<<b<<"\n";
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define re(a)  a.resize(unique(a.begin(), a.end()) - a.begin());
#define revsort(a)  is_sorted(begin(a), end(a));
#define inineg  LLONG_MIN;
#define NO_OF_CHARS 256
#define REP(i,n) for (int i = 1; i <= n; i++)
const int  P1=1000000007;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define P 1000000007
#define vc vector<int> 
#define F first

#define eb emplace_back
#define rep(i,a,b) for(int i = a; i < b; i++)



//#define multisett  multiset<1e9+7, greater<int>> tickets;

using namespace std ;

bool vis[105];
ll co[105][2];
 

//shortest path in a dag !!

void findTopoSort(int node, int vis[], stack<int> &st, vector<pair<int,int>> adj[]) {
    vis[node] = 1; 
    for(auto it : adj[node]) {
        if(!vis[it.first]) {
            findTopoSort(it.first, vis, st, adj); 
        }
    }
    st.push(node);
}


void shortestPath(int src, int N, vector<pair<int,int>> adj[]) 
{ 
    int vis[N] = {0};
    stack<int> st; 
    for (int i = 0; i < N; i++) 
        if (!vis[i]) 
            findTopoSort(i, vis, st, adj); 
            
    int dist[N]; 
    for (int i = 0; i < N; i++) 
        dist[i] = 1e9; 
    dist[src] = 0; 

    while(!st.empty()) 
    {  
        int node = st.top(); 
        st.pop(); 
 
        if (dist[node] != INF) {
            for(auto it : adj[node]) {
                if(dist[node] + it.second < dist[it.first]) {
                    dist[it.first] = dist[node] + it.second; 
                }
            }
        }
    } 

    for (int i = 0; i < N; i++) 
        (dist[i] == 1e9)? cout << "INF ": cout << dist[i] << " "; 
} 


void solve()
{

 




int n, m;
    cin >> n >> m;
    vector<pair<int,int>> adj[n]; 
    for(int i = 0;i<m;i++) {
        int u, v, wt;
        cin >> u >> v >> wt; 
        adj[u].push_back({v, wt}); 
    }
    
    shortestPath(0, n, adj);

  
  //SAMPLE INPUT      
/*
6 7
0 1 2
0 4 1
1 2 3
2 3 6
4 2 2
4 5 4
5 3 1
*/
// ANS : 0 2 3 6 1 5
    

}


int  main(void)
{
  
    ios::sync_with_stdio(0);   
    cin.tie(0);


#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE


//ull t;



//cin>>t;

//while(t--)
//{


 
  solve();

//}


 //cout<<1<<endl;



 
// memset(arr1,0,sizeof(arr1));





#ifndef ONLINE_JUDGE
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
#endif
//return 0;



}






/*

 !!!!!
 *
 *
 * ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
 * │Esc│   │ F1│ F2│ F3│ F4│ │ F5│ F6│ F7│ F8│ │ F9│F10│F11│F12│ │P/S│S L│P/B│  ┌┐    ┌┐    ┌┐
 * └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘  └┘    └┘    └┘
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
 * │~ `│! 1│@ 2│# 3│$ 4│% 5│^ 6│& 7│* 8│( 9│) 0│_ -│+ =│ BacSp │ │Ins│Hom│PUp│ │Num│ / │ * │ - │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
 * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │{ [│} ]│ | \ │ │Del│End│PDn│ │ 7 │ 8 │ 9 │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘ ├───┼───┼───┤ + │
 * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │: ;│" '│ Enter  │               │ 4 │ 5 │ 6 │   │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐     ├───┼───┼───┼───┤
 * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │< ,│> .│? /│  Shift   │     │ ↑ │     │ 1 │ 2 │ 3 │   │
 * ├─────┬──┴─┬─┴──┬┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤ E││
 * │ Ctrl│ Win│ Alt│         Space         │ Alt│ Win│Menu│Ctrl│ │ ← │ ↓ │ → │ │   0   │ . │←—┘│
 * └─────┴────┴────┴───────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
 */
