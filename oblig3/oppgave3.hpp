#pragma once //only include once

#include <string>
using namespace std;

//tax i første utskrift (229.688 / 2.5) - 73.5 = 18.3752
const double tax = 18.3752;
//tax i andre utskrift (248.75 / 2.5) - 79.6 = 19.9
//const double tax = 19.9;

//Template
class Commodity  {
  public:
    Commodity(string name_, int id_, double price_); // FIX
    const string &get_name() const;
    int get_id() const;
    double get_price() const;
    double get_price(double quantity) const;
    void set_price(double price_);
    double get_price_with_sales_tax(double quantity) const;
  private:
    string name; 
    int id;
    double price;
};

// ==> Implementasjon av klassen // Commodity

//Constructor
Commodity::Commodity(string name_, int id_, double price_) : name(name_), id(id_), price(price_) {} 

//GETTERS
const string &Commodity::get_name() const { return name; }

int Commodity::get_id() const { return id; }

double Commodity::get_price() const { return price; }

double Commodity::get_price(double quantity) const { return price * quantity; }

double Commodity::get_price_with_sales_tax(double quantity) const { return (price + tax) * quantity; }

//SETTERS
void Commodity::set_price(double price_) { price = price_; }
