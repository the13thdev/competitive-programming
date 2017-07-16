#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

int gcd(int a, int b)
{
    //printf("..a=%d, b%d\n",a,b);
    if(b==0)
    {
        return a;
    }
    else
    {
        return gcd(b,a%b);
    }
}

int main() {
    int i,j,rep_d,num,l,r,gcd_v,denominator,numerator;
    //double num;
    string s;
    while(getline(cin,s))
    {
        if(s.length()>1)
        {
            s= s.substr(0,s.length()-3);
            s=s.substr(2);
            num =atoi(s.c_str());
            numerator=1;
            denominator=1000000000;
            for(j=1;j<=s.length();++j)
            {
                l=(pow(10,j)-1)*pow(10,s.length()-j);
                r=num-(num/(int)(pow(10,j)));
                gcd_v=gcd(l,r);
                //printf("..j=%d num=%d, l=%d,r=%d, gcd=%d\n",j,num,l,r,gcd_v);
                //printf("...r = %d - %d\n",num,(num/(int)(pow(10,j))));
                if((l/gcd_v)<denominator)
                {
                    numerator=r/gcd_v;
                    denominator=l/gcd_v;
                    //printf("..ans updated to %d/%d\n",numerator,denominator);
                }
            }
            /*l=pow(10,s.length()-1);
            l=l*9;
            r=num-(num/10);
            //printf("..nm=%d, l=%d,r=%d\n",num,l,r);
            //solve, simplify r/l
            gcd_v=gcd(l,r);
            //printf("..gcd_v=%d\n",gcd_v);*/
            printf("%d/%d\n",numerator,denominator);
            //next
        }
    }
    return 0;
}