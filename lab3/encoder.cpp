#include "encoder.h"

encoder::encoder()
{
	readfile = "",
		decode = "",
		encode = "",
		choice = 0;
}
// Кодирование
string encoder::TextToBinaryString(string words)
{
	encode = "";
	try
	{
		for (char& _char : words)
			// Передаем символ, представляя его в бинарной записи
			// и конвертируем в string
			encode += bitset<8>(_char).to_string();
	}
	catch (...)
	{

	}
	return encode;
}
// Декодирование
string encoder::BinaryToTextString(string data)
{
	std::stringstream sstream(data);
	decode = "";
	try
	{
		// Проверка потока на ошибку/конец
		while (sstream.good())
		{
			std::bitset<8> bits; // Создали контейнер на 8 битов
			sstream >> bits; // Заполнили контейнер
			// Получили код символа и преобразовали в символ
			decode += char(bits.to_ulong());
		}
	}
	catch (...)
	{

	}
	return decode;
}

void encoder::EncodeAndWriteToFile(string data)
{
	try
	{
		// Побайтовая запись
		string text = TextToBinaryString(data);
		std::fstream fw("file.binary", std::ios::out | std::ios::binary);
		if (fw.is_open())
		{
			for (int i = 0; i < text.size(); i++)
				fw.write(&text[i], sizeof(char));
			fw.close();
		}
	}
	catch (...)
	{

	}
}

string encoder::ReadAndDecodeFile(string name)
{
	string result = "";
	try
	{
		// Побайтовое чтение
		std::fstream fs(name, std::ios::in | std::ios::binary);
		if (fs.is_open())
		{
			char byte = '\0';
			while (!fs.eof())
			{
				if (byte != '\0')
					result += byte;
				fs.read(&byte, sizeof(char));
			}
			fs.close();
		}
	}
	catch (...)
	{

	}
	return BinaryToTextString(result);
}

void encoder::WriteToFile(string filename, string data)
{
	try
	{
		// Побайтовая запись
		std::fstream fw(filename, std::ios::out | std::ios::binary);
		if (fw.is_open())
		{
			for (int i = 0; i < data.size(); i++)
				fw.write(&data[i], sizeof(char));
			fw.close();
		}
	}
	catch (...)
	{

	}
}

string encoder::ReadFile(string name)
{
	readfile = "";
	try
	{
		// Побайтовое чтение
		std::fstream fs(name, std::ios::in | std::ios::binary);
		if (fs.is_open())
		{
			char byte = '\0';
			while (!fs.eof())
			{
				if (byte != '\0')
					readfile += byte;
				fs.read(&byte, sizeof(char));
			}
			fs.close();
		}
	}
	catch (...)
	{

	}
	return readfile;
}

void encoder::menu(int& choice)
{
	cout << "1. Прочитать файл и закодировать" << endl;
	cout << "2. Прочитать файл и декодировать" << endl;
	cout << "3. Завершить работу" << endl;
	cout << "Выбор: "; cin >> this->choice;
	choice = this->choice;
}

string encoder::getReadFile()
{
	return readfile;
}

string encoder::getDecode()
{
	return decode;
}

string encoder::getEncode()
{
	return encode;
}

int encoder::getChoice()
{
	return choice;
}
