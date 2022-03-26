#include <fstream>
#include <iostream>
#include <sstream>
#include "ProteinDatabase.h"

static int no_of_strings = 0;

namespace sdds
{




	ProteinDatabase::ProteinDatabase(const std::string& filename)
	{
		std::ifstream in(filename);
	
		while (!in.eof())
		{
			char c = in.get();
			
			if (c == '>')
			{
				no_of_strings++;
			}
		}

		in.clear();
		in.seekg(std::ios::beg);

		m_strings = new std::string[no_of_strings];


		
		for (int i = 0; i < no_of_strings; i++)
		{

			in.ignore(2000, '\n');

			std::getline(in, m_strings[i], '>');

			m_strings[i] = RemoveChar(m_strings[i], '\n');
		}

	}

	
	size_t ProteinDatabase::size()
	{
		return no_of_strings;
	}

	std::string ProteinDatabase::operator[](size_t idx)
	{
		if (idx < no_of_strings)
		{
			return m_strings[idx];
		}
		else
		{
			return "";
		}
		
	}

	ProteinDatabase::ProteinDatabase(const ProteinDatabase& src)
	{
		*this = src;
	}

	ProteinDatabase& ProteinDatabase::operator = (const ProteinDatabase& src)
	{
		if (this != &src)
		{
			delete[] m_strings;
			m_strings = new std::string[src.no_of_strings];
			for (int i = 0; i < src.no_of_strings; i++)
			{
				m_strings[i] = src.m_strings[i];
			}
			no_of_strings = src.no_of_strings;
		}
		return *this;
	}

	ProteinDatabase::ProteinDatabase(ProteinDatabase&& src)
	{
		m_strings = nullptr;
		*this = std::move(src);
	}

	ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& src)
	{
		if (this != &src)
		{
			delete[] m_strings;
			m_strings = src.m_strings;
			src.m_strings = nullptr;

			no_of_strings = src.no_of_strings;
			src.no_of_strings = 0;
		}
		return *this;
	}

	ProteinDatabase::~ProteinDatabase()
	{
		delete[] m_strings;
	}

	std::string ProteinDatabase::RemoveChar(std::string str, char c)
	{
		std::string result;
		for (int i = 0; i < str.size(); i++)
		{
			char currentChar = str[i];
			if (currentChar != c)
			{
				result += currentChar;
			}
		}
		return result;
	}

}