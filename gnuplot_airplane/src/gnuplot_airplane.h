#ifndef gnuplot_airplane_H
#define gnuplot_airplane_H

int generate_plot();

/*
 *
 */

void GnuPlotOpen(char *title, char *filename);
/*
 *
 */

void GnuPlotClose(void);
/*
 *
 */

void GnuPlotValue(float v1, float v2);

#endif /* GNUPLOT_H_ */