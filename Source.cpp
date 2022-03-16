#include <iostream>
#include <fstream>
#include <string>
#include <bitset> //для перевода в 2 систему
using namespace std;

/*Создайте иерархию классов по работе с файлами. Базовый
класс умеет открывать файл и отображать его содержимое
в консоль, первый класс потомка открывает файл
и отображает содержимое в виде ASCII-кодов символов,
расположенных в файле, второй класс потомка открывает
файл и показывает его содержимое в двоичном виде ит.д.
Для отображения содержимого файла в базовом классе
определена виртуальная функция*/

class Base {
protected:
	int size = 0;
	string file_text;
public:
	virtual void Read_file(const char* str) { //базовый конструктор 
		ifstream myfile(str);
		while (myfile >> file_text);
		size = file_text.size();
		myfile.close();
	}

	friend ostream& operator << (ostream& stream, const Base& gg) {
		for (int i = 0; i < gg.size; i++) {
			stream << gg.file_text[i] << " ";
		}
		return stream;
	}
};

class Tbase : public Base { //выводит номер ASCII символа
public:
	friend ostream& operator << (ostream& stream, const Tbase& gg) {
		for (int i = 0; i < gg.size; i++) {
			stream << (int)gg.file_text[i] << " ";
		}
		return stream;
	}
};

class Hbase : public Base { //переводит каждую букву в 2 систему
public:
	friend ostream& operator << (ostream& stream, const Hbase& gg) {
		for (int i = 0; i < gg.size; i++) {
			bitset <8> x(gg.file_text[i]);
			stream << x << " ";
		}
		return stream;
	}
};




int main() {
	Base a;
	a.Read_file("open.txt");
	cout << a;
	cout << endl;

	Tbase s;
	s.Read_file("open.txt");
	cout << s;
	cout << endl;

	Hbase d;
	d.Read_file("open.txt");
	cout << d;
}