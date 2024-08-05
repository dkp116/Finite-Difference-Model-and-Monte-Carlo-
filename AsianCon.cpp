#include <cmath>
#include "AsianCon.h"



const double pi=4.0*atan(1.0); //pi
double AsianCon::Gauss()   //Standard Normal dist  Already in BSM.cpp or h
{
double U1 = (rand()+1.0)/(RAND_MAX+1.0);
double U2 = (rand()+1.0)/(RAND_MAX+1.0);
return sqrt(-2.0*log(U1)) * cos(2.0*pi*U2);
}

double AsianCon::cumulativeNormal(double x) {
    return 0.5 * erfc(-x / std::sqrt(2.0));
}

double AsianCon::EstimationZ(BSModel Model) //This gives esitmation of stock price for payoff 
{
   double m = (Model.r - ((Model.sigma * Model.sigma) / 2) ) * 0.5 * T;
   double s = (Model.sigma  * sqrt(T)) / (sqrt(3.0));

   return Model.S0 * exp(m+s*Gauss());
}

double AsianCallCon::Payoff(SamplePath& S, BSModel Model)   
{
  double stockprice = 0;
  for ( int i = 0; i < 1000;i++)
  {stockprice = (i*stockprice + EstimationZ(Model))/(i+1.0);}
  if (stockprice > K){return stockprice - K;}
  else {return 0.0;} 
}

double AsianPutCon::Payoff(SamplePath& S, BSModel Model)  
{
  double stockprice = EstimationZ(Model);
  if (K > stockprice){return K - stockprice;}
  else {return 0.0;} 
}


double AsianCon::dplus(double z, BSModel Model) //check this maybe
{
  double sig =  CalcSig(Model);
    return (log(z/K) + (Model.r + 0.5 * sig * sig) * T) / (sig*sqrt(T));
}
double AsianCon::dminus(double z, BSModel Model)
{
   double sig = CalcSig(Model);
   return (log(z/K) + (Model.r - 0.5 * sig* sig) * T) / (sig*sqrt(T)); 
}
double AsianCallCon::PriceByBSFormula(BSModel Model) //Use formula in BSM 
{
    double SPrice = CalcS(Model);
    return  SPrice * cumulativeNormal(dplus(SPrice,Model)) - K * exp(-Model.r * T) * cumulativeNormal(dminus(SPrice,Model));
}

double AsianPutCon::PriceByBSFormula(BSModel Model) //Use formula in BSM 
{
    double SPrice = CalcS(Model);
    return  -SPrice * cumulativeNormal(-dplus(SPrice,Model)) + K * exp(-Model.r * T) * cumulativeNormal(-dminus(SPrice,Model));

}