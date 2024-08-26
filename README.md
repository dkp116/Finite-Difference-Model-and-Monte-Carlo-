# Asian Option Pricing Simulator Using Monte Carlo and American Vanilla Option Pricing Using Finite Difference

This project implements an option pricing simulator using various financial models, including the Black-Scholes model and Monte Carlo simulations. It supports pricing Asian options and European options, with methods to compute prices using direct Monte Carlo simulations, variance reduction techniques, and the Black-Scholes analytical formulas.

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
- [Contributing](#contributing)
- [License](#license)

## Installation

To use this project, you need to have a C++ compiler installed on your machine. The project uses standard libraries and requires no additional dependencies. To set up the project:

1. Clone the repository:
   ```bash
   git clone https://github.com/dkp116/Finite-Difference-Model-and-Monte-Carlo-.git


## Usage

For Pricing Asian Options in the main.cpp file initialise the BSM Mode with 
```cpp
  double S0=100.0, r=0.08, sigma= 0.3;
     BSModel Model(S0,r,sigma);                   //Constructor for our Model 
     double T =1.0/12.0;
     double K=102.0;
int m=1000;
   AsianPut Option(T,K,m);
   AsianPut Option1(T,K,m);
   AsianPutCon  CVOption(T,K,m);
   long N=1000;


