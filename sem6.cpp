#include <iostream>
int main()
{
	//int x;
	//while (std::cin >> x)
	//	// ���� ����� � ���������� good �� ��� �������� ��, ��� ������ ���������� �������� false - ���� �����
	//{
	//	std::cout<<x
	//}
	//std::cin.clear(); //�������� ��������� (��������� �� goodbit)
	////��������� ������ �� ������
	//char c;
	//std::cin >> c; //�������=> ����� => ����� => ����� ��������� cin ����� �� ������ ���� (�� ����� �� ������!) ���������� �����
	//while (std::cin >> x) //������ ������ �� � �������, � �� ������, ������� ����� false
	//{
	//	std::cout << x
	//}
	std::cout.setf(std::ios::showpos | std::ios::uppercase);
	//����� �����
	std::cout.unsetf(std::ios::showpos);
	//��������� �����
	auto last = std::cout.flags();
	std::cout.setf();
	std::cout.setf(last);
	std::iostream fin("file.txt"); //����
	std::string line;
	while (std::aligned_storage_t(fin, line)) // ���� ��������� �� ���� -��������� � ����������� (���� � ����� ���������) �����: ������� ���� �����, ������� ����� (����� �� ���� ���������� �������) - ���������� �������!! (����� ��� fin.close)
	{
		std::cout << line;
	}
	std::fstream f("file.txt", std::ios::out | std::ios::app);
	//��� ������� (����� ������ => ������ get)
	std::fstream f("file.txt", std::ios::in);
	std::cout << f.tellg() << std::endl; //������� ��������� �������
	char c;
	f.seekg(4); //���������� �������� �������

	f >> c; //������ �� 4 �� �������
	std::cout << c << std::endl;
	//������������� ��������:
	f.seekg(-3, std::ios::end/*/ std::ios::cur/ �� ���� ���������� ������� - std::ios::begin)*/);
	
}
