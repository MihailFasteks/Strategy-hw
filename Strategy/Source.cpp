#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

	/*
	Паттерн Стратегия позволяет вынести алгоритм поведения объекта за его пределы.
	Для решения заданной проблемы может быть представлено несколько алгоритмов.
	Инкапсулирование всех алгоритмов внутри класса-владельца грозит нагромождением кода
	и отсутствием возможности расширения работы класса,  а именно добавления дополнительных алгоритмов.
	А при данной структуре клиент может выбирать, какой алгоритм поведения объекта ему необходим.
	*/

class TransportStrategy abstract
{
public:
	virtual void Transport() abstract;
};

class BicycleStrategy: public TransportStrategy
{
public:
	void Transport() override
	{
		cout << "Your transport is BICYCLE! The level cost of road is 1 , level duration of trip is 3" << endl;
	}
};

class BusStrategy : public TransportStrategy
{
public:
	void Transport() override
	{
		cout << "Your transport is BUS! The level cost of road is 2 , level duration of trip is 2" << endl;
	}
};

class TaxiStrategy : public TransportStrategy
{
public:
	void Transport() override
	{
		cout << "Your transport is TAXI! The level cost of road is 3 , level duration of trip is 1" << endl;
	}
};

class Transport
{
	
	TransportStrategy* transportStrategy;

public:
	void SetTransportStrategy(TransportStrategy* transportStrategy)
	{
		this->transportStrategy = transportStrategy;
	}
	void Print() {
		this->transportStrategy->Transport();
	}
	
};

int main()
{
	Transport tr;

	BicycleStrategy bicyclestrategy;
	tr.SetTransportStrategy(&bicyclestrategy);
	tr.Print();

	

	BusStrategy busstrategy;
	tr.SetTransportStrategy(&busstrategy);
	tr.Print();

	

	TaxiStrategy taxistrategy;
	tr.SetTransportStrategy(&taxistrategy);
	tr.Print();

	system("pause");
	return 0;
}
	
