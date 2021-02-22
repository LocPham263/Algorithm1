class Superclass
{
public:
	// note that since we are declaring the copy constructor we now
	// need to provide our own default constructor
	Superclass () {}
private:
	// prohibited, we will not define this method
	Superclass (const Superclass& other);
};

class Subclass : public Superclass
{
	int val;
};

int main ()
{
	Subclass sub;
	Superclass super = sub; // now this line of code causes a compilation error
}
