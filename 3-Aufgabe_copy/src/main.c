#include <stdio.h>
#include "fms.h"

int main(void)
{
    extern FMS FMS1; // initialising pfms
    FMS *pFMS = &FMS1;
    Generate_Time_Table(pFMS);
    //   Generate_Duration_Table( pFMS);
    //  Generate_Distance_Table( pFMS);
}