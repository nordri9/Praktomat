#include "gnuplot_airplane.h"
#include <stdio.h>
#include <math.h>

int generate_plot()
{
  // Open a pipe to gnuplot
  FILE *gnuplotPipe = popen("gnuplot -persistent", "w");

  // If gnuplot is not found or cannot be opened
  if (!gnuplotPipe)
  {
    printf("Error opening gnuplot pipe.\n");
    return -1;
  }
  fprintf(gnuplotPipe, "f1(x) = (x >= 0 && x < 10) ? 1-exp(-x) : NaN\n");
  fprintf(gnuplotPipe, "f2(x) = (x >= 10 && x < 18) ? 20-(x-14)**2 : NaN\n");
  fprintf(gnuplotPipe, "f3(x) = (x >= 18 && x < 23) ? 1-exp(-30+x) : NaN\n");
  fprintf(gnuplotPipe, "f4(x) = (x >= 23 && x < 25) ? 2*x-45 : NaN\n");
  fprintf(gnuplotPipe, "f5(x) = (x >= 25 && x < 27) ? 5 : NaN\n");
  fprintf(gnuplotPipe, "f6(xhhh) = (x >= 27 && x < 28) ? -4.2*x+118.4 : NaN\n");
  fprintf(gnuplotPipe, "f7(x) = (x >= 28 && x < 30) ? 1-exp(-30+x) : NaN\n");

  // Plot the functions
  fprintf(gnuplotPipe, "set title 'Airplane'\n");
  fprintf(gnuplotPipe, "set xlabel 'x'\n");
  fprintf(gnuplotPipe, "set ylabel 'y'\n");
  fprintf(gnuplotPipe, "set xrange [0:30]\n");
  fprintf(gnuplotPipe, "plot f1(x) title 'f1', f2(x) title 'f2', f3(x) title 'f3', f4(x) title 'f4', f5(x) title 'f5', f6(x) title 'f6', f7(x) title 'f7'\n");

  pclose(gnuplotPipe);

  return 0;
}
