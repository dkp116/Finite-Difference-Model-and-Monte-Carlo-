#include <iostream>
#include "Option.h"
#include "AsianCon.h"
#include "MCOption.h"
#include "BSModel01.h"
#include "BSModel.h"
#include "BSOption.h"

using namespace std;

int main()
{
     double S0=100.0, r=0.08, sigma= 0.3;
     BSModel Model(S0,r,sigma);                   //Constructor for our Model 
     double T =1.0/12.0;
     double K=102.0;
     BSModelCheck stock(S0, r, sigma, T);         //Constructor for our Model Checker
     
   //   grid Grid( r,  sigma, T, S0, 200, 0, 2000, 700); //grid(double r, double sigma_, double T_, double S0_, double Smax, double Smin, int N_, int imax);
   //   Call Test(K);
   //   double PriceOption = Test.PriceAM(Grid);          //Pricing using Explicit Mathod
   //   double HedgeXpos = Test.HedgeX;
   //   double HedgeMMpos = Test.HedgeMM;
   //   cout <<"Explicit Method Price of Option "<< PriceOption <<  endl; 
   //   cout <<"X position " <<  HedgeXpos << endl;
   //   cout <<"MM Position " << HedgeMMpos << endl;

   //   BSCall BaSCall(T,K);                         //Pricing using formula 
   //   BSPut BaSPut(T,K);
   //   cout << "European Put from Black-Scholes model: "<< endl;
   //   cout << " price: " << BaSPut.Price(stock) << endl;
   //   cout << " x : " << BaSPut.Getx() << " y: "<< BaSPut.Gety() << endl;

   //   cout << "European Call from Black-Scholes model: "<< endl;            //This is the pricing of the call Option
   //   cout << " price: " << BaSCall.Price(stock) << endl;
   //   cout << " x : " << BaSCall.Getx() << " y: "
   //   << BaSCall.Gety() << endl;

   int m=1000;
   AsianPut Option(T,K,m);
   AsianPutCon  CVOption(T,K,m);
   long N=10000;

   Option.PriceByMC(Model,N,0.0001);  
   cout << "Price by direct MC = " << Option.Price << endl
        << "MC Error = " << Option.PricingError << endl
        << "X position =  " << Option.delta << " and MM position =  " << Option.MMposition 
        << endl;

   Option.PriceByVarRedMC(Model,N,CVOption);
   cout << "Price using Control = " << Option.Price << endl
        << "Error = " << Option.PricingError << endl; 


   return 0; 
}


