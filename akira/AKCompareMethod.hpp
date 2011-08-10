// Ŭnicode please
//template impl
namespace testing
{
	template<typename T1, typename T2>
	bool isEqual(const T1 &a, const T2 &b)
	{
		bool result = true;
		//a, b를 각각 캐스팅해서 비교해보고 캐스팅이 통과하면 타입이 같은거라고 볼수있다 
		//a, b의 타입이 캐스팅이 불가능한경우 static_cast를 썻기떄문에 컴파일동 통과못함으로써 
		//어차피 fail될걸 찾기 쉬울 것이다 
		T1 t1a = static_cast<T1> (a);
		T1 t1b = static_cast<T1> (b);
		if(t1a != t1b)
		{
			result = false;
		}

		T2 t2a = static_cast<T2> (a);
		T2 t2b = static_cast<T2> (b);
		if(t2a != t2b)
		{
			result = false;
		}
		return result;
	}
	
	template<typename T>
	bool isEqual(const T &a, const T &b)
	{
		return (a == b);
	}

	template<typename T>
	bool isLessThan(const T &a, const T &b)
	{
		return (a < b);
	}

	//le
	template<typename T>
	bool isLessEqual(const T &a, const T &b)
	{
		return (a <= b);
	}

	//gt
	template<typename T>
	bool isGreaterThan(const T &a, const T &b)
	{
		return (a > b);
	}

	//ge
	template<typename T>
	bool isGreaterEqual(const T &a, const T &b)
	{
		return (a >= b);
	}

	template<typename T>
	bool isAbsErrorEqual(T a, T b, T absError)
	{
		T error = a - b;
		if(error < 0)
		{
			error = -error;
		}
		return (error <= absError);
	}
	template<typename T>
	bool isRelErrorEqual(T a, T b, T relError)
	{
		if (a == b)
		{
			return true;
		}
		float relativeError = 0;
		if (abs(b) > abs(a))
		{
			relativeError = abs((a - b) / b);
		}
		else
        {
			relativeError = abs((a - b) / a);
		}
		if (relativeError <= relError)
		{
			return true;
		}
		return false;
	}
}
