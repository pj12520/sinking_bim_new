//Program to create input files for sweep over number of intervals on interface

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

  vector<double> n_interf(10);

  vector<double> mdr(2);
  vector<double> bond_data(3);
  vector<double> viscos_rat_data(3);

  n_interf[0] = 50.0;
  n_interf[1] = 100.0;
  n_interf[2] = 150.0;
  n_interf[3] = 200.0;
  n_interf[4] = 250.0;
  n_interf[5] = 300.0;
  n_interf[6] = 350.0;
  n_interf[7] = 400.0;
  n_interf[8] = 450.0;
  n_interf[9] = 500.0;

  mdr[0] = 1.0;
  mdr[1] = 1000.0;

  bond_data[0] = 0.001;
  bond_data[1] = 1.0;
  bond_data[2] = 1000;

  viscos_rat_data[0] = 0.001;
  viscos_rat_data[1] = 1.0;
  viscos_rat_data[2] = 1000;

  int n_sphere = 100;
  double trunc = 15.0;
  double sphere_height = 3.0;
  //  double t_step = 0.01;
  int max_it = 60000;

  //Create output directories 

  string interv_dir_name;

  string mdr_dir_name;
  string Bo_dir_name;
  string viscos_dir_name;

  ostringstream interv_convert;

  ostringstream mdr_convert;
  ostringstream Bo_convert;
  ostringstream viscos_convert;

  const char* up = "../";

  const char* data = "interv_sweep/";

  chdir(data);

  for (int i = 0; i < n_interf.size(); i++)
    {
      interv_convert << "n_interf=" << n_interf[i];

      interv_dir_name = interv_convert.str();

      mkdir(interv_dir_name.c_str(), S_IRWXU);

      for (int l = 0; l < mdr.size(); l++)
	{
	  mdr_convert << "D=" << mdr[l];

	  mdr_dir_name = mdr_convert.str();

	  chdir(interv_dir_name.c_str());

	  mkdir(mdr_dir_name.c_str(), S_IRWXU);

	  for (int j = 0; j < bond_data.size(); j++)
	    {
	      Bo_convert << "Bo=" << bond_data[j];

	      Bo_dir_name = Bo_convert.str();

	      chdir(mdr_dir_name.c_str());

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
		  fout << mdr[l] << endl;
		  fout << viscos_rat_data[k] << endl;

		  fout << n_sphere << endl;
		  fout << n_interf[i] << endl;
		  fout << trunc << endl;
		  //	      fout << t_step << endl;
		  fout << sphere_height << endl;
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

	  chdir(up);

	  mdr_convert.str(string());
	}

      interv_convert.str(string());
    }

  return 0;
}
