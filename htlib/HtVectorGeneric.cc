

#define GType int
#define HtVectorGType HtVector_int
#include "HtVectorGeneric.h"
#define GType int
#define HtVectorGType HtVector_int
#include "HtVectorGenericCode.h"


#define GType char
#define HtVectorGType HtVector_char
#include "HtVectorGeneric.h"
#define GType char
#define HtVectorGType HtVector_char
#include "HtVectorGenericCode.h"

#include<stdio.h>

class ZOZO
{
    int a,b,c;
public:
    void show(){printf("ZOZO SHOW:%d %d %d\n",a,b,c);}
    ZOZO()
    {
	a=1;
	b=2;
	c=3;
    }
};
#define HTVECTORGENERIC_NOTCOMPARABLE
#define GType ZOZO
#define HtVectorGType HtVector_ZOZO
#include "HtVectorGeneric.h"
#define HTVECTORGENERIC_NOTCOMPARABLE
#define GType ZOZO
#define HtVectorGType HtVector_ZOZO
#include "HtVectorGenericCode.h"

// just check if it compiles ok
void
test_HtVectorGeneric()
{
    HtVector_int  intv;
    HtVector_char charv;
    HtVector_ZOZO vz;
    ZOZO zz;
    vz.push_back(zz);
    vz.push_back(zz);
    vz.push_back(zz);

    int i;
    for(i=0;i<vz.size();i++)
    {
	vz[i].show();
    }
}
