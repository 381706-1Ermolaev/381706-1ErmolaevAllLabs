#include <iostream>
#include"Monom.h"

class TPolynomial{
protected:
  TPolynomial* nextP;//Указатель на следующий
  Tmonom* monoms;//Степени
  const int n;//Кол-во мономов
public:
  TPolynomial(int _n, unsigned* _power, double c);
  ~TPolynomial();
  TPolynomial(TPolynomial& monom);
  TPolynomial* GetNext();//Указатель на следующий
  unsigned* GetPower();//Степени
  const int GetN();//Кол-во переменных

  void SetNext(TPolynomial* _next);//Указатель на следующий
  void SetpPower(unsigned* _power);//Степени
  void SetC(double _c);// Коэффициент

  TPolynomial& operator =(TPolynomial& monom);
  TPolynomial operator +(TPolynomial& monom);
  TPolynomial operator -(TPolynomial& monom);
  bool operator ==(TPolynomial& monom);
  bool operator >(TPolynomial& monom);
  bool operator <(TPolynomial& monom);

  friend std::istream& operator >> (std::istream& _s, TPolynomial& Tm);
  friend std::ostream& operator << (std::ostream& _s, TPolynomial& Tm);

};