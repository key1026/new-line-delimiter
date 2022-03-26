#ifndef PROTEINDATABASE_H_
#define PROTEINDATABASE_H_
#include <string>
namespace sdds
{
	class ProteinDatabase
	{
		int no_of_strings{0};
		std::string* m_strings{};
		char* charactor{};
	public:
		ProteinDatabase() = default;
		ProteinDatabase(const std::string&);
		size_t size();
		std::string operator[](size_t);
		ProteinDatabase(const ProteinDatabase&);
		ProteinDatabase& operator = (const ProteinDatabase& src);
		ProteinDatabase(ProteinDatabase&&);
		ProteinDatabase& operator=(ProteinDatabase&&);
		~ProteinDatabase();

		std::string RemoveChar(std::string str, char c);
		
	};
}



#endif
