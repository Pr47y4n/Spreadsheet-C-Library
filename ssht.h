#ifndef SSHT_H
#define SSHT_H

#include "cell.h"

#include <iostream>

class Spreadsheet
{
public:
	Spreadsheet() = default;
	Spreadsheet(int, int);
	void add_row(int);
	void add_col(int);
	void rm_row(int);
	void rm_col(int);
	const Spreadsheet_cell& get_cell(int, int) const;
	void set_cell(int, int, const std::string&);
	void print() const;
	Spreadsheet& operator=(const Spreadsheet&);
	Spreadsheet_cell* operator[](int);
	~Spreadsheet();

private:
	Spreadsheet_cell** m_matrix;
	int m_row_size;
	int m_col_size;
};


#endif //SSHT_H
