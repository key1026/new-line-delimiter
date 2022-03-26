#ifndef TIMEDTASK_H_
#define TIMEDTASK_H_

#include <string>
#include <chrono>
#include <iostream>


namespace sdds
{
	const int MaxNoObject = 10;

	class TimedTask
	{
		int No_of_records = 0;
		std::chrono::steady_clock::time_point time_S;
		std::chrono::steady_clock::time_point time_E;
		struct Task
		{
			std::string name;
			std::string units;
			std::chrono::steady_clock::duration duration;
		}m_event[MaxNoObject];
	public:
		TimedTask() = default;
		void startClock();
		void stopClock();
		void addTask(const char*);
		friend std::ostream& operator << (std::ostream&, const TimedTask&);
	};
}





#endif