template <class T>
class TNewStack
{
	int size;
	int top;
	T* mas;
public:
	TNewStack(int _size, T* _mas);
	TNewStack(TNewStack &A);
	int GetFreeMem();
	void SetMas(int _size, T* _mas);
	int GetTop();
	int GetSize();
	T Get();
	void Push(T _A);
};

template <class T>
TNewStack<T>::TNewStack(int _size, T* _mas)
{
	if (_size <= 0)
	{
		ME osh(-1, "Not exist\n");
		throw osh;
	}

	size = _size;
	top = 0;
	mas = _mas;
}

template <class T>
TNewStack<T>::TNewStack(TNewStack &A)
{
	size = A.size;
	top = A.top;
	mas = A.mas;
}

template <class T>
int TNewStack<T>::GetFreeMem()
{
	return size - top;
}

template <class T>
void TNewStack<T>::SetMas(int _size, T* _mas)
{
	size = _size;
	mas = _mas;
}
template <class T>
int TNewStack<T>::GetTop()
{
	return top;
}

template <class T>
int TNewStack<T>::GetSize()
{
	return size;
}

template <class T>
void TNewStack<T>::Push(T _A)
{
	mas[top] = _A;
	top++;
}

template <class T>
T TNewStack<T>::Get() {

	top--;
	return mas[top];
}