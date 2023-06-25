#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct PartFuncion
{
    PartFuncion(char sign,double d)
    {
        this->sign=sign;
        this->d=d;
    }
    double Apply(double quality)const
    {
        //cout<<sign<<d<<'\n';
        if(sign=='+')
        {
            return quality+d;
        }
        if(sign=='-')
        {
            return quality-d;
        }
         if(sign=='*')
        {
            return quality*d;
        }
        if(sign=='/')
        {
            return quality/d;
        }
        return quality;
    }
    void Invert()
    {
        if(sign=='+')
        {
            sign='-';
        }
        else
        {
            if(sign=='-')
            {
                sign='+';
            }
        }
        if(sign=='*')
        {
            sign='/';
        }
        else
        {
            if(sign=='/')
            {
                sign='*';
            }
        }
    }
    double d;
    char sign;
};
struct Function
{
    void AddPart(char sign,double d)
    {
        partFunction.push_back({sign,d});
    }
    void Invert()
    {
        for(auto &part:partFunction)
        {
            part.Invert();
        }
        reverse(partFunction.begin(),partFunction.end());

    }
    double Apply(double quality)const
    {
        //cout<<quality<<'\n';
        for(auto const part:partFunction)
        {
            quality=part.Apply(quality);
        }
       // cout<<quality<<"\n\n";
        return quality;
    }
    vector<PartFuncion> partFunction;
};
/*
struct Image {
  double quality;
  double freshness;
  double rating;
};

struct Params {
  double a;
  double b;
  double c;
};

Function MakeWeightFunction(const Params& params,
                            const Image& image) {
  Function function;
  function.AddPart('*', params.a);
  function.AddPart('-', image.freshness * params.b);
  function.AddPart('+', image.rating * params.c);
  return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
  Function function = MakeWeightFunction(params, image);
  return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
  Function function = MakeWeightFunction(params, image);
  function.Invert();
  return function.Apply(weight);
}

int main() {
  Image image = {10, 2, 6};
  Params params = {4, 2, 6};
  cout << ComputeImageWeight(params, image) << endl;
  cout << ComputeQualityByWeight(params, image, 52) << endl;
  return 0;
}*/
