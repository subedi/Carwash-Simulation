#include <time.h>
#include "car_wash.h"
#include <queue>
#include <stdlib.h>

using namespace std;
using namespace car_wash;

int main()
{
	queue<int> q;
	int cur, next, wash_time, s_len, car_denied;
	double a_rate;
	char answer[2];

	do
	{
	cout<<"\nEnter Simulation lemgth: ";
	cin>>s_len;
	cout<<"\nEnter Arrival Rate: ";
	cin>>a_rate;
	cout<<"\nEnter wash time for a car: ";
	cin>>wash_time;

	wash_machine car_wash(wash_time);
	arrival car_rate(a_rate);
	averager cal;

	srand(time(NULL));

	for(cur=1; cur<s_len+1; cur++)
	{
		if(car_rate.is_car_coming())
		q.push(cur);
		
		if(!car_wash.is_busy() && !q.empty())
		{
			next=q.front();
			cout<<endl<<cur<<" "<<next<<endl;
			q.pop();
			cal.plus_next_number(cur-next);
			car_wash.start_washing();
		}
		
		car_wash.one_second();
	}
		
	cout<<"\nCars washed were: "<<cal.how_many_cars()<<endl;
	cout<<"\nThe average waiting time is: "<<cal.average_time()<<endl;

	car_denied=0;
	while(!q.empty())
	{
		q.pop();
		car_denied++;
	}
	
	cout<<"\nThe number of denied cars is: "<<car_denied<<endl;
	cout<<endl;
	
	cout<<"\nDo it again y for yes: ";
	cin>>answer;
	cout<<endl<<endl;

	}while(tolower(answer[0]) == 'y');
	
}
		
