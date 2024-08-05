#ifndef option_h
#define option_h
#include "grid.h"
#include <cmath>
class Option
{
public:
virtual double Payoff(double S)=0;
virtual double f(grid G, int j)=0;
virtual double g(grid G, int j)=0;
double HedgeX;
double HedgeMM;
};
class EurOption: public virtual Option
{
public:
double PriceEU(grid G);
};
class AMOption: public virtual Option
{
public:
double PriceAM(grid G);
};
class Call: public EurOption , public AMOption
{
private:
double K;
double Payoff(double S){if(S>K){ return S-K;} return 0.;}
double g(grid G, int j){return G.S(G.Getimax())
- K*exp(-G.Getr()*(G.GetT() - G.t(j)));}
double f(grid G, int j){return 0.;}
public:
Call(double K_){K=K_;}
};
class Put: public EurOption, public AMOption
{
private:
double K;
double Payoff(double S){if(K>S){ return K-S;} return 0.;}
double g(grid G, int j){return 0.;}
double f(grid G, int j){return K*exp(-G.Getr()*(G.GetT() - G.t(j)));}
public:
Put(double K_){K=K_;}
};
#endif