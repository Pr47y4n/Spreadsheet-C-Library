#include "cell.h"
#include <utility>
Spreadsheet_cell::Spreadsheet_cell(const Spreadsheet_cell& other)
	:m_value {other.m_value}
{}

void Spreadsheet_cell::set_string_val(const std::string& val)
{
	m_value = val;
}

std::string Spreadsheet_cell::get_string_value() const
{
	return m_value;
}

int Spreadsheet_cell::get_int_value() const
{
	std::stringstream Stringstream(m_value);
	int res = 0;
	Stringstream >> res;
	if(Stringstream.fail())
	{
		std::cerr << "invalid_argument" << std::endl;
	}
	return res;
}

double Spreadsheet_cell::get_double_value() const
{
	std::stringstream Stringstream(m_value);
	double res = 0;
	Stringstream >> res;
	if(Stringstream.fail())
	{
		std::cerr << " Invalid input" << std::endl;
	}
	return res;
	
}

Spreadsheet_cell& Spreadsheet_cell::operator = (const Spreadsheet_cell& other){
	if(this != &other){
		m_value = other.m_value;
	}
	return *this;
}

Spreadsheet_cell& Spreadsheet_cell::operator = (Spreadsheet_cell&& other){
	if(this != &other){
		m_value = std::exchange(other.m_value, nullptr);
	}
	return *this;
}

Spreadsheet_cell::operator int() const
{
	return this->get_int_value();
}

Spreadsheet_cell::operator double() const
{
	return this->get_double_value();
}
