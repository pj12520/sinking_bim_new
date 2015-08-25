//Program to create input files for parameter sweep 3

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

  vector<double> mod_dens_rat_data(3);
  vector<double> bond_data(6);
  vector<double> viscos_rat_data(8);

  mod_dens_rat_data[0] = 10;
  mod_dens_rat_data[1] = 100;
  mod_dens_rat_data[2] = 1000;

  bond_data[0] = 0.01;
  bond_data[1] = 0.1;
  bond_data[2] = 1;
  bond_data[3] = 10;
  bond_data[4] = 100;
  bond_data[5] = 1000;

  viscos_rat_data[0] = 2;
  viscos_rat_data[1] = 3;
  viscos_rat_data[2] = 4;
  viscos_rat_data[3] = 5;
  viscos_rat_data[4] = 6;
  viscos_rat_data[5] = 7;
  viscos_rat_data[6] = 8;
  viscos_rat_data[7] = 9;

  int n_sphere = 100;
  int n_interf = 100;
  double trunc = 15.0;
  //  double t_step = 0.01;
  double height = 3.0;
  int max_it = 60000;

  //Create output directories 

  string D_dir_name;
  string Bo_dir_name;
  string viscos_dir_name;

  ostringstream D_convert;
  ostringstream Bo_convert;
  ostringstream viscos_convert;

  const char* up = "../";

  const char* data = "param_sweep4/";

  chdir(data);

  for (int i = 0; i < mod_dens_rat_data.size(); i++)
    {
      D_convert << "D=" << mod_dens_rat_data[i];

      D_dir_name = D_convert.str();

      mkdir(D_dir_name.c_str(), S_IRWXU);

      for (int j = 0; j < bond_data.size(); j++)
	{
	  Bo_convert << "Bo=" << bond_data[j];

	  Bo_dir_name = Bo_convert.str();

	  chdir(D_dir_name.c_str());

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
	      fout << mod_dens_rat_data[i] << endl;
	      fout << viscos_rat_data[k] << endl;

	      fout << n_sphere << endl;
	      fout << n_interf << endl;
	      fout << trunc << endl;
	      //	      fout << t_step << endl;
	      fout << height << endl;
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

      D_convert.str(string());
    }

  return 0;
}
