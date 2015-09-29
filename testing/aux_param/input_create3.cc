//Program to create input files for third round of testing for auxilery variables

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
  int n_sphere = 100;
  double height = 5.0;
  int max_it = 600000;
  double trunc = 15.0;

  //Create vectors containing the different values of the auxillery variables over which we are sweeping
  vector<int> n_interf(8);
  n_interf[0] = 50;
  n_interf[1] = 100;
  n_interf[2] = 150;
  n_interf[3] = 200;
  n_interf[4] = 250;
  n_interf[5] = 300;
  n_interf[6] = 350;
  n_interf[7] = 400;

  //Create output directories 

  string viscos_dir_name;

  string n_interf_dir_name;

  //Create objects to convert string to character arrays
  ostringstream viscos_convert;

  ostringstream n_interf_convert;

  //Character arrays of use
  const char* up = "../";

  const char* data = "data3/";

  const char* interf_dir = "n_interf/";

  //Move into directory for sweep over number of interface intervals
  chdir(data);
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

	  fout << n_sphere << endl;
	  fout << n_interf[j] << endl;
	  fout << trunc << endl;
	  fout << height << endl;
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

  viscos_convert.str(string());


  return 0;

}
