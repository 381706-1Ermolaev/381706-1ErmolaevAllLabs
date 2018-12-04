

template <class T>
class TNewStack {
	int size;
	T* top;
	T* mas;
public:
	TNewStack(int _size, T* _mas);
	TNewStack(TNewStack &A);
	int Free();
	void SetMas(int _size, T* _mas);
};

template <class T>
TNewStack<T>::TNewStack(int _size, T* _mas){
		size = _size;
		top = 0;
		mas = _mas;
}
	
template <class T>
TNewStack<T>::TNewStack(TNewStack &A){
		size = A.size;
		top = A.top;
		mas = A.mas;
}

template <class T>
int TNewStack<T>::Free(){
		return size - top;
}

template <class T>
void TNewStack<T>::SetMas(int _size, T* _mas){
		size = _size;
		mas = _mas;
}