#ifndef BSModel01_h
#define BSModel01_h

using namespace std;
#include<vector>

typedef vector<double> SamplePath;  // double vector when SamplePath is called

class BSModel
{
   public:
      double S0, r, sigma;
      BSModel(double S0_, double r_, double sigma_) //Constructer
         {S0 = S0_; r = r_; sigma = sigma_;
                            srand(time(NULL));}
      void GenerateSamplePath(double T,int m,SamplePath& S);  
};

#endif
