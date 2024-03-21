#include <stdio.h>
#include <math.h>
#include "gnuplot.h"

int generate_plot();

int generate_plot()
{
    Gnuplotopen("Airplane", "airplane");

    // Generate sine wave points and plot them
    float point_spacing = 1;
    float x, y;
    for (int i = 0; i < 2; ++i)
    {
        char mirror = 1;
        if (i != 1)
        {
            mirror = 1;
        }
        else
        {
            mirror = -1;
        }

        for (x = 0; x <= 10; x += point_spacing)
        {
            y = mirror * (1 - exp(-x));
            GnuPlotValue(x, y);
        }

        for (x = 10; x <= 18; x += point_spacing)
        {
            y = mirror * (20 - pow(x - 14, 2));
            GnuPlotValue(x, y);
        }
        for (x = 18; x <= 23; x += point_spacing)
        {
            y = mirror * (1 - exp(-30 + x));
            GnuPlotValue(x, y);
        }
        for (x = 23; x <= 25; x += point_spacing)
        {
            y = mirror * (2 * x - 45);
            GnuPlotValue(x, y);
        }
        for (x = 25; x <= 27; x += point_spacing)
        {
            y = mirror * (5);
            GnuPlotValue(x, y);
        }
        for (x = 27; x <= 28; x += point_spacing)
        {
            y = mirror * (-4.2 * x + 118.4);
            GnuPlotValue(x, y);
        }
        for (x = 28; x <= 30; x += point_spacing)
        {
            y = mirror * (1 - exp(-30 + x));
            GnuPlotValue(x, y);
        }
    }

    GnuPlotClose();

    return 0;
}