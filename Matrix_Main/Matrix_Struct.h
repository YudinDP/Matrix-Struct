#pragma once
#include <vector>
//класс матрицы
class Matrix {

private:
	//поля
	std::vector<std::vector <double>> Matr;//сама матрица представляющая вектор векторов типа double

	//author Yudin

public: 
	//методы
	
	//конструктор по умолчанию - заполняет нулями матрицу 3x3, если при объявлении не были введены размеры
	Matrix();

	//конструктор с параметрами - заполняет нулями матрицу rowXcol
	Matrix(unsigned int row, unsigned int col);

	//деструктор
	~Matrix();

	//геттер матрицы в виде вектора из векторов типа double
	std::vector<std::vector<double>> Get_Matr();

	//вывод матрицы на экран
	void Output_Matrix();

	//геттер элемента матрицы по его передаваемому в параметрах положению в матрице
	double Get_Element(unsigned int row, unsigned int col);

	//сеттер элемента матрицы по его передаваемому в параметрах положению в матрице
	void Set_Element(unsigned int row, unsigned int col, double param);

	//геттер строки матрицы по ее номеру(на выход подается double вектор)
	std::vector<double> Get_Str(unsigned int row);

	//сеттер строки матрицы по ее номеру и передаваемому вектору типа double то же размерности
	void Set_Str_By_Vector(unsigned int row, std::vector<double> str);

	//сеттер строки матрицы по ее номеру и передаваемому вектору типа double то же размерности
	void Set_Str_By_Keyboard(unsigned int row);

	//заполнение матрицы одним передаваемым числом number
	void Fill_With(double number);

	//заполнение матрицы случайными числами из диапазона min - max
	void Fill_Random(double min, double max);

	//умножение матрицы на число number
	void Matr_X_Number(double number);

	//транспонирование исходной матрицы(работает только для квадратной)
	void Transposition();

	//создание диагональной матрицы из исходной
	void Diagonal();

	//оператор сложения матриц(передаваемый тип данных - вектор из векторов типа double)
	void operator+= (std::vector<std::vector<double>> Matr2);

	//оператор вычитания матриц(передаваемый тип данных - вектор из векторов типа double)
	void operator-= (std::vector<std::vector<double>> Matr2);

	//оператор умножения матриц(передаваемый тип данных - вектор из векторов типа double)
	void operator*= (std::vector<std::vector<double>> Matr2);

	//вычисление обратной матрицы к исходной методом корней(только для квадратных матриц!!!)
	void Reverse_Matrix();

	//вычисление определителя квадратной матрицы(только 1-4 порядка!!!)
	double Determinant();
};

//проверка методов матрицы
void Test();

