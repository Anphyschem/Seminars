#include <iostream>
#include <thread>
#include <future>

void f(int x)
{
	std::cout << " H" << x ;
}
int main(int argc, char** argv)
{

	std::cout << std::thread::hardware_concurrency() << std::endl; // 8���� � 4 ��� ����
	int x = 42;
	std::thread t(f,x); //����������� x ������ ����� �������� ����������� ������: ������� ����� �������� ������ ������������ �����
	std::thread t(f, std::ref(x)); //std::ref(x) �� ������ - ������� ���������� ����������� ����������� ��������� (������ ���� ��������)
						//����� ����� ���� ������ main
	t.join();//main ���� ����� t (������� ���������� ������ t)
	t.detach(); //������� ������ (main fin - t �����, �� ���� �������� ��) ��������� ������� �����: -while true; ������� ������ � ���������;
	std::future<int> result = std::async([]() {return 43; });
	std::cout << result.get() << std::endl; //���� ���� � ����������� �� ���� wait - ��� � get ����� ������� 1 ��� (���� �� ���� ��), valid
	//void - wait (��� ���������� ������ ���������� �������)
	//async - ��� ���������, ��� � ���������� (�� ���������� ����� ����������) - ���� too much, �� ������ ����� ����������� ���������  (�����������)
	//std::launch::async([]....); //�������� ���������� ������ (�������� ��� �� ��������)
	//std::deferred::async....;// ���������� ��������� - �� ������� �� ���� 
	std::packaged_task<int()>task([]() {return 42; }); //��������� ������ ������ ���� �������, ������� �� ��������� ���������� � ���������� ���
		std::future<int>result = task.get_future();
		std::thread(std::move(task)).detach();
	
	system("pause");
	return EXIT_SUCCESS;
}