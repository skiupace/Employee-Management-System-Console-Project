#pragma once
#include "../employee's_data_class-imp/EmployeesDataClass.hpp"

class PrintInfo {
public:
	void ViewMainMenu();
	void ViewAboutProgramMenu();
	void ViewUpdatingOptions();
	void ViewSearchingOptions();
	void PrintErrorMessage();
	void ViewAllEmployeesInfo(const EmployeesData& obj);
};