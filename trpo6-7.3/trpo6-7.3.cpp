#include <iostream>

using namespace std;

class Shoes {
public:
    virtual void releaseShoes() = 0;
};

class Snikers : public Shoes {
public:
    void releaseShoes() override {
        cout << "Кроссовки" << endl;
    }
};


class ClassicShoes : public Shoes {
public:
    void releaseShoes() override {
        cout << "Туфли" << endl;
    }
};

class Suit {
public:
    virtual void releaseSuit(Shoes* shoes) = 0;
};

class SportSuit : public Suit{
public:
    void releaseSuit(Shoes* shoes) override {
        cout << "Спортивный костюм очень хорошо подходит для повседневного использования, а на ногах удобные: ";
        shoes->releaseShoes();
    }
};

class Smoking : public Suit {
public:
    void releaseSuit(Shoes* shoes) override {
        cout << "Смокинг выглядит великолепно, к нему отлично подходят: ";
        shoes->releaseShoes();
    }
};

class Costume {//абстрактная фабрика
public:
    virtual Shoes* createShoes() = 0;
    virtual Suit* createSuit() = 0;
};

class SportCostume : public Costume {
public:
    Shoes* createShoes() override {
        return new Snikers();
    }
    Suit* createSuit() override {
        return new SportSuit(); 
    }
};


class ClassicCostume : public Costume {
public:
    Shoes* createShoes() override {
        return new ClassicShoes();
    }
    Suit* createSuit()override {
        return new Smoking();
    }
};



int main()
{
    setlocale(LC_ALL, "ru");

    Costume* sport_costume = new SportCostume();

    Shoes* sport_shoes = sport_costume->createShoes();
    Suit* sport_suit = sport_costume->createSuit();

    sport_suit->releaseSuit(sport_shoes);

    Costume* classic_costume = new ClassicCostume();

    Shoes* classic_shoes = classic_costume->createShoes();
    Suit* classic_suit = classic_costume->createSuit();

    classic_suit->releaseSuit(classic_shoes);
    
}

