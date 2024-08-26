# Asian Option Pricing Simulator Using Monte Carlo, American and European Vanilla Option Pricing Using Finite Difference

This project implements an option pricing simulator using various financial models, including the Black-Scholes model, Monte Carlo simulations, and finite difference methods. It supports pricing for Asian options and American and European vanilla options, with different methods to compute prices, such as direct Monte Carlo simulations, variance reduction techniques, and analytical formulas.

## Table of Contents
- [Installation](#installation)
- [Asian Option Pricing](#asian-option-pricing)
- [American Vanilla Option Pricing](#american-vanilla-option-pricing)
- [European Vanilla Option Pricing](#european-vanilla-option-pricing)
- [License](#license)


## Installation

To use this project, you need to have a C++ compiler installed on your machine. The project uses standard libraries and requires no additional dependencies. To set up the project:

1. Clone the repository:
   ```bash
   git clone https://github.com/dkp116/Finite-Difference-Model-and-Monte-Carlo-.git
   ```

2. Navigate into the project directory and compile the source code:
   ```bash
   cd Finite-Difference-Model-and-Monte-Carlo
   make
   ```
3. Run the executable:
   ```bash
   ./Main01
   ```

## Asian Option Pricing

To price Asian options, initialize the Black-Scholes model and the Asian option in main.cpp as follows:
```cpp
double S0 = 100.0, r = 0.08, sigma = 0.3;   // Initial stock price, risk-free rate, and volatility
BSModel Model(S0, r, sigma);                // Construct the Black-Scholes model
double T = 1.0 / 12.0;                      // Time to maturity (in years)
double K = 102.0;                           // Strike price
int m = 1000;                               // Number of time steps
AsianPut Option(T, K, m);                   // Asian put option
AsianPutCon CVOption(T, K, m);              // Control variable to reduce variance in Monte Carlo simulation
long N = 1000;                              // Number of simulations

```
# Pricing Using Monte Carlo Simulation

The Monte Carlo simulation uses a control variable method to reduce the variance of the simulation:

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
The above code calculates the price of Asian options using Monte Carlo simulations with and without control variates. It also computes the hedging positions for the next period.

## American Vanilla Option Pricing 

An explicit finite difference method is used to price American options. An implicit method, which is more stable, could be implemented in the future to improve the pricing algorithm.

```cpp
double S0 = 100.0, r = 0.08, sigma = 0.3;
BSModel Model(S0, r, sigma);                // Construct the Black-Scholes model
double T = 1.0 / 12.0;                      // Time to maturity (in years)
double K = 102.0;                           // Strike price
BSModelCheck stock(S0, r, sigma, T);        // Model checker for Black-Scholes model
grid Grid(r, sigma, T, S0, 200, 0, 2000, 700); // Finite difference grid setup
Call Test(K);
double PriceOption = Test.PriceAM(Grid);    // Pricing using explicit finite difference method
double HedgeXpos = Test.HedgeX;
double HedgeMMpos = Test.HedgeMM;
cout << "Explicit Method Price of Option = " << PriceOption << endl; 
cout << "X position = " << HedgeXpos << endl;
cout << "MM Position = " << HedgeMMpos << endl;


```
In the code above, we initialize the parameters for the American option, set up the finite difference grid, and calculate the option price along with the hedging positions.

## European Vanilla Option Pricing 

To price European options, we use the analytical Black-Scholes formula derived from the Black-Scholes partial differential equation (PDE).

```cpp                       
BSPut BaSPut(T,K);
cout << "European Put from Black-Scholes model: "<< endl;
cout << " price: " << BaSPut.Price(stock) << endl;
cout << " x : " << BaSPut.Getx() << " y: "<< BaSPut.Gety() << endl;

```
The code snippet above demonstrates how to price a European vanilla option using the explicit formula derived from the Black-Scholes PDE.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE.txt) file for more details.




