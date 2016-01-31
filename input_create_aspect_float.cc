//Program to create input files

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

  vector<double> mod_dens_rat_data(7);
  vector<double> bond_data(10);
  vector<double> aspect(4);

  mod_dens_rat_data[0] = 2.0;
  mod_dens_rat_data[1] = 4.0;
  mod_dens_rat_data[2] = 6.0;
  mod_dens_rat_data[3] = 8.0;
  mod_dens_rat_data[4] = 10.0;
  mod_dens_rat_data[5] = 100.0;
  mod_dens_rat_data[6] = 1000.0;

  bond_data[0] = 0.01;
  bond_data[1] = 0.1;
  bond_data[2] = 1.0;
  bond_data[3] = 2.0;
  bond_data[4] = 4.0;
  bond_data[5] = 6.0;
  bond_data[6] = 8.0;
  bond_data[7] = 10.0;
  bond_data[8] = 100.0;
  bond_data[9] = 1000.0;

  aspect[0] = 0.1;
  aspect[1] = 0.5;
  aspect[2] = 2;
  aspect[3] = 10;

  int n_sphere = 100;
  int n_interf = 400;
  double trunc = 15.0;
  //  double t_step = 0.01;
  double height = 11.0;
  int max_it = 100000;
  double viscos_rat = 1.0;
  double diff_step = 1e-6;
  int n_out = 100;

  //Create output directories 

  string D_dir_name;
  string Bo_dir_name;
  string aspect_dir_name;

  ostringstream D_convert;
  ostringstream Bo_convert;
  ostringstream aspect_convert;

  const char* up = "../";

  const char* data = "data/";

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

	  for (int k = 0; k < aspect.size(); k++)
	    {
	      aspect_convert << "aspect_rat=" << aspect[k];

	      aspect_dir_name = aspect_convert.str();

	      chdir(Bo_dir_name.c_str());

	      mkdir(aspect_dir_name.c_str(), S_IRWXU);

	      chdir(aspect_dir_name.c_str());

	      ofstream fout;

	      fout.open("dimensionless_input.dat");

	      fout << bond_data[j] << endl;
	      fout << mod_dens_rat_data[i] << endl;
	      fout << viscos_rat << endl;

	      fout << n_sphere << endl;
	      fout << n_interf << endl;
	      fout << trunc << endl;
	      //	      fout << t_step << endl;
	      fout << height << endl;
	      fout <<max_it << endl;
	      fout << aspect[k] << endl;
	      fout << diff_step << endl;
	      fout << n_out << endl;

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
	      fout << "Aspect Ratio" << endl;
	      fout << "Initial step size used in the numerical differentiation" << endl;
	      fout << "Number of times at which output occurs" << endl;
	      fout.close();

	      chdir(up);
	      
	      chdir(up);

	      aspect_convert.str(string());

	    }

	  chdir(up);

	  Bo_convert.str(string());

	}
      D_convert.str(string());

    }


  return 0;
}
