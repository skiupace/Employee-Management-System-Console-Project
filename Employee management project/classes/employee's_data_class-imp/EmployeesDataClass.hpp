#pragma once
#include "../employee's_attributes_class/EmployeesAttributesClass.hpp"

class EmployeesData : public EmployeesAttributes {
public:
	const bool isEmpty() const;
	void HireNewEmployee();
	void UpdatingEmployeesInfo();
	void DeletingEmployeeInfo();
	bool CheckIfDataExist(bool) const;

	class TakeInput {
	public:
		template<class T>
		void InputAndErrorHanlder(T& var) const;
	} input;

private:
	friend class PrintInfo;
	friend class SearchForData;
};