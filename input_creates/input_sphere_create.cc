//Program to create input files for sweep over initial sphere height

#include <vector>
#include <fstream>
#include <sstream>
#include <sys/stat.h>

using std::vector;
using std::ofstream;
using std::vector;
using std::endl;
using std::string;
using std::ostringstream;

int main()
{

  //Create arrays containing the different values of the dimensionless numbers over which we are sweeping

  vector<double> sphere_height(10);

  vector<double> bond_data(5);
  vector<double> viscos_rat_data(6);

  sphere_height[0] = 2.0;
  sphere_height[1] = 4.0;
  sphere_height[2] = 6.0;
  sphere_height[3] = 8.0;
  sphere_height[4] = 10.0;
  sphere_height[5] = 12.0;
  sphere_height[6] = 14.0;
  sphere_height[7] = 16.0;
  sphere_height[8] = 18.0;
  sphere_height[9] = 20.0;

  bond_data[0] = 1;
  bond_data[1] = 2;
  bond_data[2] = 3;
  bond_data[3] = 4;
  bond_data[4] = 5;

  viscos_rat_data[0] = 0.001;
  viscos_rat_data[1] = 0.01;
  viscos_rat_data[2] = 0.1;
  viscos_rat_data[3] = 10;
  viscos_rat_data[4] = 100;
  viscos_rat_data[5] = 1000;

  double mdr = 3.3;

  int n_sphere = 100;
  int n_interf = 100;
  double trunc = 15.0;
  //  double t_step = 0.01;
  int max_it = 60000;

  //Create output directories 

  string height_dir_name;
  string Bo_dir_name;
  string viscos_dir_name;

  ostringstream height_convert;
  ostringstream Bo_convert;
  ostringstream viscos_convert;

  const char* up = "../";

  const char* data = "height_sweep/";

  chdir(data);

  for (int i = 0; i < sphere_height.size(); i++)
    {
      height_convert << "height=" << sphere_height[i];

      height_dir_name = height_convert.str();

      mkdir(height_dir_name.c_str(), S_IRWXU);

      for (int j = 0; j < bond_data.size(); j++)
	{
	  Bo_convert << "Bo=" << bond_data[j];

	  Bo_dir_name = Bo_convert.str();

	  chdir(height_dir_name.c_str());

	  mkdir(Bo_dir_name.c_str(), S_IRWXU);

	  for (int k = 0; k < viscos_rat_data.size(); k++)
	    {
	      viscos_convert << "viscos_rat=" << viscos_rat_data[k];

	      viscos_dir_name = viscos_convert.str();

	      chdir(Bo_dir_name.c_str());

	      mkdir(viscos_dir_name.c_str(), S_IRWXU);

	      chdir(viscos_dir_name.c_str());

	      ofstream fout;

	      fout.open("dimensionless_input.dat");

	      fout << bond_data[j] << endl;
	      fout << mdr << endl;
	      fout << viscos_rat_data[k] << endl;

	      fout << n_sphere << endl;
	      fout << n_interf << endl;
	      fout << trunc << endl;
	      //	      fout << t_step << endl;
	      fout << sphere_height[i] << endl;
	      fout <<max_it << endl;

	      fout << "Input file containing the dimensionless numbers that characterise the system" << endl;

	      fout << "Bond Number" << endl;
	      fout << "Modified Density Ratio" << endl;
	      fout << "Viscosity Ratio" << endl;

	      fout << "Number of elements on sphere" << endl;
	      fout << "Number of elements on interface" << endl;
	      fout << "Truncation length of interface" << endl;
	      //	      fout << "Time step" << endl;
	      fout << "Initial height of sphere" << endl;
	      fout << "Maximum number of iterations" << endl;

	      fout.close();

	      chdir(up);

	      chdir(up);

	      viscos_convert.str(string());

	    }

	  chdir(up);

	  Bo_convert.str(string());

	}

      height_convert.str(string());
    }

  return 0;
}
