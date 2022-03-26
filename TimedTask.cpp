
#include "TimedTask.h"

namespace sdds
{
	void TimedTask::startClock()
	{
		time_S = std::chrono::steady_clock::now();
	}

	void TimedTask::stopClock()
	{
		time_E = std::chrono::steady_clock::now();
	}

	void TimedTask::addTask(const char* n)
	{
		if (No_of_records < MaxNoObject)
		{
			m_event[No_of_records].name = n;
			m_event[No_of_records].units = "nanoseconds";
			m_event[No_of_records].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(time_E - time_S);
			No_of_records++;
		}
		
	}

	std::ostream& operator<<(std::ostream& os, const TimedTask& t)
	{
		os << "Execution Time: " << std::endl;
		os << "--------------------------" << std::endl;
		

		for (int i = 0; i < t.No_of_records; i++)
		{
			os.width(21);
			os.setf(std::ios::left);
			os << t.m_event[i].name << " ";
			os.width(13);
			os.unsetf(std::ios::left);
			os<< t.m_event[i].duration.count() << " " << t.m_event[i].units << std::endl;
			//os << "--------------------------" << std::endl;
				
		}
		return os;
	}
	

	
}