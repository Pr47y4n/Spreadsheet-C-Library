# Spreadsheet-C-Library
This C++ library provides a simple and customizable spreadsheet implementation. It includes a Spreadsheet class that allows users to create, manipulate, and print spreadsheet-like structures. The library features a Spreadsheet_cell class for representing individual cells within the spreadsheet.
# Getting Started

To use the Spreadsheet library in your C++ project, follow these steps:
# Installation
Clone the repository to your local machine and copy the spreadsheet.h and spreadsheet.cpp files to your project directory.
# Usage
Include the spreadsheet.h file in your main.cpp and create a Spreadsheet instance for testing its functionality in main.cpp:
    
    int main() {
    // Create a 3x4 spreadsheet
    Spreadsheet mySpreadsheet(3, 4);

    // Set and retrieve cell values
    Spreadsheet_cell cellValue;
    mySpreadsheet.set_cell(1, 2, cellValue);

    // Access cell values using the subscript operator
    Spreadsheet_cell retrievedValue = mySpreadsheet[1][2];

    // Print the spreadsheet
    mySpreadsheet.print();

    // Copy and assign spreadsheets
    Spreadsheet copiedSpreadsheet = mySpreadsheet;
    Spreadsheet anotherSpreadsheet(2, 2);
    anotherSpreadsheet = mySpreadsheet;

    // Test other functionalities as needed

    return 0;
}

