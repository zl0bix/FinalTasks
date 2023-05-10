#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>

template <typename ANY>
void fill_arr(ANY arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++){
		arr[i] = rand() % (right - left) + left;
	}
}

template <typename ANY>
void print_arr(ANY arr[], const int length) {
	for (int i = 0; i < length; i++) 
		std::cout << arr[i] << ' ';
	std::cout << "\n\n";
}

// Направление указателя на двумерный динамический массив
template <typename ANY>
void memory_mx(ANY**& pointer, int rows, int cols) {
	pointer = new ANY*[rows];
	for (int i = 0; i < rows; i++){
		pointer[i] = new ANY[cols]{};
	}
}
// Удаление памяти под двумерный динамический массив
template <typename ANY>
void clear_mx(ANY**&pointer, int rows) {
	for (int i = 0; i < rows; i++)
		delete[] pointer[i];
	delete[] pointer;
	pointer = nullptr;
}

template <typename ANY>
ANY* arr_ptr(ANY arr1[], const int length1, ANY arr2[], const int length2, int &var) {
	ANY* tmp = new ANY[length1 + length2]{};
	var = 0;
	for (int i = 0; i < length1; i++)
		if (arr1[i] > 0) 
			tmp[var++] = arr1[i];

	for (int i = 0; i < length2; i++)
		if (arr2[i] > 0)
			tmp[var++] = arr2[i];
		
	ANY*result = new ANY[var];
	for (int i = 0; i < var; i++){
		result[i] = tmp[i];
	}
	
	delete[] tmp;
	return result;
}
/*
void txt_add(int num,std::string str) {
	if ((num > -100 && num < -9) || num > 9 && num < 100) {
		std::ofstream rec("file.txt");
		
		if (num > 9 && num < 20) {
			switch (num) {
			case 11: {
				str = "Одинадцать\n";
				rec << str;
				break;
			}
			case 12: {
				str = "Двинадцать\n";
				rec << str; break;
			}
			case 13: {
				str = "Тринадцать\n";
				rec << str; break;
			}
			case 14: {
				str = "Четырнадцать\n";
				rec << str; break;
			}
			case 15: {
				str = "Пятнадцать\n";
				rec << str; break;
			}
			case 16: {
				str = "Шестнадцать\n";
				rec << str; break;
			}
			case 17: {
				str = "Семнадцать\n";
				rec << str; break;
			}
			case 18: {
				str = "Восемьнадцать\n";
				rec << str; break;
			}
			case 19: {
				str = "Девятнадцать\n";
				rec << str; break;
			}
			}
		}
		else
			std::cout << "Error!";
}

*/


bool number_num(int num, std::string file_path) {
	if (num < 10 || num>99)
		return false;

	static const char* tens[]{
		"двадцать",
		"тридцать",
		"сорок",
		"пятьдесят",
		"шестьдесят",
		"семьдесят",
		"восемьдесят",
		"девяносто",
	};
	static const char* ones[]{
		"",
		"один",
		"два",
		"три",
		"четыре",
		"пять",
		"шесть",
		"семь",
		"восемь",
		"девять"
	};
	static const char* exceps[]{
		"десять",
		"одинадцать",
		"двеннадцать",
		"тринадцать",
		"четырнадцать",
		"пятнадцать",
		"шестнадцать",
		"семнадцать",
		"восемнадцать",
		"девятнадцать",
	};
	int num1 = num / 10;
	int num2 = num % 10;

	std::ofstream file;
	file.open(file_path);

	if (num1 == 1) {
		file << exceps[num2] << '\n';
		file.close();
		return true;
	}

	file << tens[num1 - 2] << ones[num2] << '\n';
	file.close();
	return true;
}


int main() {
	int n, m;
	setlocale(LC_ALL, "rus");
	// Matrix arr + 2 nubers
	/*
	std::cout << "Ex1\nEnter | arr -> ";
	std::cin >> n;
	std::cout << "Enter - arr -> ";
	std::cin >> m;

	int**mx = nullptr;
	memory_mx(mx, n, m);
	std::cout << "Итоговый массив:\n";
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)
			std::cout << mx[i][j];
		std::cout << std::endl;
	}
	clear_mx(mx, n);

	std::cout << std::endl;
	*/
	//Ex2 Arr > 0
	/*
	std::cout << "Ex2\n";
	const int size1 = 7;
	const int size2 = 6;
	int arr1[size1], arr2[size2];
	fill_arr(arr1, size1, -10, 15);
	fill_arr(arr2, size2, -15, 10);
	std::cout << "Первый массив:\n";
	print_arr(arr1, size1);
	std::cout << "Второй массив:\n";
	print_arr(arr2, size2);
	int size3;
	int* arr3 = arr_ptr(arr1, size1, arr2, size2, size3);
	std::cout << "Итоговый массив:\n";
	print_arr(arr3, size3);
	*/
	//Ex3
	/*std::cout << "Ex3" << std::endl;
	std::ofstream rec("file.txt", std::ios::app);
	int num3;
	std::string str3;
	std::cin >> num3;
	txt_add(num3, str3);
	*/
	int n3 = 13;
	std::string str3;
	if (number_num(n3, "number.txt"))
		std::cout << "Good";
	else
		std::cout << "Ne Good";


	return 0;
}
