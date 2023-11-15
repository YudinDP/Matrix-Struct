#include "Matrix_struct.h"//������������ ���� � �������
#include <iostream> //����-�����
#include <iomanip> //��� ��������� ������
#include <stdlib.h>// ���������� ������� srand,rand
#include <vector> //��� �������� //author Yudin
#include <cmath> //��� ���������� � �������� �������
#include <stdexcept> //��� try-catch
#include <cassert> //��� assert-��
using namespace std;


//����������� �� ��������� - ��������� ������ ������� 3x3
Matrix::Matrix() {
	unsigned int n = 3;
	Matr.resize(n);
	for (unsigned int i = 0; i < n; i++) {
		Matr[i].resize(n);
	}
}

//����������� � ����������� - ��������� ������ ������� rowXcol
Matrix::Matrix(unsigned int row, unsigned int col) {
	if (row < 1 || col < 1) {  //������ ����������, ���� ������ ������� �� ������� ��� �������� < 1
		throw std::invalid_argument("Incorrect parameters of matrix size");
	}
	else {
		Matr.resize(row);
		for (unsigned int i = 0; i < row; i++) {
			Matr[i].resize(col);
		}
	}
}

//����������
Matrix::~Matrix() {
	cout << "~Matrix" << endl;
	Matr.clear();
}


//������ ������� � ���� ������� �� �������� ���� double
std::vector<std::vector<double>> Matrix::Get_Matr() {
	return Matr;
}
//����� ���� ������� �� �����
void Matrix::Output_Matrix() {
	cout << endl;
	for (unsigned int i = 0; i < Matr.size(); i++) {
		cout.precision(2);
		for (unsigned int j = 0; j < Matr[i].size(); j++) {
			cout << setfill(' ') << setw(12) << fixed << Matr[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

//������ �������� ������� �� ��� ������������� � ���������� ��������� � �������
double Matrix::Get_Element(unsigned int row, unsigned int col) {  
	if ((row < 0 || row > Matr.size()) || (col < 0 || col > Matr[0].size())) { //������ ���������, ���� ������� ������������ ���������� � �������
		throw std::invalid_argument("Incorrect Matrix coordinate");
	}
	else
	{
		return Matr[row][col];
	}
}

//������ �������� ������� �� ��� ������������� � ���������� ��������� � �������
void Matrix::Set_Element(unsigned int row, unsigned int col, double param) {  
	if ((row < 0 || row > Matr.size()) || (col < 0 || col > Matr[0].size())) { //������ ���������, ���� ������� ������������ ���������� � �������
		throw std::invalid_argument("Incorrect Matrix coordinate");
	}
	else 
	{
		Matr[row][col] = param;
	}
}

//������ ������ ������� �� �� ������(�� ����� �������� double ������)
std::vector<double> Matrix::Get_Str(unsigned int row) {
	if (row < 0 || row > Matr.size()) {  //������ ����������, ���� ����������� ������� ����� ������
		throw std::invalid_argument("Incorrect row number");
	}
	else {
		return Matr[row];
	}
}

//������ ������ ������� �� �� ������ � ������������� ������� ���� double �� �� �����������
void Matrix::Set_Str_By_Vector(unsigned int row, const std::vector<double> str) {
	if (row < 0 || row > Matr.size()) {  //������ ����������, ���� ����������� ������� ����� ������
		throw std::invalid_argument("Incorrect row number");
	}
	else if (str.size() != Matr[row].size()) { //���������� �� ����������� ����� ������������� �������
		throw std::length_error("Incorrect new string length");
	}
	else
	{
		for (unsigned int i = 0; i < Matr[row].size(); i++) {
			Matr[row][i] = str[i];
		}
	}
}

//������ ������ ������� �� �� ������ � ������������� ������� ���� double �� �� �����������
void Matrix::Set_Str_By_Keyboard(unsigned int row) {
	if (row < 0 || row > Matr.size()) {  //������ ����������, ���� ����������� ������� ����� ������
		throw std::invalid_argument("Incorrect row number");
	}
	else
	{
		cout << "input elements:" << endl;
		for (unsigned int i = 0; i < Matr[row].size(); i++) {
			cin >> Matr[row][i];
		}
	}
}

//���������� ������� ����� ������������ ������ number
void Matrix::Fill_With(double number) {
	for (unsigned int i = 0; i < Matr.size(); i++) {
		for (unsigned int j = 0; j < Matr[i].size(); j++) {
			Matr[i][j] = number;
		}
	}
}

//���������� ������� ���������� ������� �� ��������� min - max
void Matrix::Fill_Random(double min, double max) {
	if (min > max || min == max) {  //������ ����������� ���� �������� ������ �����������
		throw std::range_error("Incorrect random range input. Correct examples: (10, 20),  (1.12, 2.56)");
	}
	else
	{
		for (unsigned int i = 0; i < Matr.size(); i++) {
			for (unsigned int j = 0; j < Matr[i].size(); j++) {
				Matr[i][j] = (1.0 * rand() / RAND_MAX * (max - min) + min);//��������� ���������� ����� �� min �� max
			}
		}
	}
}

//��������� ������� �� ����� number
void Matrix::Matr_X_Number(double number) {
	for (unsigned int i = 0; i < Matr.size(); i++) {
		for (unsigned int j = 0; j < Matr[i].size(); j++) {
			Matr[i][j] = Matr[i][j] * number;
		}
	}
}

//���������������� �������� �������
void Matrix::Transposition() {
	std::vector<std::vector<double>> T;   //������� ������� T ����������������� �����������
	T.resize(Matr[0].size());  //� ������� ����� ��������������� ���������� �������� �������� �������
	for (unsigned int i = 0; i < Matr[0].size(); i++) {
		T[i].resize(Matr.size());
	}

	//��������������� ������������ �������� �� Matr � T 
	for (unsigned int i = 0; i < Matr.size(); i++) {
		for (unsigned int j = 0; j < Matr[i].size(); j++) {
			T[j][i] = Matr[i][j];
		}
	}

	//������������� ����������� �������� �������
	Matr.resize(T.size());
	for (unsigned int i = 0; i < T.size(); i++) {
		Matr[i].resize(T[i].size());
	}

	//������������ �������� �� T � Matr
	for (unsigned int i = 0; i < T.size(); i++) {
		for (unsigned int j = 0; j < T[i].size(); j++) {
			Matr[i][j] = T[i][j];
		}
	}

}

//�������� ������������ ������� �� ��������
void Matrix::Diagonal() {
	for (unsigned int i = 0; i < Matr.size(); i++) {
		for (unsigned int j = 0; j < Matr[i].size(); j++) {
			if(i != j)
				Matr[i][j] = 0.0;
		}
	}
}

//�������� �������� ������(������������ ��� ������ - ������ �� �������� ���� double)
//����� ������� � ������ �������� ����� ������ ����� � ������������� ������� ������� ����� Get_Matr
void Matrix::operator+= (const std::vector<std::vector<double>> Matr2) {
	if (Matr2.size() != Matr.size() || Matr2[0].size() != Matr[0].size()) { //������ ����������, ���� ������� ������������ ������ ������
		throw std::length_error("Incorrect size of Matrix you want to add");
	}
	else
	{
		for (unsigned int i = 0; i < Matr.size(); i++) {
			for (unsigned int j = 0; j < Matr[i].size(); j++) {
				Matr[i][j] = Matr[i][j] + Matr2[i][j];
			}
		}
	}
}

//�������� ��������� ������(������������ ��� ������ - ������ �� �������� ���� double)
//����� ������� � ������ �������� ����� ������ ����� � ����������� ������� ������� ����� Get_Matr
void Matrix::operator-= (const std::vector<std::vector<double>> Matr2) {
	if (Matr2.size() != Matr.size() || Matr2[0].size() != Matr[0].size()) {  //������ ����������, ���� ������� ���������� ������ ������
		throw std::length_error("Incorrect size of Matrix you want to add");
	}
	else
	{
		for (unsigned int i = 0; i < Matr.size(); i++) {
			for (unsigned int j = 0; j < Matr[i].size(); j++) {
				Matr[i][j] = Matr[i][j] - Matr2[i][j];
			}
		}
	}
}

//�������� ��������� ������(������������ ��� ������ - ������ �� �������� ���� double)
//����� �������� �� ������ ������ ����� ������ ����� � ������� �� ������� �������� ������� ����� Get_Matr
//������ ��� ���-�� �������� 1-� ������� = ���-�� ����� 2-�
void Matrix::operator*= (const std::vector<std::vector<double>> Matr2) {
	if (Matr[0].size() != Matr2.size()) {
		throw std::length_error("Incorrect size of Matrix you want to multiply by. Correct: col of Matrix1 = row of Matrix2");
	}
	else
	{
		std::vector<std::vector<double>> Matr_count;//������� ���.������� ��� ���������� ��������� ���� ����������� ��������
		Matr_count.resize(Matr2.size());
		for (unsigned int i = 0; i < Matr2.size(); i++)
		{
			Matr_count[i].resize(Matr2[i].size());
		}
		double count = 0.0; int a = 0; //���������� ��� �����
		for (unsigned int i = 0; i < Matr2.size(); i++) {
			for (unsigned int j = 0; j < Matr2[i].size(); j++) {
				a = 0; count = 0.0;
				while (a < Matr2.size()) {
					count = count + (Matr[i][a] * Matr2[a][j]);
					a++;
				}

				Matr_count[i][j] = count;
			}
		}

		//������ ����������� �������� ������� ����������� ��� �������, �� ������� �������� ��� �������������
		if (Matr2[0].size() != Matr[0].size()) {
			Matr.resize(Matr2.size());
			for (unsigned int i = 0; i < Matr2.size(); i++) {
				Matr[i].resize(Matr2[i].size());
			}
		}

		//���������� �������� � �������� �������
		for (unsigned int i = 0; i < Matr_count.size(); i++) {
			for (unsigned int j = 0; j < Matr_count[i].size(); j++) {
				Matr[i][j] = Matr_count[i][j];
			}
		}
	}
}

//���������� �������� ������� � �������� ������� ������(������ ��� ���������� ������!!!)
void Matrix::Reverse_Matrix() {
	double pairsum, sqsum;
	unsigned int const n = Matr.size();
	std::vector<std::vector<double>> l;  l.resize(n);
	std::vector<std::vector<double>> y;  y.resize(n);
	std::vector<std::vector<double>> AInv;  AInv.resize(n);
	std::vector<std::vector<double>> u;  u.resize(n);
	std::vector<std::vector<double>> x;  x.resize(n);
	for (unsigned int i = 0; i < n; i++) {
		l[i].resize(n); y[i].resize(n); AInv[i].resize(n); u[i].resize(n); x[i].resize(n);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			u[i][j] = Matr[i][j];
			l[i][j] = Matr[i][j];
			y[i][j] = 0.0;
			x[i][j] = 0.0;
			AInv[i][j] = 0.0;
		}
	}

	int k = 0;
	while (k < n) {
		for (int i = 0; i < n; i++) {
			for (int j = n - 1 - k; j < n; j++) {
				if (j > i) {
					u[i][j] = 0.0;
				}
				if (j == i) {
					u[i][j] = 1.0;
				}
				if (j < i) {
					l[i][j] = 0.0; 
				}
			}
		}
		k = k + 1;
	}


	//���������� ��������� ������ L � U
	for (int i = 0; i < n; i++) {
		l[i][0] = Matr[i][0];
	}
	for (int j = 1; j < n; j++) {
		u[0][j] = Matr[0][j] / l[0][0];
	}


	for (int k = 1; k < n; k++) {
		for (int i = k; i < n; i++) {
			l[i][k] = Matr[i][k];
			for (int m = 0; m < k; m++) {
				l[i][k] = (l[i][k] - l[i][m] * u[m][k]);
			}
		}
		if (k <= n - 2) {
			for (int j = k + 1; j < n; j++) {
				u[k][j] = Matr[k][j];
				for (int m = 0; m < k; m++) {
					u[k][j] = u[k][j] - l[k][m] * u[m][j];
				}
				u[k][j] = u[k][j] / l[k][k];
			}
		}
	}


	//����������� ������ Y
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j > i) {
				y[i][j] = 0.0;
			}
			else if (j == i) {
				y[i][j] = 1.0 / l[i][i];
			}
			else if (j < i) {
				y[i][j] = 0.0;
				for (int m = j; m < i; m++) {
					y[i][j] = y[i][j] - l[i][m] * y[m][j];
				}
				y[i][j] = y[i][j] / l[i][i];
			}
		}
	}


	//���������� ������� x
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			if (j < i) {
				x[i][j] = 0.0;
			}
			else if (j == i) {
				x[i][j] = 1.0;
			}
			else if (j > i) {
				x[i][j] = 0.0;
				for (int m = i + 1; m <= j; m++) {
					x[i][j] = x[i][j] - u[i][m] * x[m][j];
				}
			}
		}
	}


	//���������� � ����� ������� �������� � A
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Matr[i][j] = 0.0;
			for (int m = 0; m < n; m++) {
				Matr[i][j] = Matr[i][j] + x[i][m] * y[m][j];
			}
		}
	}
	

}

//���������� ������������ ���������� �������(������ 1-3 �������!!!)
double Matrix::Determinant() {
	if (Matr.size() == 1) {
		return Matr[0][0];
	}
	
	if (Matr.size() == 2) {
		return(Matr[0][0] * Matr[1][1] - Matr[0][1] * Matr[1][0]);
	}

	if (Matr.size() == 3) {
		double a = Matr[0][0] * (Matr[1][1] * Matr[2][2] - Matr[1][2] * Matr[2][1]);

		double b = Matr[0][1] * (Matr[1][0] * Matr[2][2] - Matr[1][2] * Matr[2][0]);

		double c = Matr[0][2] * (Matr[1][0] * Matr[2][1] - Matr[1][1] * Matr[2][0]);
	
		return a - b + c;
	}
}

//�������� ������� �������
void Test() {

	//������ ������ � ������� �1(try-catch)
	try {
		Matrix M(1, 3); //����� ������������� ���������� ��� ������������ ������� �������
	}
	catch (const std::invalid_argument a) {
		cout << a.what() << endl; //����� � ������� ����������
	}


	//���� assert
	Matrix M(2, 2);
	M.Fill_With(2);
	M.Output_Matrix(); //�������� ������������ ������ �������(��������� ������� 2x2 ����������� ��������)
	assert(M.Get_Element(0, 0) == 2 && M.Get_Element(1, 0) == 2); //�������� ������������ ���������� ������� ����� ���������

	M.Set_Element(0, 1, 3);
	assert(M.Get_Element(0, 1) == 3); //�������� ������������ ������� � ��������� �������

	std::vector<double> V{1, 1};
	M.Set_Str_By_Vector(0, V);
	assert(M.Get_Element(0, 0) == 1 && M.Get_Element(1, 0) == 2); //�������� ������������ ������� � ������� �������

	M.Fill_Random(10, 20); //��������� �������� �� 10 �� 20
	for (unsigned int i = 0; i < 2; i++) {
		for (unsigned int j = 0; j < 2; j++) {
			assert(M.Get_Element(0, 0) >= 10 && M.Get_Element(0, 0) <= 20); //�������� ������������ ������ ������������
		}
	}

	M.Fill_With(1);
	M.Matr_X_Number(3);
	assert(M.Get_Element(0, 0) == 3 && M.Get_Element(1, 0) == 3); //�������� ������������ ��������� ������� �� �����

	M.Diagonal();
	assert(M.Get_Element(0, 0) == 3 && M.Get_Element(1, 0) == 0);//�������� ������������ �������

	M.Transposition();
	assert(M.Get_Element(0, 0) == 3 && M.Get_Element(1, 0) == 0);//�������� ����������������� �������

	Matrix N(2, 2);
	N.Fill_With(2);
	M.Fill_With(3);
	M += N.Get_Matr();
	assert(M.Get_Element(0, 0) == 5 && M.Get_Element(1, 1) == 5); //�������� �������� ������
	M -= N.Get_Matr();
	assert(M.Get_Element(0, 0) == 3 && M.Get_Element(1, 1) == 3); //�������� ��������� ������
	M *= N.Get_Matr();
	assert(M.Get_Element(0, 0) == 12 && M.Get_Element(1, 1) == 12); //�������� ��������� ������

	assert(M.Determinant() == 0); //�������� ������������ �������

	M.Fill_With(2); M.Set_Element(0, 0, 1);
	M.Reverse_Matrix();
	assert(M.Get_Element(0, 0) == -1 && M.Get_Element(1, 1) == -0.5);
}