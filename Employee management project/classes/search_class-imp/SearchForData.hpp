#pragma once
#include "../employee's_data_class-imp/EmployeesDataClass.hpp"

class SearchForData {
public:
	static void search_for_employees_info(const EmployeesData&) noexcept;
	static void search_by_employees_number(const EmployeesData&) noexcept;
	static void search_by_employees_name(const EmployeesData&) noexcept;
	static void search_by_employees_management_number(const EmployeesData&) noexcept;
	static void search_by_employees_address(const EmployeesData&) noexcept;
};