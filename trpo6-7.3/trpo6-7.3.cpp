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

class Bag {
public:
    virtual void releaseBag() = 0;
};

class sportBag : public Bag {
public:
    void releaseBag() override{
        cout << "Спортивная сумка, ";
    }
};

class classicBag : public Bag {
public:
    void releaseBag() override {
        cout << "Классическая сумка, ";
    }
};

class Suit {
public:
    virtual void releaseSuit(Bag* bag, Shoes* shoes) = 0;
};

class SportSuit : public Suit{
public: //хаха хахо
        bag->releaseBag();
        shoes->releaseShoes();
    virtual Shoes* createShoes() = 0;
    virtual Suit* createSuit() = 0;
    virtual Bag* createBag() = 0;
};

class SportCostume : public Costume {
public:
    Shoes* createShoes() override {
        return new Snikers();
    }
    Suit* createSuit() override {
        return new SportSuit(); 
    }
    Bag* createBag() override {
        return new sportBag();
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
    Bag* createBag() override {
        return new classicBag();
    }
};

class DailyCostume : public Costume {
public:
    Shoes* createShoes() override {
        return new ClassicShoes();
    }
    Suit* createSuit() override {
        return new SportSuit();
    }
    Bag* createBag()override {
        return new classicBag();
    }
};


int main()
{
    setlocale(LC_ALL, "ru");

    Costume* sport_costume = new SportCostume();

    Shoes* sport_shoes = sport_costume->createShoes();
    Suit* sport_suit = sport_costume->createSuit();
    Bag* sport_bag = sport_costume->createBag();

    sport_suit->releaseSuit(sport_bag,sport_shoes);

    Costume* classic_costume = new ClassicCostume();

    Shoes* classic_shoes = classic_costume->createShoes();
    Suit* classic_suit = classic_costume->createSuit();
    Bag* classic_bag = classic_costume->createBag();

    classic_suit->releaseSuit(classic_bag,classic_shoes);

    Costume* daily_costume = new DailyCostume();

    Shoes* daily_shoes = daily_costume->createShoes();
    Suit* daily_suit = daily_costume->createSuit();
    Bag* daily_bag = daily_costume->createBag();

    daily_suit->releaseSuit(daily_bag, daily_shoes);
    
}

