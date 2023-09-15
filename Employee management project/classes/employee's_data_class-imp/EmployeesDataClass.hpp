#pragma once
#include "../employee's_attributes_class/EmployeesAttributesClass.hpp"

class EmployeesData : public EmployeesAttributes {
public:
	void HireNewEmployee() noexcept;
	void UpdatingEmployeesInfo() noexcept;
	void DeletingEmployeeInfo() noexcept;

	bool isEmpty() const noexcept;
	constexpr bool CheckIfDataExist(bool) const noexcept;

private:
	friend class PrintInfo;
	friend class SearchForData;
};