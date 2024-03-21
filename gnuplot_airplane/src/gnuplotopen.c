#include <stdio.h>
#include "gnuplot_airplane.h"

FILE *gnu;

void Gnuplotopen(char *title, char *filename)
{
  gnu = popen("gnuplot -persistent", "w");
  if (filename != NULL)
  {
    // Do something with the filename
  }
  else
  {
    fprintf(gnu, "set title \"%s\"; set terminal png; set output \"%s.png\"; plot '-' \n", title, filename);
  }
  fprintf(gnu, "plot '-' \n");
}

void GnuPlotClose(void)
{
  pclose(gnu);
}

void GnuPlotValue(float v1, float v2)
{
  fprintf(gnu, "%0.2f %0.2f \n", v1, v2);
}
