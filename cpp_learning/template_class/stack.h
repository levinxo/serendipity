template <class T> class Stack {
	public:
		Stack();
		~Stack();
		void push(T t);
		T pop();
		bool isEmpty();
	private:
		T *pt;
		int t_max_size;
		int t_size;
};

template <class T>
Stack<T>::Stack(){
	t_max_size = 100;
	t_size = 0;
	pt = new T[t_max_size];
}

template <class T>
Stack<T>::~Stack(){
	delete [] pt;
}

template <class T>
void Stack<T>::push(T t){
	if (t_size == t_max_size) {
		return;
	}
	t_size++;
	pt[t_size-1] = t;
}

template <class T>
T Stack<T>::pop(){
	T t = pt[t_size-1];
	t_size--;
	return t;
}

template <class T>
bool Stack<T>::isEmpty(){
	return t_size == 0;
}

