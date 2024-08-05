//This is the file BSModel.h
#ifndef BSModel_h
#define BSModel_h
class BSModelCheck
{
private:
double r, sigma, T, S0;
public:
double Getr(){return r;}
double GetS0(){return S0;}
double GetT(){return T;}
double Getsigma(){return sigma;}
BSModelCheck(double S0_, double r_, double sigma_, double T_);
double S(double St, double dt);
};
#endif