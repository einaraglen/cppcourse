#pragma once //only include once

const double pi = 3.141592;

class Circle {
  public:
    //circle(double radius_); bruk av liten boktav i constructor
    Circle(double radius_); // FIX
    int get_area() const;
    double get_circumference() const;
  //private double radius; private er ikke åpnet med ":"
  private: //FIX
    double radius; 
//} semikolon
}; // FIX

// ==> Implementasjon av klassen Circle

Circle::Circle(double radius_) : radius(radius) {} // radius_ er er ikke en del av feltene til Circle

//int Circle::get_area() { mangler const keyword
int Circle::get_area() const { // FIX
  return pi * radius * radius;
}

//Circle::get_circumference() const { mangler return type av "double"
double Circle::get_circumference() const { // FIX
  //circumference = 2.0 * pi * radius; her er det bruk av variable som ikke er blitt initialisert
  double circumference = 2.0 * pi * radius; // FIX
  return circumference;
}