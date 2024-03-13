
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef long double ld;
const int MOD=1e9+7, OO=0x3f3f3f3f;
const ll LOO=0x3f3f3f3f3f3f3f3f;
#define all(x) (x).begin(),(x).end()
#define mm(f, x) memset(f,x,sizeof(f))
#define f(n) for(int i=0;i<n;++i)
#define fa(i,a,n) for(int i=(a);i<=(n);++i)
#define  c(vec) for(auto &x:vec)cin>>x;
#define ff(vec) for(auto &x:vec)cout<<x<<' ' ;cout<<'\n';
#define fp(vec) for(auto &x:vec)cout<<x.first<<' '<<x.second<<'\n';
#define debug(x) cout<<#x<<":"<<x<<endl;
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define pb push_back
#define sz(a) (int)(a).size()
const long double EPS=1e-7;
const ll MOD1=1e18+7;
int dr[]={-1, -1, -1, 0, 1, 1,  1,  0};
int dc[]={-1,  0,  1, 1, 1, 0, -1, -1};
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

const int N=1e7+5;
ll fac[N];
void pre(){
    fac[0]=1;
    for(ll i=1;i<N;i++){
        fac[i]=(fac[i-1]*i)%MOD;
    }

}
ll fastpow(ll n,ll p){
    if(p==0)return 1;
    ll ans= fastpow(n,p/2);
    ans=ans*ans%MOD;
    if(p&1)ans=ans*n%MOD;
    return ans;
}

ll modinv(ll n){
    return fastpow(n,MOD-2)%MOD;
}

ll ncr(ll n,ll r){
    if(n<r)return 0;
    return (fac[n]*modinv(fac[n-r])%MOD)*modinv(fac[r])%MOD;
}

ll mul(const ll &a, const ll &b) {
    return (a % MOD + MOD) * (b % MOD + MOD) % MOD;
}



void build(vector<int>&tree,string s,int v,int vl,int vr){
    if(vl==vr)tree[v]=(1<<(s[vl]-'a'));
    else{
        int m=(vl+vr)/2;
        build(tree,s,2*v,vl,m);
        build(tree,s,2*v+1,m+1,vr);
        tree[v]=(tree[2*v]|tree[2*v+1]);
    }
}
void update(vector<int>&tree,int v,int vl,int vr,int idx,char val){
    if(vl==vr)tree[v]=(1<<(val-'a'));
    else{
        int m=(vl+vr)/2;
        if(idx<=m) update(tree,2*v,vl,m,idx,val);
        else update(tree,2*v+1,m+1,vr,idx,val);
        tree[v]=(tree[2*v]|tree[2*v+1]);
    }
}


int get(vector<int>&tree,int v,int vl,int vr,int l,int r){
    if(l>r)return 0;
    if(vl==l&&vr==r)return tree[v];
    else {
        int m = (vl + vr) / 2;
        return (get(tree, 2 * v, vl, m, l, min(m, r))| get(tree, 2 * v + 1, m + 1, vr, max(l, m+1), r));
    }
}



signed  main(){
    FAST
    //freopen("game.in","rt",stdin);
    //freopen("game.out","wt",stdout);



    int x;
    cin>>x;
    while(x--){
        cout<<x<<'\n';
    }


    return 0;
}

