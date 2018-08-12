// rdt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

double rdt_factor(double Vtot, double Vtarget);
double rdt_voltage_R1(double Vtot, double R1, double R2);
double rdt_voltage_R2(double Vtot, double R1, double R2);
double rdt_current(double Vtot, double R1, double R2);
void   printInfo();
void   printStandardValues();
void   printInvalidArgumentsError();

int main(int argc, char *argv[])
{
  if (argc == 2)
  {
    if (string(argv[1]) == "info")
      printInfo();
    else if (string(argv[1]) == "standard")
      printStandardValues();
    else
      cout << endl << "  Error: Invalid argument. For more information type: rdt info." << endl << endl;
  }
  else if (argc == 3)
  {
    double Vtot    = atof(argv[1]);
    double Vtarget = atof(argv[2]);

    if (Vtot < Vtarget)
      cout << endl << "  Error: Vtot has to be bigger than the Vtarget. For more information type: rdt info." << endl << endl;
    else if (Vtot == 0 || Vtarget == 0)
      printInvalidArgumentsError();
    else
      cout << endl 
           << "To obtain the target voltage on R2:  R1 = " << rdt_factor(Vtot, Vtarget) << " * R2" << endl
           << "To obtain the target voltage on R1:  R2 = " << rdt_factor(Vtot, Vtarget) << " * R1" << endl << endl;

  }
  else if (argc == 4)
  {
    double Vtot = atof(argv[1]);
    double R1   = atof(argv[2]);
    double R2   = atof(argv[3]);

    if (Vtot == 0 || R1 == 0 || R2 == 0)
      printInvalidArgumentsError();
    else
      cout << endl 
           << "Voltage on R2:                    UR2  = " << rdt_voltage_R2(Vtot, R1, R2) << "V" << endl
           << "Voltage on R1:                    UR1  = " << rdt_voltage_R1(Vtot, R1, R2) << "V" << endl
           << "The current through the divider:  Idiv = " << rdt_current(Vtot, R1, R2) << "A" << endl << endl;

  }
  else
  {
    cout << endl << "  Error: Invalid number of arguments. For more information type: rdt info." << endl << endl;
  }

  return 0;
}

double rdt_factor(double Vtot, double Vtarget)
{
  return Vtot / Vtarget - 1; 
}

double rdt_voltage_R1(double Vtot, double R1, double R2)
{
  return R1 / (R1 + R2) * Vtot;
}

double rdt_voltage_R2(double Vtot, double R1, double R2)
{
  return R2 / (R1 + R2) * Vtot;
}

double rdt_current(double Vtot, double R1, double R2)
{
  return Vtot / (R1 + R2);
}

void printInfo()
{
  cout << endl 
       << "  This tool is designed to help you calculate the resistances needed to obtain" << endl
       << "a desired voltage using a resistive voltage divider and to calculate the divided voltage:" << endl << endl
       << "  UR1 = R1 / (R1 + R2) * Vtot" << endl
       << "  UR2 = R2 / (R1 + R2) * Vtot" << endl << endl
       << "Syntax: " << endl
       << "  To calculate the resistances: " << endl
       << "        rdt Vtot Vtarg" << endl
       << "  To calculate the voltage on the resistances: " << endl
       << "        rdt Vtot R1 R2" << endl
       << "  To display standard resistor values: " << endl
       << "        rdt \"standard\"" << endl << endl;
}

void   printStandardValues()
{
  cout << endl
    << "  Standard Resistor Values:" << endl << endl

    << "        +-0.1%, +-0.25%, +-0.5%:" << endl

    << "10.0   14.7   21.5   31.6    46.4   68.1" << endl
    << "10.1   14.9   21.8   32.0    47.0   69.0" << endl
    << "10.2   15.0   22.1   32.4    47.5   69.8" << endl
    << "10.4   15.2   22.3   32.8    48.1   70.6" << endl
    << "10.5   15.4   22.6   33.2    48.7   71.5" << endl
    << "10.6   15.6   22.9   33.6    49.3   72.3" << endl
    << "10.7   15.8   23.2   34.0    49.9   73.2" << endl
    << "10.9   16.0   23.4   34.4    50.5   74.1" << endl
    << "11.0   16.2   23.7   34.8    51.1   75.0" << endl
    << "11.1   16.4   24.0   35.2    51.7   75.9" << endl
    << "11.3   16.5   24.3   35.7    52.3   76.8" << endl
    << "11.4   16.7   24.6   36.1    53.0   77.7" << endl
    << "11.5   16.9   24.9   36.5    53.6   78.7" << endl
    << "11.7   17.2   25.2   37.0    54.2   79.6" << endl
    << "11.8   17.4   25.5   37.4    54.9   80.6" << endl
    << "12.0   17.6   25.8   37.9    55.6   81.6" << endl
    << "12.1   17.8   26.1   38.3    56.2   82.5" << endl
    << "12.3   18.0   26.4   38.8    56.9   83.5" << endl
    << "12.4   18.2   26.7   39.2    57.6   84.5" << endl
    << "12.6   18.4   27.1   39.7    58.3   85.6" << endl
    << "12.7   18.7   27.4   40.2    59.0   86.6" << endl
    << "12.9   18.9   27.7   40.7    59.7   87.6" << endl
    << "13.0   19.1   28.0   41.2    60.4   88.7" << endl
    << "13.2   19.3   28.4   41.7    61.2   89.8" << endl
    << "13.3   19.6   28.7   42.2    61.9   90.9" << endl
    << "13.5   19.8   29.1   42.7    62.6   92.0" << endl
    << "13.7   20.0   29.4   43.2    63.4   93.1" << endl
    << "13.8   20.3   29.8   43.7    64.2   94.2" << endl
    << "14.0   20.5   30.1   44.2    64.9   95.3" << endl
    << "14.2   20.8   30.5   44.8    65.7   96.5" << endl
    << "14.3   21.0   30.9   45.3    66.5   97.6" << endl
    << "14.5   21.3   31.2   45.9    67.3   98.8" << endl << endl

    << "                 +-1%:" << endl

    << "10.0   14.7   21.5   31.6   46.4   68.1" << endl
    << "10.2   15.0   22.1   32.4   47.5   69.8" << endl
    << "10.5   15.4   22.6   33.2   48.7   71.5" << endl
    << "10.7   15.8   23.2   34.0   49.9   73.2" << endl
    << "11.0   16.2   23.7   34.8   51.1   75.0" << endl
    << "11.3   16.5   24.3   35.7   52.3   76.8" << endl
    << "11.5   16.9   24.9   36.5   53.6   78.7" << endl
    << "11.8   17.4   25.5   37.4   54.9   80.6" << endl
    << "12.1   17.8   26.1   38.3   56.2   82.5" << endl
    << "12.4   18.2   26.7   39.2   57.6   84.5" << endl
    << "12.7   18.7   27.4   40.2   59.0   86.6" << endl
    << "13.0   19.1   28.0   41.2   60.4   88.7" << endl
    << "13.3   19.6   28.7   42.2   61.9   90.9" << endl
    << "13.7   20.0   29.4   43.2   63.4   93.1" << endl
    << "14.0   20.5   30.1   44.2   64.9   95.3" << endl
    << "14.3   21.0   30.9   45.3   66.5   97.6" << endl << endl

    << "      +-2%, +-5%:" << endl

    << "10   16    27   43   68" << endl
    << "11   18    30   47   75" << endl
    << "12   20    33   51   82" << endl
    << "13   22    36   56   91" << endl
    << "15   24    39   62     " << endl << endl

    << "      +-10%: " << endl

    << "10   18   33   56" << endl
    << "12   22   39   68" << endl
    << "15   27   47   82" << endl << endl;
}

void   printInvalidArgumentsError()
{
  cout << endl << "  Error: Invalid arguments. All the arguments have to be integer" << endl
    << "or floating point numbers which are greater than 0." << endl
    << "For more information type : rdt info." << endl << endl;
}