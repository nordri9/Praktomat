#include <stdio.h>
#include <stdlib.h>
#include "fms.h"

int main()
{
    FMS *fms = fms_data_input();

    printf("FMS ID: %d\n", fms->cntAirline);
    // Generate_Time_Table(fms);

    free(fms); // Speicherfreigabe nach der Verwendung
    return 0;
}