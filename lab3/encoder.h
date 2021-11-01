#pragma once
#include <Windows.h>
#include <iostream>
#include <sstream>
#include <bitset>
#include <fstream>
#include <limits>
using namespace std;

class encoder
{
public:
	encoder();
	string TextToBinaryString(string words); // �����������
	string BinaryToTextString(string data); // �������������
	void EncodeAndWriteToFile(string data); // ������������ � �������� � ����
	string ReadAndDecodeFile(string name); // ��������� � ������������ ����
	void WriteToFile(string filename, string data); // �������� � ����
	string ReadFile(string name); // ��������� ����
	void menu(int& choice);
	string getReadFile();
	string getDecode();
	string getEncode();
	int getChoice();
private:
	string readfile, decode, encode;
	int choice;
};

