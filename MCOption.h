#ifndef MCOption_h
#define MCOption_h
#include "BSModel01.h"
#include <cstdlib>
#include <ctime>

#include "BSModel01.h"

class PathDepOption
{
   public:
      double T, Price, PricingError, delta, MMposition;
      int m;
      virtual double Payoff(SamplePath& S, BSModel Model)=0;
      double PriceByMC(BSModel Model, long N,
                               double epsilon);
       double PriceByVarRedMC
             (BSModel Model, long N, PathDepOption& CVOption);
      virtual double PriceByBSFormula
                     (BSModel Model){return 0.0;}
};



class DifferenceOfOptions: public PathDepOption
{
   public:
      PathDepOption* Ptr1;
      PathDepOption* Ptr2;
      DifferenceOfOptions(double T_, int m_,
                          PathDepOption* Ptr1_,
                          PathDepOption* Ptr2_)
         {T=T_; m=m_; Ptr1=Ptr1_; Ptr2=Ptr2_;}
      double Payoff(SamplePath& S, BSModel Model)
         {return Ptr1->Payoff(S, Model)-Ptr2->Payoff(S, Model);}  //Check this formula
};


class AsianCall: public PathDepOption //Payoff needs changing for the option
{
   public:
      double K;
      AsianCall
            (double T_, double K_, int m_)
            {T=T_; K=K_; m=m_;}
      double Payoff(SamplePath& S, BSModel Model);
};

class AsianPut: public PathDepOption
{
     public:
      double K;
      AsianPut
            (double T_, double K_, int m_)
            {T=T_; K=K_; m=m_;}
      double Payoff(SamplePath& S, BSModel Model);
};







// class MCOption
// {
// private:
// double T, Precision;
// long N;
// public:
// virtual double Payoff(BSModel stock)=0;
// virtual double ControlVariate(BSModel stock)=0; //where is the vector for the simulation?
// long GetN(){ return N;}
// double GetT(){ return T;}
// double GetPrecision(){return Precision;}
// void SetT(double T_){T=T_;}
// void SetN(long N_){N=N_;} //Maybe include constructor to set N - steps to begin with
// void SetPrecision(double P){Precision = P;}
// };

// class MCAsOption: public MCOption
// {
// private:
// int NofSteps;
// public:
// double Price(BSModel model);
// int GetNofSteps(){return NofSteps;}
// void SetNofSteps(int M){NofSteps = M;}

// };

// class MCCall: public MCAsOption
// {
// private:
// double X;
// public:
// double Payoff(BSModel stock);
// double ControlVariate(BSModel stock){return 0.;}
// MCCall(double T, long N, int M, double X_)
// { SetT(T); SetN(N); SetNofSteps(M); X=X_; srand((unsigned)time(0));}
// };

// class MCPut: public MCAsOption
// {
// private:
// double X;
// public:
// double Payoff(BSModel stock);
// double ControlVariate(BSModel stock){return 0.;}
// MCPut(double T, long N, int M, double X_)
// { SetT(T); SetN(N); SetNofSteps(M); X=X_; srand((unsigned)time(0));}
// };

#endif