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

  //Create variables for the physical parameters of the system that are being fixed
  double mdr = 10.0;
  double bond = 1000.0;
  double aspect = 1.0;

  //Create arrays containing the different values of the viscosity ratio over which we are sweeping
  vector<double> viscos_rat(2);

  viscos_rat[0] = 0.1;
  viscos_rat[1] = 10.0;

  //Create variables for the auxilary variables which are not looped over
  int max_it = 600000;

  //Create vectors containing the different values of the auxillery variables over which we are sweeping
  vector<int> n_sphere(8);
  n_sphere[0] = 50;
  n_sphere[1] = 100;
  n_sphere[2] = 150;
  n_sphere[3] = 200;
  n_sphere[4] = 250;
  n_sphere[5] = 300;
  n_sphere[6] = 350;
  n_sphere[7] = 400;

  vector<int> n_interf(8);
  n_interf[0] = 50;
  n_interf[1] = 100;
  n_interf[2] = 150;
  n_interf[3] = 200;
  n_interf[4] = 250;
  n_interf[5] = 300;
  n_interf[6] = 350;
  n_interf[7] = 400;

  vector<double> trunc(10);
  trunc[0] = 10.0;
  trunc[1] = 15.0;
  trunc[2] = 20.0;
  trunc[3] = 25.0;
  trunc[4] = 30.0;
  trunc[5] = 35.0;
  trunc[6] = 40.0;
  trunc[7] = 45.0;
  trunc[8] = 50.0;
  trunc[9] = 55.0;

  vector<double> height(8);
  height[0] = 3.0;
  height[1] = 4.0;
  height[2] = 5.0;
  height[3] = 6.0;
  height[4] = 7.0;
  height[5] = 8.0;
  height[6] = 9.0;
  height[7] = 10.0;

  //Create output directories 

  string viscos_dir_name;

  string n_sphere_dir_name;
  string n_interf_dir_name;
  string trunc_dir_name;
  string height_dir_name;

  //Create objects to convert string to character arrays
  ostringstream viscos_convert;

  ostringstream n_sphere_convert;
  ostringstream n_interf_convert;
  ostringstream trunc_convert;
  ostringstream height_convert;

  //Character arrays of use
  const char* up = "../";

  const char* data = "data/";

  const char* sphere_dir = "n_sphere/";
  const char* interf_dir = "n_interf/";
  const char* trunc_dir = "truncation/";
  const char* height_dir = "initial_height/";

  //Move into directory for sweep over number of sphere intervals
  chdir(data);
  chdir(sphere_dir);

  //Sweep over viscosity ratios
  for (int i = 0; i < viscos_rat.size(); i++)
    {
      //Create directories for each viscosity ratio
      viscos_convert << "viscos_rat=" << viscos_rat[i];

      viscos_dir_name = viscos_convert.str();

      mkdir(viscos_dir_name.c_str(), S_IRWXU);

      chdir(viscos_dir_name.c_str());

      for (int j = 0; j < n_sphere.size(); j++)
	{
	  //Create directories for each n_sphere
	  n_sphere_convert << "n_sphere=" << n_sphere[j];

	  n_sphere_dir_name = n_sphere_convert.str();

	  mkdir(n_sphere_dir_name.c_str(), S_IRWXU);

	  chdir(n_sphere_dir_name.c_str());

	  //Output data to file
	  ofstream fout;

	  fout.open("dimensionless_input.dat");

	  fout << bond << endl;
	  fout << mdr << endl;
	  fout << viscos_rat[i] << endl;

	  fout << n_sphere[j] << endl;
	  fout << n_interf[1] << endl;
	  fout << trunc[1] << endl;
	  fout << height[0] << endl;
	  fout << max_it << endl;
	  fout << aspect << endl;

	  fout << "Input file containing the dimensionless numbers that characterise the system" << endl;

	  fout << "Bond Number" << endl;
	  fout << "Modified Density Ratio" << endl;
	  fout << "Viscosity Ratio" << endl;

	  fout << "Number of elements on sphere" << endl;
	  fout << "Number of elements on interface" << endl;
	  fout << "Truncation length of interface" << endl;
	  fout << "Initial height of sphere" << endl;
	  fout << "Maximum number of iterations" << endl;

	  fout.close();

	  chdir(up);

	  n_sphere_convert.str(string());
	}

      chdir(up);

      viscos_convert.str(string());

    }

  chdir(up);



  //Move into directory for sweep over number of interface intervals
  chdir(interf_dir);

  //Sweep over viscosity ratios
  for (int i = 0; i < viscos_rat.size(); i++)
    {
      //Create directories for each viscosity ratio
      viscos_convert << "viscos_rat=" << viscos_rat[i];

      viscos_dir_name = viscos_convert.str();

      mkdir(viscos_dir_name.c_str(), S_IRWXU);

      chdir(viscos_dir_name.c_str());

      for (int j = 0; j < n_interf.size(); j++)
	{
	  //Create directories for each n_sphere
	  n_interf_convert << "n_interf=" << n_interf[j];

	  n_interf_dir_name = n_interf_convert.str();

	  mkdir(n_interf_dir_name.c_str(), S_IRWXU);

	  chdir(n_interf_dir_name.c_str());

	  //Output data to file
	  ofstream fout;

	  fout.open("dimensionless_input.dat");

	  fout << bond << endl;
	  fout << mdr << endl;
	  fout << viscos_rat[i] << endl;

	  fout << n_sphere[1] << endl;
	  fout << n_interf[j] << endl;
	  fout << trunc[1] << endl;
	  fout << height[0] << endl;
	  fout << max_it << endl;
	  fout << aspect << endl;

	  fout << "Input file containing the dimensionless numbers that characterise the system" << endl;

	  fout << "Bond Number" << endl;
	  fout << "Modified Density Ratio" << endl;
	  fout << "Viscosity Ratio" << endl;

	  fout << "Number of elements on sphere" << endl;
	  fout << "Number of elements on interface" << endl;
	  fout << "Truncation length of interface" << endl;
	  fout << "Initial height of sphere" << endl;
	  fout << "Maximum number of iterations" << endl;

	  fout.close();

	  chdir(up);

	  n_interf_convert.str(string());
	}

      chdir(up);

      viscos_convert.str(string());

    }

  chdir(up);



  //Move into directory for sweep over truncation length
  chdir(trunc_dir);

  //Sweep over viscosity ratios
  for (int i = 0; i < viscos_rat.size(); i++)
    {
      //Create directories for each viscosity ratio
      viscos_convert << "viscos_rat=" << viscos_rat[i];

      viscos_dir_name = viscos_convert.str();

      mkdir(viscos_dir_name.c_str(), S_IRWXU);

      chdir(viscos_dir_name.c_str());

      for (int j = 0; j < trunc.size(); j++)
	{
	  //Create directories for each n_sphere
	  trunc_convert << "trunc=" << trunc[j];

	  trunc_dir_name = trunc_convert.str();

	  mkdir(trunc_dir_name.c_str(), S_IRWXU);

	  chdir(trunc_dir_name.c_str());

	  //Output data to file
	  ofstream fout;

	  fout.open("dimensionless_input.dat");

	  fout << bond << endl;
	  fout << mdr << endl;
	  fout << viscos_rat[i] << endl;

	  fout << n_sphere[1] << endl;
	  fout << n_interf[1] << endl;
	  fout << trunc[j] << endl;
	  fout << height[0] << endl;
	  fout << max_it << endl;
	  fout << aspect << endl;

	  fout << "Input file containing the dimensionless numbers that characterise the system" << endl;

	  fout << "Bond Number" << endl;
	  fout << "Modified Density Ratio" << endl;
	  fout << "Viscosity Ratio" << endl;

	  fout << "Number of elements on sphere" << endl;
	  fout << "Number of elements on interface" << endl;
	  fout << "Truncation length of interface" << endl;
	  fout << "Initial height of sphere" << endl;
	  fout << "Maximum number of iterations" << endl;

	  fout.close();

	  chdir(up);

	  trunc_convert.str(string());
	}

      chdir(up);

      viscos_convert.str(string());

    }

  chdir(up);




  //Move into directory for sweep over initial height
  chdir(height_dir);

  //Sweep over viscosity ratios
  for (int i = 0; i < viscos_rat.size(); i++)
    {
      //Create directories for each viscosity ratio
      viscos_convert << "viscos_rat=" << viscos_rat[i];

      viscos_dir_name = viscos_convert.str();

      mkdir(viscos_dir_name.c_str(), S_IRWXU);

      chdir(viscos_dir_name.c_str());

      for (int j = 0; j < height.size(); j++)
	{
	  //Create directories for each n_sphere
	  height_convert << "height=" << height[j];

	  height_dir_name = height_convert.str();

	  mkdir(height_dir_name.c_str(), S_IRWXU);

	  chdir(height_dir_name.c_str());

	  //Output data to file
	  ofstream fout;

	  fout.open("dimensionless_input.dat");

	  fout << bond << endl;
	  fout << mdr << endl;
	  fout << viscos_rat[i] << endl;

	  fout << n_sphere[1] << endl;
	  fout << n_interf[1] << endl;
	  fout << trunc[1] << endl;
	  fout << height[j] << endl;
	  fout << max_it << endl;
	  fout << aspect << endl;

	  fout << "Input file containing the dimensionless numbers that characterise the system" << endl;

	  fout << "Bond Number" << endl;
	  fout << "Modified Density Ratio" << endl;
	  fout << "Viscosity Ratio" << endl;

	  fout << "Number of elements on sphere" << endl;
	  fout << "Number of elements on interface" << endl;
	  fout << "Truncation length of interface" << endl;
	  fout << "Initial height of sphere" << endl;
	  fout << "Maximum number of iterations" << endl;

	  fout.close();

	  chdir(up);

	  height_convert.str(string());
	}

      chdir(up);

      viscos_convert.str(string());

    }

  chdir(up);


  return 0;

}

