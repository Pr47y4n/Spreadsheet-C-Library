#include "ssht.h"

#include <iostream>
#include <iomanip>


Spreadsheet::Spreadsheet(int nr, int nc) : m_row_size(nr), m_col_size(nc)
{
	m_matrix = new Spreadsheet_cell*[m_row_size];
	for(int i = 0; i < m_row_size; ++i)
	{
			m_matrix[i] = new Spreadsheet_cell[m_col_size];
	}	 
}

Spreadsheet_cell* Spreadsheet::operator[](int row_index){
	if(row_index < 0 || row_index >= m_row_size){
		std::cerr << "Invalid row input" << std::endl;
		return nullptr; 
	}		
	return m_matrix[row_index];
}

void Spreadsheet::add_row(int new_row)
{
	Spreadsheet_cell** new_matrix = new Spreadsheet_cell*[m_row_size + new_row];
	for(int i = 0 ; i < m_row_size + new_row; ++i)
	{
		new_matrix[i] = new Spreadsheet_cell[m_col_size];	
	}

	for(int i = 0; i < m_row_size; ++i){
		for(int j = 0; j < m_col_size; ++j){
			new_matrix[i][j] = m_matrix[i][j];
		}
	}

	for(int i = 0; i < m_row_size; ++i)
	{
		delete[] m_matrix[i];
	}
	delete[] m_matrix;

	m_matrix = new_matrix;
	m_row_size += new_row;
}

void Spreadsheet::add_col(int new_col)
{
	Spreadsheet_cell** new_matrix = new Spreadsheet_cell*[m_row_size];

	for(int i = 0; i < m_row_size; ++i){
		new_matrix[i] = new Spreadsheet_cell[m_col_size + new_col];
	}

	for(int i = 0; i < m_row_size; ++i){
		for(int j = 0; j < m_col_size; ++j){
			new_matrix[i][j] = m_matrix[i][j];
		}
	}
	
	for(int i = 0; i < m_row_size; ++i){
		delete[] m_matrix[i];
	}
	delete[] m_matrix;
		
	m_matrix = new_matrix;
	m_col_size += new_col;
}

void Spreadsheet::rm_row(int row_index)
{
	if(row_index < 0 || row_index >= m_row_size){
		std::cerr << "Invalid row index" << std::endl;
		return;
	}
		
	Spreadsheet_cell** new_matrix = new Spreadsheet_cell*[m_row_size - 1];
	for(int i = 0, new_row = 0; i < m_row_size; ++i){
		if(i != row_index){
			new_matrix[new_row++] = m_matrix[i];
		}
	}
	
	for(int i = 0; i < m_row_size; ++i){
		delete[] m_matrix[i];
	}
	delete[] m_matrix;
	
	m_matrix = new_matrix;
	--m_row_size;
}

void Spreadsheet::rm_col(int col_index){
	if(col_index < 0 || col_index >= m_col_size){
		std::cerr << "Invalid column index" << std::endl;
		return;
	}
	
	Spreadsheet_cell** new_matrix = new Spreadsheet_cell*[m_row_size];
	for(int i = 0; i < m_row_size; ++i){
		new_matrix[i] = new Spreadsheet_cell[m_col_size - 1];
	}

	for(int i = 0; i < m_row_size; ++i){
		for(int j = 0, new_col = 0; j < m_col_size; ++j){
			if( j != col_index){
				new_matrix[i][new_col++] = m_matrix[i][j];
			}	
		}
	}
	
	for(int i =0; i < m_row_size; ++i){
		delete[] m_matrix[i];
	}
	delete[] m_matrix;

	m_matrix = new_matrix;
	--m_col_size;
}

const Spreadsheet_cell& Spreadsheet::get_cell(int row_index, int col_index) const
{
	if(row_index < 0 || row_index >= m_row_size || col_index < 0 || col_index >= m_col_size){
		std::cerr << "Invalid row or column index" << std::endl;
		return m_matrix[0][0];
	}
	return m_matrix[row_index][col_index];
}

void Spreadsheet::print() const
{
	std::cout << std::setw(8) << " ";
	for(int j = 0; j < m_col_size; ++j){
		std::cout << std::setw(8) << "Column" << j + 1;
	}
	std::cout << std::endl;
	
	for(int i = 0; i < m_row_size; ++i){
		std::cout << std::setw(8) << "Row" << i+1;
		for(int j = 0; j < m_col_size; ++j){
			std::cout << std::setw(8) << m_matrix[i][j].get_int_value();
		}
		std::cout << std::endl;
	}			
}

void Spreadsheet::set_cell(int row_index, int col_index, const std::string& new_input){
	if(row_index < 0 || row_index >= m_row_size || col_index < 0 || col_index >= m_col_size){
		std::cerr << "Invalid row or column index" << std::endl;
	}
	m_matrix[row_index][col_index] = new_input;
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& other){
	if(this == &other){
		return *this;
	}
	
	for(int i = 0; i < m_row_size; ++i){
		delete[] m_matrix[i];
	}
	delete[] m_matrix;

	m_row_size = other.m_row_size;
	m_col_size = other.m_col_size;

	m_matrix = new Spreadsheet_cell*[m_row_size];
	for(int i = 0; i < m_row_size; ++i){
		m_matrix[i] = new Spreadsheet_cell[m_col_size];
		for(int j = 0; j < m_col_size; ++j){
			m_matrix[i][j] = other.m_matrix[i][j];
		}
	}
	return *this;
}

Spreadsheet::~Spreadsheet(){
	for(int i = 0; i < m_row_size; ++i){
		delete[] m_matrix[i];
	}
	delete[] m_matrix;
}
