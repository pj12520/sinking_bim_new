//Program to model the impact of a sphere onto a fluid fluid interface 

#include <string>
#include <fstream>
#include <sstream>

#include <iostream> //Currently only included for debugging purposes. Can be removed when program is functional
#include <iomanip> //Currently only included for debugging purposes. Can be removed when program is functional

#include "inout.h"
#include "object.h"
#include "testing.h"
#include "build.h"
#include "solve.h"
#include "vel.h"
#include "geo.h"
#include "ellip.h"

using std::string;
using std::ofstream;
using std::ostringstream;

using std::cout; //Currently only used for debugging purposes. Can be removed when program is functional
using std::endl; //Currently only used for debugging purposes. Can be removed when program is functional
using std::setw; //Currently only used for debugging purposes. Can be removed when program is functional

int main(int argc, char *argv[])
{
  //Read in input data from input file
  dimless_in input;
  string infile(argv[1]);
  Dimless_in(infile, &input);

  //TESTING - Test that input data is read correctly//////////////////////
  //In_test(input);
  ///////////////////////////////////////////////////////////////////////

  //Create sphere
  particle sphere;
  sphere.intervals.resize(input.n_sphere);
  Create_sphere(&sphere, input.init_height, input.n_sphere, input.aspect);
  
  //Create interface
  surf interf;
  interf.intervals.resize(input.n_int);
  Create_interf(&interf, input.n_int, input.max_arc);

  //Testing - Test that sphere and interface are constructed correctly///////////////////////////////////

  //Produce functions r(theta), z(theta), z(r) for the sphere and r(s), z(s) and z(r) for the interface
  //Config(sphere, interf);
  //Output values of the interval bounds and midpoints for both the sphere and interface
  //////////////////////////////////////////////////////////////////////////////////////////////////////

  //Create the matrix of coefficients and the known vector for the linear system
  int order = 2 * (input.n_int + input.n_sphere - 1);

  vector<vector<double> > coeffs(order);
  for (int i = 0; i < order; i++)
    {
      coeffs[i].resize(order);
    }

  vector<double> known(order);

  //Start loop over iterations
  int it = 0;
  double time = 0.0;

  double min_tstep;
  //Contraint on time step from quasi-static condition
  //  if (input.viscos_rat < 1)
  //{
      //      min_tstep = min(0.01 / sqrt(input.bond), 0.01 * 2.0 * input.mdr * sqrt(input.bond) * input.viscos_rat / 9.0);
  //  min_tstep = min(0.01, 0.01 * input.mdr * input.bond * input.viscos_rat);
  //}
  //  else
  //{
      //      min_tstep = min(0.01 / sqrt(input.bond), 0.01 * 2.0 * input.mdr * sqrt(input.bond) / 9.0);
      min_tstep = min(0.01, 0.01 * input.mdr * input.bond);
      //}
  //  min_tstep = 0.01;
  double t_step = min_tstep;
  //  double t_step = 0.01;

  //Testing - Variables used to check timestep
  double max_vel;
  double min_sep;
  double crit;

  double max_rad_vel;
  double max_vert_vel;

  double rad_crit;
  double vert_crit;

  double min_vert_sep;
  double min_rad_sep;

  //Vectors to store the interfacial velocity
  vector<double> rad_vel(input.n_int);
  vector<double> vert_vel(input.n_int);


  //Object to output the position and velocity of the sphere and the entrained volume
  ofstream sphere_out;
  //  string out_file = "D=" + static_cast<ostringstream*>( &(ostringstream() << input.mdr) )->str() + "/Bo=" + static_cast<ostringstream*>( &(ostringstream() << input.bond) )->str() + "/viscos_rat=" + static_cast<ostringstream*>( &(ostringstream() << input.viscos_rat) )->str() + "/sphere.dat";
  string out_file = "sphere.dat";
  sphere_out.open(out_file.c_str());
  sphere_out << setw(20) << "iteration" << setw(20) << "time" << setw(20) << "height" << setw(20) << "velocity" << setw(20) << "Entrained Volume" << endl;

  
  //Vectors of output data structures
  vector<out_data> output;

  //Number of time steps after which step size increases by viscosity ratio.
  //  int steps = 50000;
  
  while(it < input.max_it)
    {
      //Build the linear system
      Build(&coeffs, &known, sphere, interf, input.viscos_rat, input.bond, input.mdr);

      //Testing-Test the creation of the linear system/////////////////////////////////
      Lin_sys_test(&coeffs, &known);
      //////////////////////////////////////////////////////////////////////////////////

      //Solve the linear system 
      vector<double> unknown(order);

      Solve(order, &coeffs, &known, &unknown);

      //Update the vectors storing the interfacial velocities
      for (int i = 0; i < input.n_int; i++)
	{
	  if (i == 0)
	    {
	      rad_vel[i] = 0.0;
	      vert_vel[i] = unknown[i + input.n_int - 1];

	      max_vel = max(fabs(vert_vel[i]), fabs(unknown[unknown.size()-1])); //Testing - used in time step test

	      max_rad_vel = 0.0;
	      max_vert_vel = fabs(vert_vel[i]);

	      min_rad_sep = interf.mid_rad[1] - interf.mid_rad[0];
	      min_vert_sep = interf.mid_vert[1] - interf.mid_vert[0];
	    }
	  else
	    {
	      rad_vel[i] = unknown[i - 1];
	      vert_vel[i] = unknown[i + input.n_int - 1];

	      //Testing///////////////////////////////////
	      if (fabs(rad_vel[i]) > max_vel || fabs(vert_vel[i]) > max_vel)
		{
		  max_vel = max(fabs(rad_vel[i]), fabs(vert_vel[i]));
		}

	      if (fabs(rad_vel[i]) > max_rad_vel)
		{
		  max_rad_vel = fabs(rad_vel[i]);
		}

	      if (fabs(vert_vel[i]) > max_vert_vel)
		{
		  max_vert_vel = fabs(vert_vel[i]);
		}

		if (interf.mid_rad[i] - interf.mid_rad[i - 1] < min_rad_sep)
		  {
		    min_rad_sep = interf.mid_rad[i] - interf.mid_rad[i - 1];
		  }

		if (interf.mid_vert[i] - interf.mid_vert[i - 1] < min_vert_sep)
		  {
		    min_vert_sep = interf.mid_vert[i] - interf.mid_vert[i - 1];
		  }

	      ////////////////////////////////////////
	    }
	}

      //Testing - check time step////////////////////////
      min_sep = interf.intervals[0].width;
      crit = min_sep / max_vel;

      vert_crit = min_vert_sep / max_vert_vel;
      rad_crit = min_rad_sep / max_rad_vel;

      t_step = min(min_tstep, crit);

      //      if (it >= steps)
      //{
      //  t_step = 0.9 * input.viscos_rat * t_step;
      //}

      /////////////////////////////////////////////////


      //Output the configuration
      //      Out_sys(it, sphere, interf, input.mdr, input.bond, input.viscos_rat, &rad_vel, &vert_vel);

      //Store the configuration
      output.resize(output.size() + 1);

      output[output.size() - 1].it = it;
      output[output.size() - 1].time = time;
      output[output.size() - 1].sphere_pos = sphere.height;

      for (int i = 0; i < interf.n_int; i++)
	{
	  output[output.size() - 1].interf_rad.push_back(interf.mid_rad[i]);
	  output[output.size() - 1].interf_vert.push_back(interf.mid_vert[i]);
	}

      for (int i = 0; i < unknown.size(); i++)
	{
	  //	  	  cout << i << '\t' << unknown[i] << endl;
	}

      //Testing - Test the solution for the sphere velocity ///////////////////////////
      cout << setw(20) << it << setw(20) << time << setw(20) << sphere.height << setw(20) << unknown[unknown.size() - 1] << setw(20) << t_step << setw(20) << rad_crit << setw(20) << vert_crit << endl;
      //      cout << setw(20) << input.aspect << setw(20) << it << setw(20) << time << setw(20) << sphere.height << setw(20) << unknown[unknown.size() - 1] << endl;
      //cout << setw(20) << sphere.aspect << setw(20) << sphere.n_int << setw(20) << time << setw(20) << sphere.height << setw(20) << unknown[unknown.size() - 1] << endl;
      ////////////////////////////////////////////////////////////////////////////////

      
      //Outout the sphere position and velocity
      sphere_out << setw(20) << it << setw(20) << time << setw(20) << sphere.height << setw(20) << unknown[unknown.size() - 1] << setw(20) << interf.ent_vol << endl;
      //Perform the 1st time step
      Iterate(input.n_int, &unknown, &interf.midpoints, &interf.mid_rad, &interf.mid_vert, &sphere.height, t_step);

      //Iterate the system
      it = it + 1;
      time = time + t_step;

      //Update the properties of the interface and sphere
      Up_interf(&interf, sphere.height, input.diff_step);
      Up_sphere(&sphere);

      //Testing - Check the new configuration of the system/////////////////////////////////////////////////
      Config(sphere, interf);
      ////////////////////////////////////////////////////////////////////////////////////////////////////////

      //Check the separation between the sphere and the interface isn't smaller than the distance between collocation points
      double perim_comp_param = 2 - input.aspect * input.aspect;
      double perim = 2.0 * input.aspect * Ellip2(perim_comp_param);
      double particle_sep = perim / input.n_sphere;

      int break_criteria = Break_Crit(&interf.midpoints, &interf.mid_rad, &interf.mid_vert, sphere.height, input.aspect, particle_sep);

      if (break_criteria == 1)
	{
	  sphere_out << "# Sphere and interface collide" << endl;
	  break;
	}
      else if (break_criteria == 2)
	{
	  sphere_out << "# Tail snaps" << endl;
	  break;
	}

      //Output the system
      //    Out_sys(it, sphere, interf, input.mdr, input.bond, input.viscos_rat);
    }

  sphere_out.close();
  
  //Need to output the configuration at 20 iterations plus the initial and final ones
  int n_it = it - 1; //Number of iterations that occured

  double final_time = time - t_step;

  double final_pos = sphere.height;

  if (n_it < input.n_out)
    {
      vector<int> out_it(n_it + 1);

      for (int i = 0; i < out_it.size(); i++)
	{
	  out_it[i] = i;

	  Out_sys(output[out_it[i]], input.mdr, input.bond, input.viscos_rat, input.aspect);
	}

    }
  else 
    {
      vector<int> out_it(input.n_out + 1);
      out_it[0] = 0;
      out_it[input.n_out] = n_it;

      for (int i = 1; i < input.n_out; i++)
	{
	  double factor = i * final_time / input.n_out;

	  double space_factor = i * fabs(final_pos - input.init_height) / input.n_out;

	  /*	  for (int j = 1; j < output.size(); j++)
	    {
	      if (factor <= output[j].time && factor >= output[j - 1].time)
		{
		  out_it[i] = output[j].it;
		}
	    }
	  */
	  for (int j = 1; j < output.size(); j++)
	    {
	      if (space_factor <= fabs(output[j].sphere_pos - input.init_height) && space_factor >= fabs(output[j - 1].sphere_pos - input.init_height))
		{
		  out_it[i] = output[j].it;
		}
	    }
	}

      for (int i = 0; i < out_it.size(); i++)
	{
	  Out_sys(output[out_it[i]], input.mdr, input.bond, input.viscos_rat, input.aspect);
	}
    }
  
  /*
  //Output all data
  int n_it = it - 1; //Number of iterations that occured
  vector<int> out_it(n_it + 1);

  for (int i = 0; i < out_it.size(); i++)
    {
      out_it[i] = i;
      
      Out_sys(output[out_it[i]], input.mdr, input.bond, input.viscos_rat, input.aspect);
    }
  */

  return 0;
}

