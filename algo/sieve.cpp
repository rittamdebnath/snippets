#include <iostream> 
#include <cstdio>
#include <cstdlib> 
#include <cstring> 
#include <string>

const int maxn = (int)1e7 + 10;

int isComposite[maxn >> 6];
int factor[maxn];
int primes[665000];
int P;
int A,B;

inline bool check(int i)
{
	return ( isComposite[i >> 5] & ( 1 << ( i & 31) ) );
}

inline void fix(int i)
{
	isComposite[ i >> 5] |= ( 1 << ( i & 31) );
}

void sieve()
{
	int i,j, k;

	for(i = 6; i <= 3160; i += 6)
	{
		for(k = i -1; k <= i + 1; k += 2)
			if(!check(k >> 1) )
				for(j = k * k; j < maxn; j += k << 1)
					fix( j >> 1);
	}

	P = 1;
	primes[P++] = 2;
	primes[P++] = 3;
	for(i = 6; i < maxn ;  i += 6)
	{
		for(j = i -1; j <= i + 1; j +=2)
			if(!check(j >> 1 ) )
				primes[P++] = j;
	}
	primes[0] = primes[P++] = 1 << 30;
}
