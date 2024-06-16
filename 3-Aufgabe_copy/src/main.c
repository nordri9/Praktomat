#include <stdio.h>
#include <stdlib.h>
#include "fms.h"


extern FMS fms;

int main() {
    Generate_Time_Table(&fms);
    return 0;
}