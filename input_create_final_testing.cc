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

  vector<double> mod_dens_rat_data(3);
  vector<double> bond_data(3);
  vector<double> viscos_rat_data(4);

  vector<double> height(6);
  vector<double> trunc(9);
  vector<double> n_interf(8);
  vector<double> diff_step(8);

  mod_dens_rat_data[0] = 10.0;
  mod_dens_rat_data[1] = 3.45;
  mod_dens_rat_data[2] = 3.256;

  bond_data[0] = 10.0;
  bond_data[1] = 0.88;
  bond_data[2] = 3.95;

  viscos_rat_data[0] = 0.001;
  viscos_rat_data[1] = 10.0;
  viscos_rat_data[2] = 18.5;
  viscos_rat_data[3] = 0.43;

  height[0] = 3.0;
  height[1] = 5.0;
  height[2] = 7.0;
  height[3] = 9.0;
  height[4] = 11.0;
  height[5] = 13.0;

  trunc[0] = 10.0;
  trunc[1] = 15.0;
  trunc[2] = 20.0;
  trunc[3] = 25.0;
  trunc[4] = 30.0;
  trunc[5] = 35.0;
  trunc[6] = 40.0;
  trunc[7] = 45.0;
  trunc[8] = 50.0;
  
  n_interf[0] = 100.0;
  n_interf[1] = 150.0;
  n_interf[2] = 200.0;
  n_interf[3] = 250.0;
  n_interf[4] = 300.0;
  n_interf[5] = 350.0;
  n_interf[6] = 400.0;
  n_interf[7] = 450.0;

  diff_step[0] = 1E-7;
  diff_step[1] = 1E-6;
  diff_step[2] = 1E-5;
  diff_step[3] = 1E-4;
  diff_step[4] = 1E-3;
  diff_step[5] = 1E-2;
  diff_step[6] = 1E-1;
  diff_step[7] = 1E-0;

  int n_sphere = 100;
  //  double t_step = 0.01;
  int max_it = 10000;
  double aspect = 1.0;
  int n_out = 100;

  //Create output directories 

  string D_dir_name;
  string Bo_dir_name;
  string height_dir_name;
  string trunc_dir_name;
  string ninterf_dir_name;
  string diff_dir_name;
  string viscos_dir_name;

  ostringstream D_convert;
  ostringstream Bo_convert;
  ostringstream height_convert;
  ostringstream trunc_convert;
  ostringstream ninterf_convert;
  ostringstream diff_convert;
  ostringstream viscos_convert;

  const char* up = "../";

  const char* data = "data/";

  chdir(data);

  //Now Height tests

  for (int i = 0; i < height.size(); i++)
    {
      height_convert << "height=" << height[i];

      height_dir_name = height_convert.str();

      mkdir(height_dir_name.c_str(), S_IRWXU);

      for (int j = 0; j < 2; j++)
	{
	  viscos_convert << "viscos_rat=" << viscos_rat_data[j];

	  viscos_dir_name = viscos_convert.str();

	  chdir(height_dir_name.c_str());

	  mkdir(viscos_dir_name.c_str(), S_IRWXU);

	  chdir(viscos_dir_name.c_str());

	  ofstream fout;

	  fout.open("dimensionless_input.dat");

	  fout << bond_data[0] << endl;
	  fout << mod_dens_rat_data[0] << endl;
	  fout << viscos_rat_data[j] << endl;

	  fout << n_sphere << endl;
	  fout << n_interf[6] << endl;
	  fout << trunc[1] << endl;
	  //	      fout << t_step << endl;
	  fout << height[i] << endl;
	  fout <<max_it << endl;
	  fout << aspect << endl;
	  fout << diff_step[1] << endl;
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

  height_convert.str(string());    
    }



  //Now truncation radius tests

  for (int i = 0; i < trunc.size(); i++)
    {
      trunc_convert << "trunc=" << trunc[i];

      trunc_dir_name = trunc_convert.str();

      mkdir(trunc_dir_name.c_str(), S_IRWXU);

      for (int j = 0; j < 2; j++)
	{
	  viscos_convert << "viscos_rat=" << viscos_rat_data[j];

	  viscos_dir_name = viscos_convert.str();

	  chdir(trunc_dir_name.c_str());

	  mkdir(viscos_dir_name.c_str(), S_IRWXU);

	  chdir(viscos_dir_name.c_str());

	  ofstream fout;

	  fout.open("dimensionless_input.dat");

	  fout << bond_data[0] << endl;
	  fout << mod_dens_rat_data[0] << endl;
	  fout << viscos_rat_data[j] << endl;

	  fout << n_sphere << endl;
	  fout << n_interf[6] << endl;
	  fout << trunc[i] << endl;
	  //	      fout << t_step << endl;
	  fout << height[4] << endl;
	  fout << max_it << endl;
	  fout << aspect << endl;
	  fout << diff_step[1] << endl;
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

  trunc_convert.str(string());    
    }



  //Now interface intervals tests

  for (int i = 0; i < n_interf.size(); i++)
    {
      ninterf_convert << "n_interf=" << n_interf[i];

      ninterf_dir_name = ninterf_convert.str();

      mkdir(ninterf_dir_name.c_str(), S_IRWXU);

      for (int j = 0; j < 2; j++)
	{
	  viscos_convert << "viscos_rat=" << viscos_rat_data[j];

	  viscos_dir_name = viscos_convert.str();

	  chdir(ninterf_dir_name.c_str());

	  mkdir(viscos_dir_name.c_str(), S_IRWXU);

	  chdir(viscos_dir_name.c_str());

	  ofstream fout;

	  fout.open("dimensionless_input.dat");

	  fout << bond_data[0] << endl;
	  fout << mod_dens_rat_data[0] << endl;
	  fout << viscos_rat_data[j] << endl;

	  fout << n_sphere << endl;
	  fout << n_interf[i] << endl;
	  fout << trunc[1] << endl;
	  //	      fout << t_step << endl;
	  fout << height[4] << endl;
	  fout << max_it << endl;
	  fout << aspect << endl;
	  fout << diff_step[1] << endl;
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

  ninterf_convert.str(string());    
    }



  //Now differentiation step size tests

  for (int i = 0; i < diff_step.size(); i++)
    {
      diff_convert << "diff_step=" << diff_step[i];

      diff_dir_name = diff_convert.str();

      mkdir(diff_dir_name.c_str(), S_IRWXU);

      for (int j = 0; j < 2; j++)
	{
	  viscos_convert << "viscos_rat=" << viscos_rat_data[j];

	  viscos_dir_name = viscos_convert.str();

	  chdir(diff_dir_name.c_str());

	  mkdir(viscos_dir_name.c_str(), S_IRWXU);

	  chdir(viscos_dir_name.c_str());

	  ofstream fout;

	  fout.open("dimensionless_input.dat");

	  fout << bond_data[0] << endl;
	  fout << mod_dens_rat_data[0] << endl;
	  fout << viscos_rat_data[j] << endl;

	  fout << n_sphere << endl;
	  fout << n_interf[6] << endl;
	  fout << trunc[1] << endl;
	  //	      fout << t_step << endl;
	  fout << height[4] << endl;
	  fout << max_it << endl;
	  fout << aspect << endl;
	  fout << diff_step[i] << endl;
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

  diff_convert.str(string());    
    }



  //Experimental verification - G25
  D_convert << "D=" << mod_dens_rat_data[1];

  D_dir_name = D_convert.str();

  mkdir(D_dir_name.c_str(), S_IRWXU);

  Bo_convert << "Bo=" << bond_data[1];

  Bo_dir_name = Bo_convert.str();

  chdir(D_dir_name.c_str());

  mkdir(Bo_dir_name.c_str(), S_IRWXU);

  viscos_convert << "viscos_rat=" << viscos_rat_data[2];

  viscos_dir_name = viscos_convert.str();

  chdir(Bo_dir_name.c_str());

  mkdir(viscos_dir_name.c_str(), S_IRWXU);

  chdir(viscos_dir_name.c_str());

  ofstream fout;

  fout.open("dimensionless_input.dat");

  fout << bond_data[1] << endl;
  fout << mod_dens_rat_data[1] << endl;
  fout << viscos_rat_data[2] << endl;

  fout << n_sphere << endl;
  fout << n_interf[6] << endl;
  fout << trunc[1] << endl;
  //	      fout << t_step << endl;
  fout << height[4] << endl;
  fout <<max_it << endl;
  fout << aspect << endl;
  fout << diff_step[1] << endl;
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

  chdir(up);

  Bo_convert.str(string());

  D_convert.str(string());




  //Experimental verification - G45
  D_convert << "D=" << mod_dens_rat_data[2];

  D_dir_name = D_convert.str();

  mkdir(D_dir_name.c_str(), S_IRWXU);

  Bo_convert << "Bo=" << bond_data[2];

  Bo_dir_name = Bo_convert.str();

  chdir(D_dir_name.c_str());

  mkdir(Bo_dir_name.c_str(), S_IRWXU);

  viscos_convert << "viscos_rat=" << viscos_rat_data[3];

  viscos_dir_name = viscos_convert.str();

  chdir(Bo_dir_name.c_str());

  mkdir(viscos_dir_name.c_str(), S_IRWXU);

  chdir(viscos_dir_name.c_str());


  fout.open("dimensionless_input.dat");

  fout << bond_data[2] << endl;
  fout << mod_dens_rat_data[2] << endl;
  fout << viscos_rat_data[3] << endl;

  fout << n_sphere << endl;
  fout << n_interf[6] << endl;
  fout << trunc[1] << endl;
  //	      fout << t_step << endl;
  fout << height[4] << endl;
  fout <<max_it << endl;
  fout << aspect << endl;
  fout << diff_step[1] << endl;
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

  chdir(up);

  Bo_convert.str(string());

  D_convert.str(string());



  return 0;
}
