// d3 28.06 fasade(washing machine).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Реализовать паттерн "Фасад". Предметная область - использование стиральной машины


#include <iostream>

using namespace std;

class Engine {
public:
    void PowerOn() {
        cout << "Power ON" << endl;
    }
    void PowerOf() {
        cout << "Power OF" << endl;
    }
};
class WaterPomp {
public:
    void AddWater() {
        cout << "Adding water " << endl;
    }
    void DrainingWater() {
        cout << "Draining water" << endl;
    }
};

class WaterHeater {
public:
    void HeatingWaterStart() {
        cout << "Heating water start" << endl;
    }
    void HeatingWaterStop() {
        cout << "Heating water stop " << endl;
    }
};

class DetergentContainer {
public:
    void LaundryDetergent() {
        cout << "Adding laundry detergent" << endl;
    }
    void  FabricSoftener() {
        cout << "adding fabric softener" << endl;
    }
};

class Basket {
public:
    void StartRotation(){
        cout << "Start rotation backet" << endl;
    }
    void StopRotation() {
        cout << "Stop rotation backet" << endl;
    }
};

class WashingMashineFasade {
    Engine _eng;
    WaterPomp _wp;
    WaterHeater _wh;
    DetergentContainer _dc;
    Basket _bskt;
public:
    WashingMashineFasade(Engine eng, WaterPomp wp, WaterHeater wh, DetergentContainer dc, Basket bskt) {
        _eng = eng;
        _wp = wp;
        _wh = wh;
        _dc = dc;
        _bskt = bskt;
    }
    void Start() {
        _eng.PowerOn();
        cout << " Start Washing!!" << endl;
        _wp.AddWater();
        _wh.HeatingWaterStart();
        _wh.HeatingWaterStop();
        _dc.LaundryDetergent();
        _bskt.StartRotation();
        _bskt.StopRotation();
        _wp.DrainingWater();
        _wp.AddWater();
        _dc.FabricSoftener();
        _bskt.StartRotation();
        _bskt.StopRotation();
        _wp.DrainingWater();
        _bskt.StartRotation();
        _bskt.StopRotation();
        _wp.DrainingWater();
    }
    void Stop() {
        cout << " Stop Washing!!" << endl;
        _eng.PowerOf();
    }

};

class WashingProgram {
public :
    void Washing(WashingMashineFasade fasade) {
        fasade.Start();
        fasade.Stop();
    }
};

int main()
{
    Engine eng;
    WaterPomp wpp;
    WaterHeater wht;
    DetergentContainer detcon;
    Basket basket;

    WashingMashineFasade wmf(eng, wpp, wht, detcon, basket);
    WashingProgram program;
    program.Washing(wmf);

    return 0;
}

