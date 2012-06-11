#ifndef CAR_WASH_H_
#define CAR_WASH_H_

#include <iostream>

namespace car_wash
{

class arrival
{
	public:
	arrival(double);
	bool is_car_coming();

	private:
	double p_rate;
};

class wash_machine
{
	public:
	wash_machine(int);
	void one_second();
	bool is_busy();
	void start_washing();

	private:
	int time_for_wash, wash_time_left;
};

class averager
{
	public:
	averager();
	void plus_next_number(int);
	int how_many_cars();
	double average_time();
	
	private:
	double sum;
	int cnt;
};

};

#include "car_wash.cpp"
#endif
