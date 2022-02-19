#include<iostream>
#include<chrono>

class Timer
{public:

	using clock_t = std::chrono::steady_clock;
	using time_poin_t = clock_t::time_point;

	Timer(): m_begin(clock_t::now()), flag (true), m_summ(0)
	{};


	void start() 
	{
		if (flag == false)
		{
			m_begin = clock_t::now();
		}
	};

	void stop() 
	{
		if (flag)
		{
			m_summ += std::chrono::duration_cast <std::chrono::microseconds>( clock_t::now() - m_begin);
			flag = false;
		}
	};

	~Timer()
	{
		stop();
		std::cout << m_summ.count() << std::endl;
	};

private:
	time_poin_t m_begin;
	std::chrono::microseconds m_summ;
	bool flag;

};


int main()
{
	

	
	{
			Timer t1;
		{
			Timer t;
			std::cout << 1 << std::endl;
			std::cout << 1 << std::endl;
			std::cout << 1 << std::endl;
			std::cout << 1 << std::endl;
			t.stop();
			std::cout << 1 << std::endl;
			std::cout << 1 << std::endl;
			std::cout << 1 << std::endl;
			std::cout << 2 << std::endl;

		}
	}
}