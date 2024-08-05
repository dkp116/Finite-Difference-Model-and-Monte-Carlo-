#ifndef AsianCon_h
#define AsianCon_h

#include "MCOption.h"

class AsianCon : public virtual PathDepOption // This is our control variate 
{
public:
    double K;
    double Z;
    double EstimationZ(BSModel Model);
    double CalcSig(BSModel Model) { return Model.sigma / (sqrt(3.0)); }
    double CalcS(BSModel Model) { return Model.S0 * exp(-0.5 * Model.r * T - ((Model.sigma * Model.sigma * T) / 12.0)); }
    double dplus(double z, BSModel Model);
    double dminus(double z, BSModel Model);
    double Gauss();
    double cumulativeNormal(double x);
};

class AsianCallCon : public AsianCon
{
public:
    AsianCallCon(double T_, double K_, int m_)
    {
        T = T_;
        K = K_;
        m = m_;
    }
    double Payoff(SamplePath& S, BSModel Model);
    double PriceByBSFormula(BSModel Model);
};

class AsianPutCon : public AsianCon
{
public:
    AsianPutCon(double T_, double K_, int m_)
    {
        T = T_;
        K = K_;
        m = m_;
    }
    double Payoff(SamplePath& S, BSModel Model);
    double PriceByBSFormula(BSModel Model);
};

#endif





