#include <iostream>
#include "stdint.h"

using namespace std;

void test(uint32_t a) 
{
	cout<<"\nUint32 passed";
}

void test(uint64_t b)
{
	cout<<"\nUint64 passed";
}


int main(int argc, char const *argv[])
{	
	/* code */
	uint32_t a=1;
	uint64_t b=1;
	test(a);
	test(b);
	return 0;
}