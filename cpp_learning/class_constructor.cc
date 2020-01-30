#include <iostream>

using namespace std;

class Test{
	public:
	    Test(){
	    	cout << "Common constructor called" << endl;
	    }
	    Test(const Test& t){
	    	cout << "Copy constructor called" << endl;
	    }
	    Test& operator=(const Test& t){
	    	cout << "Assignment operator called" << endl;
	    	return *this;
	    }
};

int main(){
	Test t1, t2;
	t2 = t1;
	Test t3 = t1;
	return 0;
}

