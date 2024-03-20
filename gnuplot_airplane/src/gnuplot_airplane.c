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

  // Generate and plot sine wave data
  fprintf(gnuplotPipe, "set title 'Sine Wave'\n");
  fprintf(gnuplotPipe, "set xlabel 'x'\n");
  fprintf(gnuplotPipe, "set ylabel 'y'\n");
  fprintf(gnuplotPipe, "plot sin(x) title 'sin(x)'\n");

  // Close the pipe
  pclose(gnuplotPipe);

  return 0;
}
