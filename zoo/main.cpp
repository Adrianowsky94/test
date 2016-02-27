#include <iostream>
#include <vector>

using namespace std;

class Zwierze
{
protected:
	int masa;
public:
	virtual void daj_glos()=0;
	void ustaw_mase (int masa) { this -> masa = masa; }
	Zwierze () {
		ustaw_mase(0);
	}
	void test() { cout << "Test"; }
};

class Krowa : public Zwierze {
public:
	void daj_glos() { cout << "Muu!\n"; }
	void ustaw_mase (int masa){
		if (masa < 0 || masa > 1000) throw -1;
		Zwierze::ustaw_mase(masa);
	}
	Krowa(){};
};

class Koza : public Zwierze {
public:
	void daj_glos() { cout << "Mee!\n"; }
	void ustaw_mase (int masa){
		if (masa < 0 || masa > 1000) throw -1;
		Zwierze::ustaw_mase(masa);
	}
	Koza(){};
};

class Zoo {
protected:
	vector <Zwierze*> vk;
};

int main (){

	vector <Zwierze*> vz;
	vz.push_back(new Krowa());
	vz.push_back(new Koza());
	vz.push_back(new Krowa());
	vz.push_back(new Koza());

	for (int i=0; i < vz.size(); ++i)
		vz.at(i) -> daj_glos();
	return 0;
};
