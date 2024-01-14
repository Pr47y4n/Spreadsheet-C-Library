#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <sstream>
#include <string>

class Spreadsheet_cell
{
public:
	Spreadsheet_cell() = default;
	Spreadsheet_cell(const std::string& value) : m_value(value)	{}
	Spreadsheet_cell(const Spreadsheet_cell&);
	Spreadsheet_cell& operator = (const Spreadsheet_cell&);
	Spreadsheet_cell& operator = (Spreadsheet_cell&&);
	~Spreadsheet_cell() = default;
	
public:
	void set_string_val(const std::string&);//gerbernel
	std::string get_string_value() const;
	int get_int_value() const;
	double get_double_value() const;
	operator int() const;//return get_int
	operator double() const; //return get_double

private:
	std::string m_value;

};

#endif // CELL_H
