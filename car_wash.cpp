#include "car_wash.h"
#include <assert.h>
#include <cstdlib>

using namespace std;
namespace car_wash

{
	arrival::arrival(double p)
	{
		assert(p>=0);
		assert(p <= 1);
		p_rate=p;
	}

	bool arrival::is_car_coming()
	{
		return rand() < p_rate * RAND_MAX;
	}
	
	wash_machine::wash_machine(int n)
	{
		time_for_wash=n;
		wash_time_left=0;
	}
	
	void wash_machine::one_second()
	{
		if(is_busy())
			wash_time_left--;
	}
		
	void wash_machine::start_washing()
	{
		assert(!is_busy());
		wash_time_left = time_for_wash;
	}
	
	bool wash_machine::is_busy()
	{
		return wash_time_left>0;
	}
	
	averager::averager()
	{
		cnt=0;
		sum=0;
	}
	
	void averager::plus_next_number(int value)
	{
		cnt++;
		sum+=value;
	}

	double averager::average_time()
	{
		assert(cnt>0);
		return (sum/cnt);
	}
		
	int averager::how_many_cars()
	{
		return cnt;
	}
	
}
