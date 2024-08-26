# Asian Option Pricing Simulator Using Monte Carlo, American and European Vanilla Option Pricing Using Finite Difference

This project implements an option pricing simulator using various financial models, including the Black-Scholes model and Monte Carlo simulations. It supports pricing Asian options and European options, with methods to compute prices using direct Monte Carlo simulations, variance reduction techniques, and the Black-Scholes analytical formulas.

## Table of Contents
- [Installation](#installation)
- [Asian Option Pricing](#usage)
- [American Vanilla Option Pricing](#usage)
- [European Vanilla Option Pricing](#usage)
- [License](#license)

## Installation

To use this project, you need to have a C++ compiler installed on your machine. The project uses standard libraries and requires no additional dependencies. To set up the project:

1. Clone the repository:
   ```bash
   git clone https://github.com/dkp116/Finite-Difference-Model-and-Monte-Carlo-.git


## Asian Option Pricing

For Pricing Asian Options in the main.cpp file initialise the BSM Model and Asian Option with 
```cpp
double S0=100.0, r=0.08, sigma= 0.3;         // edit for desired starting stock price, risk free rate and volatility
BSModel Model(S0,r,sigma);                   //Constructor for our Model 
double T =1.0/12.0;
double K=102.0;
int m=1000;
AsianPut Option(T,K,m);      
AsianPut Option1(T,K,m);
AsianPutCon  CVOption(T,K,m);                // Control variable to reduce the varience of the Monte Carlo Sim
long N=1000;                                 //How many simulations wanting to conduct

```
The Monte Carlo Simulation used is using a control variable where there is an explicit PDE solution for, this reduces the vareience of the simulation 

```cpp
Option.PriceByMC(Model,N,0.0001);  
   cout << "Price by direct MC = " << Option.Price << endl
        << "MC Error = " << Option.PricingError << endl
        << "X position =  " << Option.delta << " and MM position =  " << Option.MMposition 
        << endl;

   Option.PriceByVarRedMC(Model,N,CVOption);
   cout << "Price using Control = " << Option.Price << endl
        << "Error = " << Option.PricingError << endl;

```
The values for the initial Prices of Asian options are calulated here, using Monte Carlo and Monte Carlo with the control variable. Hedging for the next period is also calulated.

## American Vanilla Option Pricing 

An Explicit Finite Difference Model is used here to price the American Option, an implicit method will be more useful and is something I want to use to improve the pricing algorithm in the future as it is more stable.

```cpp
double S0=100.0, r=0.08, sigma= 0.3;
BSModel Model(S0,r,sigma);                   //Constructor for our Model 
double T =1.0/12.0;
double K=102.0;
BSModelCheck stock(S0, r, sigma, T);         //Constructor for our Model Checker
     
grid Grid( r,  sigma, T, S0, 200, 0, 2000, 700); //grid(double r, double sigma_, double T_, double S0_, double Smax, double Smin, int N_, int imax);
Call Test(K);
double PriceOption = Test.PriceAM(Grid);          //Pricing using Explicit Mathod
double HedgeXpos = Test.HedgeX;
double HedgeMMpos = Test.HedgeMM;
cout <<"Explicit Method Price of Option "<< PriceOption <<  endl; 
cout <<"X position " <<  HedgeXpos << endl;
cout <<"MM Position " << HedgeMMpos << endl;

```

We initailse the same as the Asian Option, but we then have to initlaise the grid for the finite difference Model and the Price, with hedging positions is created.

## European Vanilla Option Pricing 

This is extended from the code above

```cpp                       
BSPut BaSPut(T,K);
cout << "European Put from Black-Scholes model: "<< endl;
cout << " price: " << BaSPut.Price(stock) << endl;
cout << " x : " << BaSPut.Getx() << " y: "<< BaSPut.Gety() << endl;

```
Here the explicit formula derived from BS PDE is impletemented to price the vanilla option.



