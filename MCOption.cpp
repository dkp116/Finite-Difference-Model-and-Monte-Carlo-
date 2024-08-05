// This is the file MCOption.cpp
#include "MCOption.h"
#include "BSModel01.h"
#include "Option.h"
#include <cmath>
#include <iostream>
using namespace std;



void Rescale(SamplePath& S, double x)
{
   int m=S.size();
   for (int j=0; j<m; j++) S[j] = x*S[j];
}

double PathDepOption::PriceByMC(BSModel Model, long N,
                                        double epsilon)
{
   double H=0.0, Hsq=0.0, Heps=0.0;
   SamplePath S(m);
   for(long i=0; i<N; i++)
   {
      Model.GenerateSamplePath(T,m,S);
      H = (i*H + Payoff(S, Model))/(i+1.0);
      Hsq = (i*Hsq + pow(Payoff(S, Model),2.0))/(i+1.0);
      Rescale(S,1.0+epsilon);
      Heps = (i*Heps + Payoff(S, Model))/(i+1.0);
   }
   Price = exp(-Model.r*T)*H;
   PricingError = exp(-Model.r*T)*sqrt(Hsq-H*H)/sqrt(N-1.0);
   delta = exp(- Model.r*T)*(Heps-H)/(Model.S0*epsilon);
   MMposition = Price - delta * Model.S0;  //Here calculated Moneymarket poisiton and the error
   return Price;
}

double PathDepOption::PriceByVarRedMC
       (BSModel Model, long N, PathDepOption& CVOption)
{
   DifferenceOfOptions VarRedOpt(T,m,this,&CVOption);

   Price = VarRedOpt.PriceByMC(Model,N,0.0001)
           + CVOption.PriceByBSFormula(Model);

   PricingError = VarRedOpt.PricingError;

   return Price;
}


double AsianCall::Payoff(SamplePath& S, BSModel Model) // 
{
   double Ave=0.0;
   for (int k=0; k<m; k++) Ave=(k*Ave+S[k])/(k+1.0);
   if (Ave<K) return 0.0;
   return Ave-K;
}


double AsianPut::Payoff(SamplePath& S, BSModel Model)
{
   double Ave=0.0;
   for (int k=0; k<m; k++) Ave=(k*Ave+S[k])/(k+1.0);
   if (Ave<K) return K-Ave;
   return 0.;
}




