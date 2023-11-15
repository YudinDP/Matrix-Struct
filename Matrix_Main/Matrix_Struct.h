#pragma once
#include <vector>
//����� �������
class Matrix {

private:
	//����
	std::vector<std::vector <double>> Matr;//���� ������� �������������� ������ �������� ���� double

	//author Yudin

public: 
	//������
	
	//����������� �� ��������� - ��������� ������ ������� 3x3, ���� ��� ���������� �� ���� ������� �������
	Matrix();

	//����������� � ����������� - ��������� ������ ������� rowXcol
	Matrix(unsigned int row, unsigned int col);

	//����������
	~Matrix();

	//������ ������� � ���� ������� �� �������� ���� double
	std::vector<std::vector<double>> Get_Matr();

	//����� ������� �� �����
	void Output_Matrix();

	//������ �������� ������� �� ��� ������������� � ���������� ��������� � �������
	double Get_Element(unsigned int row, unsigned int col);

	//������ �������� ������� �� ��� ������������� � ���������� ��������� � �������
	void Set_Element(unsigned int row, unsigned int col, double param);

	//������ ������ ������� �� �� ������(�� ����� �������� double ������)
	std::vector<double> Get_Str(unsigned int row);

	//������ ������ ������� �� �� ������ � ������������� ������� ���� double �� �� �����������
	void Set_Str_By_Vector(unsigned int row, std::vector<double> str);

	//������ ������ ������� �� �� ������ � ������������� ������� ���� double �� �� �����������
	void Set_Str_By_Keyboard(unsigned int row);

	//���������� ������� ����� ������������ ������ number
	void Fill_With(double number);

	//���������� ������� ���������� ������� �� ��������� min - max
	void Fill_Random(double min, double max);

	//��������� ������� �� ����� number
	void Matr_X_Number(double number);

	//���������������� �������� �������(�������� ������ ��� ����������)
	void Transposition();

	//�������� ������������ ������� �� ��������
	void Diagonal();

	//�������� �������� ������(������������ ��� ������ - ������ �� �������� ���� double)
	void operator+= (std::vector<std::vector<double>> Matr2);

	//�������� ��������� ������(������������ ��� ������ - ������ �� �������� ���� double)
	void operator-= (std::vector<std::vector<double>> Matr2);

	//�������� ��������� ������(������������ ��� ������ - ������ �� �������� ���� double)
	void operator*= (std::vector<std::vector<double>> Matr2);

	//���������� �������� ������� � �������� ������� ������(������ ��� ���������� ������!!!)
	void Reverse_Matrix();

	//���������� ������������ ���������� �������(������ 1-4 �������!!!)
	double Determinant();
};

//�������� ������� �������
void Test();

