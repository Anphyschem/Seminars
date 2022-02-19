#include<iostream>
#include<chrono>
#include<string>

template<typename T = std::chrono::microseconds>
class Timer
{
public:

	using clock_t = std::chrono::steady_clock;
	using time_poin_t = clock_t::time_point;

	explicit Timer() : m_begin(clock_t::now()), flag(true), m_summ(0), m_name("")
	{
		start();
	};

	explicit Timer(const std::string& a) : m_begin(clock_t::now()), flag(true), m_summ(0), m_name(a) 
	{start(); };

	void start()
	{
		if (!flag)
		{
			m_begin = clock_t::now();
			flag = true;
		}
	};

	void restart()
	{
		m_begin = std::clock_t::now();
		m_summ = 0;
		flag = true;
	}

	void stop() 
	{
		if (flag)
		{
			m_summ += std::chrono::duration_cast <T>( clock_t::now() - m_begin);
			flag = false;
		}
	};

	~Timer() noexcept
	{
		try {
			stop();
			std::cout << m_summ.count() << std::endl;
		}
		catch (...) {}
	};

	std::string & name()
	{
		return m_name;
	}
private:
	time_poin_t m_begin;
	T m_summ;
	bool flag;
	std::string m_name;

};


int main()
{
	

	
	{
			Timer t1;
		{
				
			Timer t;
			for (auto i = 0; i < 20; ++i) {
				std::cout << 1 << std::endl;
				std::cout << 1 << std::endl;
				t.stop();
				std::cout << 1 << std::endl;
				std::cout << 1 << std::endl;
				std::cout << 1 << std::endl;
				std::cout << 1 << std::endl;
				t.start();
				std::cout << 1 << std::endl;
				std::cout << 2 << std::endl;
			}
		}
	}
}