#include "fms.h"

extern FMS fms;

int main()
{
    Generate_Time_Table(&fms);
    Generate_Duration_Table(&fms);
    Generate_Distance_Table(&fms);
    return 0;
}
