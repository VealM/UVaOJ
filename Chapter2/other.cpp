#include <iostream>
using namespace std;

void get( int i,int &he,int &ji )
{
	int g,s,b;
	g=i%10;
	s=i/10%10;
	b=i/100;
	he+=g+s+b;
	ji*=g*s*b;
}

int main( )
{
	for( int i=123;i<=329;++i ){
		int he=0,ji=1;
		for( int j=1;j<=3;++j )
			get(i*j,he,ji);
		if( he==45&&ji==362880 )
			cout << i << ' ' << 2*i << ' ' << 3*i << endl;
	}
}