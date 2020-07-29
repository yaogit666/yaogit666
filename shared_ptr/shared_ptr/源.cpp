#include<iostream>
#include <thread>
#include <mutex>
using namespace std;

template <class T>
class sharedPtr
{
public:
	sharedPtr(T* p = nullptr)
		:_count(new int(1))
		,_p(p)
		,_lock(new mutex)
	{
		if (_p == nullptr)
			*_count = 0;
	}

	~sharedPtr()
	{
		Release();
	}

	sharedPtr(const sharedPtr<T>& sp)
		:_count(sp._count)
		, _p(sp._p)
		, _lock(sp._lock)
	{
		if (_p)
			addCount();
	}

	sharedPtr<T>& operator=(const sharedPtr<T>& sp)
	{
		if (_p != sp._p)
		{
			Release();

			_p = sp._p;
			_count = sp._count;
			_lock = sp._lock;

			if (_p)
				addCount();
		}
		return *this;
	}

	T& operator*() 
	{ 
		return *_p;
	}
	T* operator->() 
	{ 
		return _p; 
	}

	int useCount()
	{
		return *_count;
	}

	T* Get()
	{
		return _p;
	}

	int addCount()
	{
		_lock->lock();
		++(*_count);
		_lock->unlock();

		return *_count;
	}

	int subCount()
	{
		_lock->lock();
		--(*_count);
		_lock->unlock();

		return *_count;
	}
private:
	void Release()
	{
		if (_p && subCount() == 0)
		{
			delete _p;
			delete _count;
		}
	}
private:
	int* _count;
	T* _p;
	mutex* _lock;
};

int main()
{
	sharedPtr<int> sp1(new int(10));
	sharedPtr<int> sp2(sp1);
	*sp2 = 20;
	cout << sp1.useCount() << endl;
	cout << sp2.useCount() << endl;
	sharedPtr<int> sp3(new int(10));
	sp2 = sp3;
	cout << sp1.useCount() << endl;
	cout << sp2.useCount() << endl;
	cout << sp3.useCount() << endl;
	sp1 = sp3;
	cout << sp1.useCount() << endl;
	cout << sp2.useCount() << endl;
	cout << sp3.useCount() << endl;
	system("pause");
	return 0;
}