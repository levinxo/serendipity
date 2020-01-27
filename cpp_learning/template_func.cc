#include <iostream>

template <typename T> void swap(T& a1, T& a2){
	T temp;
	temp = a1;
	a1 = a2;
	a2 = temp;
}

int main(){
	int a1 = 1;
	int a2 = 2;

	swap<int>(a1, a2);
	std::cout << "a1: " << a1 << " a2: " << a2 << std::endl;
	return 0;
}

