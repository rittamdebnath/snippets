#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define cin(n) scanf("%d",&n)
#define gc getchar_unlocked
typedef vector<int> VI;
int fcin(){register int c = gc();int x = 0;for(;(c<48 || c>57);c = gc());for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}return x;}
const int max_m = (1<<22);
const int max_n = (int)1e6;
int arr[max_m+1]; 
void preprocess(){
	arr[0]=0; 
	for(int i=1;i<=max_m;i++)arr[i] = arr[i>>1]^(i&1);
}
int T[max_n];
int P[max_n];
int n;
void table()
{    
  for(int i=0;i<n;i++)T[i]=-1;
  int cnd=0;
  int i=2;
  T[0]=-1;T[1]=0;
  while(i<n)
  {
    if(P[i-1]==P[cnd])T[i++]=++cnd;
    else if (cnd>0) cnd=T[cnd];
    else T[i++]=0;
  }
}
void kmp()
{
	int N = max_m;
	int m=0;int i=0;
	int printedSoFar = 0; 
	while(m+i<N && printedSoFar < n){
	    if(P[i]==arr[m+i]){
		  if(printedSoFar <= i)printedSoFar++,cout<<m<<" "; 
	      i++;
	    }
	    else{
	      m=m+i-T[i];
	      i=(T[i]>-1)?T[i]:0;
	    }
  	}
	while(printedSoFar < n)printedSoFar++,cout<<"-1 ";
}
int main(){
	preprocess(); 
	int tests=fcin();
	while(tests--){
		n = fcin();
		for(int i=0;i<n;i++)P[i] = fcin(); 
		table();
		kmp();
	}
}