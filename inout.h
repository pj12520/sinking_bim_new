/**

inout.h

Header file containing:

Definitions for structures for input and output data
Function declarations for input and output

@author Paul Jarvis
@version 1.0 16/01/2017

 */

#ifndef __INOUT_H__
#define __INOUT_H__
#pragma once

#include <string>
#include <fstream>

#include "object.h"

using std::string;

/**

Structure to contain input parameters in case where they are dimensionless parameters

@param viscos_rat  Viscosity ratio
@param bond        Bond number
@param mdr         Modified density ratio
@param n_sphere    Number of elements on the sphere surface
@param n_int       Number of elements on the interface
@param max_arc     Radius at which interface is truncated SHOULD RENAME - CURRENTLY MISLEADING
@param init_height Initial height of sphere above interface
@param max_it      Maximum number of iterations before terminating model
@param aspect      Aspect ratio of spheroid
@param diff_step   Initial step-size to be used for numerical differentiation
@param n_out       Number of time-steps at which output occurs

*/

struct dimless_in 
{
  double viscos_rat;
  double bond;
  double mdr;
  int n_sphere;
  int n_int;
  double max_arc;
  //  double t_step; //Initial time step - CURRENTLY NOT USED AS INPUT BUT CALCULATED ACCORDING TO OTHER INPUT PARAMETERS
  double init_height; 
  int max_it;
  double aspect;
  double diff_step;
  int n_out;
};

/**

Structure to contain data neccessary for output

@param it          Iteration number
@param time        Dimensionless time since start of simulation
@param sphere_pos  Height of sphere
@param interf_red  Vector containing radial coordinates of positions on interface
@param interf_vert Vector containing vertical coordinates of positions on interface

*/

struct out_data
{
  int it; //Iteration
  double time; //Time
  double sphere_pos; //Position of centre of sphere
  vector<double> interf_rad; //Radial coordinates of points on interface
  vector<double> interf_vert; //Vertical coordinates of points on interface
};


/**

Function to read in the input variables for the case that they are the dimensionless parameters

@param file   String containing the filename of the input data file
@param *input Pointer to the structure containing the input data

@return nothing
 */

void Dimless_in(string file, dimless_in *input); 


/**

Function to output the state of the system

@param data       Structure containing the data to be output
@param mdr        Modified density ratio
@param bond       Bond number
@param viscos_rat Viscosity ratio
@param aspect     Spheroid aspect ratio

@return nothing
 */

//Function to output the state of the system
void Out_sys(out_data data, double mdr, double bond, double viscos_rat, double aspect);

#endif /* INOUT_H */
