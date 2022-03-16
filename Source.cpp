#include <iostream>
#include <fstream>
#include <string>
#include <bitset> //��� �������� � 2 �������
using namespace std;

/*�������� �������� ������� �� ������ � �������. �������
����� ����� ��������� ���� � ���������� ��� ����������
� �������, ������ ����� ������� ��������� ����
� ���������� ���������� � ���� ASCII-����� ��������,
������������� � �����, ������ ����� ������� ���������
���� � ���������� ��� ���������� � �������� ���� ��.�.
��� ����������� ����������� ����� � ������� ������
���������� ����������� �������*/

class Base {
protected:
	int size = 0;
	string file_text;
public:
	virtual void Read_file(const char* str) { //������� ����������� 
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

class Tbase : public Base { //������� ����� ASCII �������
public:
	friend ostream& operator << (ostream& stream, const Tbase& gg) {
		for (int i = 0; i < gg.size; i++) {
			stream << (int)gg.file_text[i] << " ";
		}
		return stream;
	}
};

class Hbase : public Base { //��������� ������ ����� � 2 �������
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