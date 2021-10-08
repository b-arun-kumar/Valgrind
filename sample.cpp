#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	// Allocate memory on heap for 10 ints (Valid)
	int *a = (int*) malloc( 10 * sizeof(int) );
	
	// Uninitialized variable used in decision making (Invalid)
	if ( a[0] != 1)
	{
		// Write to allocated memory (Valid)
		a[0] = 5;
	}	
	
	// Write to out of bound memory (Invalid)
	a[10] = 5;
	
	// Free memory allocated by malloc using free (Valid)
	free(a);
	
	// Writing to freed memory (Invalid)
	a[0] = 5;
	
	// Freeing already freed memory (Invalid)
	free(a);
	
	// Allocate memory on heap for 10 ints (Valid)
	int *b = (int*) malloc( 10 * sizeof(int) );
	
	// Free memory allocated by malloc using delete (Invalid)
	delete b;
	
	// Allocate memory on heap for 10 ints (Valid)
	int *c = new int[10];
	
	// Free memory allocated by new[] using delete (Invalid)
	delete c;
	
	// Allocate memory on heap for 10 ints (Valid)
	int *d = (int*) malloc( 10 * sizeof(int) );
	
	// This allocated memory is not being freed (Invalid)
	//free(d);
	
	// Allocate memory on stack for 10 ints (Valid)
	int e[10];
	
	// Write to allocated memory (Valid)
	e[0] = 5;	
	
	// Write to out of bound memory (Invalid)
	e[10] = 5;
	
	return 0;
}