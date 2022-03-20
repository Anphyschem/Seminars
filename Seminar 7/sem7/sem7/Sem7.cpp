#include <iostream>
#include <thread>
#include <future>

void f(int x)
{
	std::cout << " H" << x ;
}
int main(int argc, char** argv)
{

	std::cout << std::thread::hardware_concurrency() << std::endl; // 8вирт и 4 физ ядра
	int x = 42;
	std::thread t(f,x); //копирование x внутри треда механика вариативный шаблон: сначала копию передаем всегда конструктору треда
	std::thread t(f, std::ref(x)); //std::ref(x) по ссылке - обертка показывает ссылочность переданного аргумента (ссылку тоже копируем)
						//здесь могут быть задачи main
	t.join();//main ждет поток t (ожидаем завершение задачи t)
	t.detach(); //фоновая задача (main fin - t пофиг, за него отвечает ОС) Опасность фоновых задач: -while true; висячие ссылки и указатели;
	std::future<int> result = std::async([]() {return 43; });
	std::cout << result.get() << std::endl; //ждем кофе и блокируемся на этом wait - как и get можно вызвать 1 раз (либо то либо то), valid
	//void - wait (нам достаточно просто завершения функции)
	//async - как синхронно, так и асинхронно (на усмотрение среды исполнения) - если too much, то ассинк будет исполняться синхронно  (оптимизация)
	//std::launch::async([]....); //создание отдельного потока (навязали как бы асинхрон)
	//std::deferred::async....;// выполнение синхронно - по запросу от гета 
	std::packaged_task<int()>task([]() {return 42; }); //упаковали задачу задача вида функций, которые не принимают аргументов и возвращают инт
		std::future<int>result = task.get_future();
		std::thread(std::move(task)).detach();
	
	system("pause");
	return EXIT_SUCCESS;
}