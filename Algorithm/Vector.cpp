#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Vector
{
public:
	Vector()
	{

	}

	~Vector()
	{
		if (_data)
			delete[] _data;
	}

	void push_back(const T& value)
	{
		if (_size == _capacity)
		{
			// 증설 작업
			int newCapacity = static_cast<int>(_capacity * 1.5);

			// 새로운 Capacity가 기존과 동일한 경우는 강제로 증설 처리 (ex: 0, 1)
			if (newCapacity == _capacity)
				++newCapacity;

			reserve(newCapacity);
		}

		// 데이터 저장
		_data[_size] = value;

		// 데이터 개수 증가
		_size++;
	}

	void pop_back()
	{
		_size = _size > 0 ? _size - 1 : 0;
	}

	void reserve(int capacity)
	{
		if (_capacity >= capacity)
			return;

		_capacity = capacity;

		T* newData = new T[_capacity];

		// 데이터 복사
		for (int i = 0; i < _size; ++i)
			newData[i] = _data[i];

		if (_data)
			delete[] _data;

		// 교체
		_data = newData;
	}

	T& operator[](const int pos) { return _data[pos]; }

	int size() { return _size; }
	int capacity() { return _capacity; }

	void clear()
	{
		if (_data)
		{
			delete[] _data;
			_data = new T[_capacity];
		}

		_size = 0;
	}

private:
	T*	_data = nullptr;
	int _size = 0;
	int _capacity = 0;
};

int main_vector()
{
	Vector<int> v;

	// 몇 개가 들어오는지 알고 있다면 capacity를 지정해 주는 편이 훨씬 효율적이다.
	v.reserve(100);

	// 실제 데이터 개수 조정. capacity가 매개변수보다 작다면 capacity도 같이 늘어난다.
	// 데이터가 100개에서 10개로 resize 하면? 데이터가 10개만 유효하고, 나머지는 날라간다. capacity는 그대로.
	// 코딩 테스트(구현)에서 은근 자주 나온다.
	// v.resize(10);

	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		cout << v[i] << " " << v.size() << " " << v.capacity() << endl;
	}

	v.pop_back(); v.pop_back(); v.pop_back();

	//v.clear();

	cout << v.size() << " " << v.capacity() << endl;

	return 0;
}