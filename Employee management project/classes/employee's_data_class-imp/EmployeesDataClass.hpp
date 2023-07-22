#pragma once
#include "../employee's_class_attributes/EmployeesClass.hpp"

class EmployeesData : public Employees {
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