#include <iostream>
#include <conio.h>
using namespace std;

class Car
{
	string date;
public:
	Car()
	{
		date = "";
	}
	string aboutCar()
	{
		return date;
	}
	void appendDate(string str)
	{
		date += str;
	}
};

class IConstructor
{
public:
	virtual void createBox() = 0;
	virtual void createRims() = 0;
	virtual void createequipment1() = 0;
	virtual void createequipment2() = 0;
	virtual void createequipment3() = 0;
	virtual void toning() = 0;
	virtual void systemInstall() = 0;
	virtual Car* getCar() = 0;
};

class AudiConstructor : public IConstructor
{
	Car* car;
public:

	AudiConstructor()
	{
		car = new Car;
	}

	~AudiConstructor()
	{
		delete car;
	}

	void createBox() override
	{
		car->appendDate("Created a frame for Audi;\n");
	}

	void createRims() override
	{
		car->appendDate("Wheels installed(Audi);\n");
	}

	void createequipment1() override {
		car->appendDate("Budget kit installed \"Bomzh-paket\" (Audi);\n");

	}

	void createequipment2() override {
		car->appendDate("Normal kit installed(Audi);\n");

	}

	void createequipment3() override {
		car->appendDate("Luxury kit installed \"Polniy farsh\" (Audi);\n");

	}
	void toning() override {
		car->appendDate("Installed tinting(Audi);\n");

	}

	void systemInstall() override
	{
		car->appendDate("Board computer installed(Audi);\n");
	}

	Car* getCar() override
	{
		return car;
	}
};

class NissanConstructor : public IConstructor
{
	Car* car;
public:
	NissanConstructor()
	{
		car = new Car;
	}
	~NissanConstructor()
	{
		delete car;
	}
	void createBox() override
	{
		car->appendDate("Created a frame for Nissan;\n");
	}

	void createRims() override
	{
		car->appendDate("Wheels installed(Nissan);\n");
	}

	void createequipment1() override {
		car->appendDate("Low weight kit installed \"Bomzh-paket\" (Nissan);\n");

	}

	void createequipment2() override {
		car->appendDate("Casual kit installed(Nissan);\n");

	}

	void createequipment3() override {
		car->appendDate("Drag kit installed \"Polniy farsh\" (Nissan);\n");

	}
	void toning() override {
		car->appendDate("Installed tinting(Nissan);\n");

	}

	void systemInstall() override
	{
		car->appendDate("Board computer installed(Nissan);\n");
	}

	Car* getCar() override
	{
		return car;
	}
};


class Director
{
	IConstructor* constructor;
public:
	Director(IConstructor* constr) : constructor(constr) {};

	void setConstructor(IConstructor* constr)
	{
		constructor = constr;
	}
	Car* Car1()
	{
		constructor->createBox();
		constructor->createRims();
		constructor->createequipment1();
		constructor->systemInstall();
		return constructor->getCar();
	}
	Car* Car2()
	{
		constructor->createBox();
		constructor->createRims();
		constructor->createequipment2();
		constructor->systemInstall();
		return constructor->getCar();
	}
	Car* Car3()
	{
		constructor->createBox();
		constructor->createRims();
		constructor->createequipment3();
		constructor->systemInstall();
		return constructor->getCar();
	}

	Car* Car1t()
	{
		constructor->createBox();
		constructor->createRims();
		constructor->createequipment1();
		constructor->toning();
		constructor->systemInstall();
		return constructor->getCar();
	}
	Car* Car2t()
	{
		constructor->createBox();
		constructor->createRims();
		constructor->createequipment2();
		constructor->toning();
		constructor->systemInstall();
		return constructor->getCar();
	}
	Car* Car3t()
	{
		constructor->createBox();
		constructor->createRims();
		constructor->createequipment3();
		constructor->toning();
		constructor->systemInstall();
		return constructor->getCar();
	}
	Car* Car1_no_rims()
	{
		constructor->createBox();
		constructor->createequipment1();
		constructor->systemInstall();
		return constructor->getCar();
	}
	Car* Car1_no_system()
	{
		constructor->createBox();
		constructor->createRims();
		constructor->createequipment1();
		return constructor->getCar();
	}
	Car* Frame()
	{
		constructor->createBox();
		return constructor->getCar();
	}

};
int main()
{
	IConstructor* audiConstructor = new AudiConstructor();
	IConstructor* nissanConstructor = new NissanConstructor();
	char ch1, ch2;
	do {
		system("cls");
		cout << "Selest option:\n\n";
		cout << "Audi\n\n1 - Budget equipment\n2 - Normal equipment\n3 - Luxury equipment\n4 - Budget equipment with toning\n5 - Normal equipment with toning\n6 - Luxury equipment with toning\n7 - Without rims\n8 - Without system\n9 - Only frame\n";
		ch1 = _getch();
	} while (ch1 != '1' && ch1 != '2' && ch1 != '3' && ch1 != '4' && ch1 != '5' && ch1 != '6' && ch1 != '7' && ch1 != '8' && ch1 != '9');

	Director director(audiConstructor);
	if (ch1 == '1') {
		system("cls");
		Car* audi = director.Car1();
		cout << audi->aboutCar() << endl;

	}
	else if (ch1 == '2') {
		system("cls");
		Car* audi = director.Car2();
		cout << audi->aboutCar() << endl;

	}
	else if (ch1 == '3') {
		system("cls");
		Car* audi = director.Car3();
		cout << audi->aboutCar() << endl;

	}
	else if (ch1 == '4') {
		system("cls");
		Car* audi = director.Car1t();
		cout << audi->aboutCar() << endl;

	}
	else if (ch1 == '5') {
		system("cls");
		Car* audi = director.Car2t();
		cout << audi->aboutCar() << endl;

	}
	else if (ch1 == '6') {
		system("cls");
		Car* audi = director.Car3t();
		cout << audi->aboutCar() << endl;

	}
	else if (ch1 == '7') {
		system("cls");
		Car* audi = director.Car1_no_rims();
		cout << audi->aboutCar() << endl;

	}
	else if (ch1 == '8') {
		system("cls");
		Car* audi = director.Car1_no_system();
		cout << audi->aboutCar() << endl;

	}
	else if (ch1 == '9') {
		system("cls");
		Car* audi = director.Frame();
		cout << audi->aboutCar() << endl;
	}
	system("pause");
	system("cls");
	director.setConstructor(nissanConstructor);
	do {
		system("cls");
		cout << "Selest option:\n\n";
		cout << "Nissan\n\n1 - Budget equipment\n2 - Normal equipment\n3 - Luxury equipment\n4 - Budget equipment with toning\n5 - Normal equipment with toning\n6 - Luxury equipment with toning\n7 - Without rims\n8 - Without system\n9 - Only frame\n";
		ch2 = _getch();
	} while (ch2 != '1' && ch2 != '2' && ch2 != '3' && ch2 != '4' && ch2 != '5' && ch2 != '6' && ch2 != '7' && ch2 != '8' && ch2 != '9');


	if (ch2 == '1') {
		system("cls");
		Car* nissan = director.Car1();
		cout << nissan->aboutCar() << endl;

	}
	else if (ch2 == '2') {
		system("cls");
		Car* nissan = director.Car2();
		cout << nissan->aboutCar() << endl;

	}
	else if (ch2 == '3') {
		system("cls");
		Car* nissan = director.Car3();
		cout << nissan->aboutCar() << endl;

	}
	else if (ch2 == '4') {
		system("cls");
		Car* nissan = director.Car1t();
		cout << nissan->aboutCar() << endl;

	}
	else if (ch2 == '5') {
		system("cls");
		Car* nissan = director.Car2t();
		cout << nissan->aboutCar() << endl;

	}
	else if (ch2 == '6') {
		system("cls");
		Car* nissan = director.Car3t();
		cout << nissan->aboutCar() << endl;

	}
	else if (ch2 == '7') {
		system("cls");
		Car* nissan = director.Car1_no_rims();
		cout << nissan->aboutCar() << endl;

	}
	else if (ch2 == '8') {
		system("cls");
		Car* nissan = director.Car1_no_system();
		cout << nissan->aboutCar() << endl;

	}
	else if (ch2 == '9') {
		system("cls");
		Car* nissan = director.Frame();
		cout << nissan->aboutCar() << endl;
	}
}