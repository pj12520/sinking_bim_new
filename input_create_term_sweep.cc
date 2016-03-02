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

  vector<double> mod_dens_rat_data(19);
  vector<double> bond_data(9);
  vector<double> viscos_rat_data(1);

  mod_dens_rat_data[0] = 10.0;
  mod_dens_rat_data[1] = 20.0;
  mod_dens_rat_data[2] = 30.0;
  mod_dens_rat_data[3] = 40.0;
  mod_dens_rat_data[4] = 50.0;
  mod_dens_rat_data[5] = 60.0;
  mod_dens_rat_data[6] = 70.0;
  mod_dens_rat_data[7] = 80.0;
  mod_dens_rat_data[8] = 90.0;
  mod_dens_rat_data[9] = 100.0;
  mod_dens_rat_data[10] = 200.0;
  mod_dens_rat_data[11] = 300.0;
  mod_dens_rat_data[12] = 400.0;
  mod_dens_rat_data[13] = 500.0;
  mod_dens_rat_data[14] = 600.0;
  mod_dens_rat_data[15] = 700.0;
  mod_dens_rat_data[16] = 800.0;
  mod_dens_rat_data[17] = 900.0;
  mod_dens_rat_data[18] = 1000.0;

  bond_data[0] = 0.01;
  bond_data[1] = 0.03;
  bond_data[2] = 0.05;
  bond_data[3] = 0.08;
  bond_data[4] = 0.1;
  bond_data[5] = 0.3;
  bond_data[6] = 0.5;
  bond_data[7] = 0.8;
  bond_data[8] = 1.0;

  viscos_rat_data[0] = 0.01;

  int n_sphere = 100;
  int n_interf = 400;
  double trunc = 15.0;
  //  double t_step = 0.01;
  double height = 5.0;
  int max_it = 5000;
  double aspect = 1.0;
  double diff_step = 1e-6;
  int n_out = 100;

  //Create output directories 

  string D_dir_name;
  string Bo_dir_name;
  string viscos_dir_name;

  ostringstream D_convert;
  ostringstream Bo_convert;
  ostringstream viscos_convert;

  const char* up = "../";

  const char* data = "term_sweep_data/";

  chdir(data);

  for (int i = 0; i < 10; i++)
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

	  for (int k = 0; k < 1; k++)
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
	      fout << aspect << endl;
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

	      viscos_convert.str(string());

	    }

	  chdir(up);

	  Bo_convert.str(string());

	}
      D_convert.str(string());

    }



  for (int i = 10; i < mod_dens_rat_data.size(); i++)
    {
      D_convert << "D=" << mod_dens_rat_data[i];

      D_dir_name = D_convert.str();

      mkdir(D_dir_name.c_str(), S_IRWXU);

      for (int j = 0; j < 5; j++)
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
	      fout << aspect << endl;
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

	      viscos_convert.str(string());

	    }

	  chdir(up);

	  Bo_convert.str(string());

	}
      D_convert.str(string());

    }


  return 0;
}
