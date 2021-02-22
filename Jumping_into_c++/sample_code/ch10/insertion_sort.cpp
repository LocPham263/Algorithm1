#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int findSmallestRemainingElement (int array[], int size, int index);
void swap (int array[], int first_index, int second_index);

void sort (int array[], int size)
{
	for ( int i = 0; i < size; i++ )
	{
		int index = findSmallestRemainingElement( array, size, i );
		swap( array, i, index );
	}
}

int findSmallestRemainingElement (int array[], int size, int index)
{
	int index_of_smallest_value = index;
	for (int i = index + 1; i < size; i++)
	{
		if ( array[ i ] < array[ index_of_smallest_value ]  )
		{
			index_of_smallest_value = i;
		}
	}
	return index_of_smallest_value;
}


void swap (int array[], int first_index, int second_index)
{
	int temp = array[ first_index ];
	array[ first_index ] = array[ second_index ];
	array[ second_index ] = temp;
}

// small helper method to display the before and after arrays
void displayArray (int array[], int size)
{
	cout << "{";
	for ( int i = 0; i < size; i++ )
	{
		// you'll see this pattern a lot for nicely formatting
		// lists--check if we're past the first element, and
		// if so, append a comma 
		if ( i != 0 )
		{
			cout << ", ";
		}
		cout << array[ i ];
	}
	cout << "}";
}

int main ()
{
	int array[ 10 ];
	srand( time( NULL ) ); 
	for ( int i = 0; i < 10; i++ )
	{
		// keep the numbers small so they're easy to read
		array[ i ] = rand() % 100;
	}
	cout << "Original array: ";
	displayArray( array, 10 );
	cout << '\n';

	sort( array, 10 );

	cout << "Sorted array: ";
	displayArray( array, 10 );
	cout << '\n';
}
