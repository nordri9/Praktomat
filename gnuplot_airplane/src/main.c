#include <stdio.h>   // Standard input-output library
#include <math.h>    // Math library for mathematical functions
#include "gnuplot.h" // Custom header file for GNU plot functions

// Function prototype declaration
int generate_plot();

// Main function
int main()
{
  generate_plot(); // Call the function to generate the plot
  return 0;        // Return 0 to indicate successful execution
}

// Function to generate the plot
int generate_plot()
{
  // Open a GNU plot window with title "Airplane" and file name "airplane"
  GnuPlotOpen("Airplane", "airplane");

  float x, y; // Variables to store x and y coordinates

  // Loop for plotting the functions
  for (int i = 0; i < 2; ++i)
  {
    char mirror = 1; // Variable to handle mirroring effect

    // Set mirror variable based on the value of i
    if (i != 1)
    {
      mirror = 1; // No mirroring
    }
    else
    {
      mirror = -1; // Mirror along y-axis
    }

    // Plot first segment of the curve
    for (x = 0; x <= 10; x += 0.1)
    {
      y = mirror * (1 - exp(-x)); // Function definition
      GnuPlotValue(x, y);         // Plot the point (x, y)
    }

    // Plot second segment of the curve
    for (x = 10; x <= 18; x += 0.1)
    {
      y = mirror * (20 - pow(x - 14, 2)); // Function definition
      GnuPlotValue(x, y);                 // Plot the point (x, y)
    }

    // Plot third segment of the curve
    for (x = 18; x <= 23; x += 0.1)
    {
      y = mirror * (1 - exp(-30 + x)); // Function definition
      GnuPlotValue(x, y);              // Plot the point (x, y)
    }

    // Plot fourth segment of the curve
    for (x = 23; x <= 25; x += 0.1)
    {
      y = mirror * (2 * x - 45); // Function definition
      GnuPlotValue(x, y);        // Plot the point (x, y)
    }

    // Plot fifth segment of the curve
    for (x = 25; x <= 27; x += 0.1)
    {
      y = mirror * (5); // Function definition
      GnuPlotValue(x, y); // Plot the point (x, y)
    }

    // Plot sixth segment of the curve
    for (x = 27; x <= 28; x += 0.1)
    {
      y = mirror * (-4.2 * x + 118.4); // Function definition
      GnuPlotValue(x, y);              // Plot the point (x, y)
    }

    // Plot seventh segment of the curve
    for (x = 28; x <= 30; x += 0.1)
    {
      y = mirror * (1 - exp(-30 + x)); // Function definition
      GnuPlotValue(x, y);              // Plot the point (x, y)
    }
  }

  GnuPlotClose(); // Close the GNU plot window

  return 0; // Return 0 to indicate successful execution
}
