#include <iostream>

using namespace std;

class Foo // Foo is a common placeholder name in computer programming
{
	public:
	Foo () { cout << "Foo's constructor" << endl; }
	~Foo () { cout << "Foo's destructor" << endl; }
};

class Bar : public Foo
{
	public:
	Bar () { cout << "Bar's constructor" << endl; }
	~Bar () { cout << "Bar's destructor" << endl; }
};

int main ()
{
	// a lovely elephant ;)
	Bar bar;
}
