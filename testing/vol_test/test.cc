//Program to test the volume calculation

#include <vector>
#include <math.h>
#include <iostream>
#include <iomanip>

#include "../../geo.h"
#include "../../interp_1d.h"
#include "../../const.h"

using std::vector;
using std::cout;
using std::endl;
using std::setw;

using math_const::PI;

int main()
{

  //Let interface be represented by function r^2 - 5
  int n_pts = 100;
  vector<double> r(n_pts);
  vector<double> z(n_pts);
  vector<double> arc(n_pts);

  double r_max = 5.0 * sqrt(5.0);

  arc[0] = 0.0;

  for (int i = 0; i < n_pts; i++)
    {
      r[i] = i * r_max / (n_pts - 1);
      z[i] = r[i] * r[i] - 5.0;

      if (i != 0)
	{
	  arc[i] = arc[0] + Pythag(r[i] - r[i - 1], z[i] - z[i - 1]);
	}
    }

  Spline_interp rad_spline(arc, r, 1.0, sqrt(1.0 + 4.0 * r[n_pts - 1] * r[n_pts - 1]));
  Spline_interp vert_spline(arc, z, 0.0, sqrt(1.0 + 1.0 / (4.0 * r[n_pts - 1] * r[n_pts - 1])));


  vector<double> sphere_pos(5);

  sphere_pos[0] = 1.0;
  sphere_pos[1] = 0.5;
  sphere_pos[2] = 0.0;
  sphere_pos[3] = -0.5;
  sphere_pos[4] = -1.0;

  double est_vol;
  double tru_vol;

  for (int i = 0; i < 5; i++)
    {
      est_vol = Ent_vol(rad_spline, vert_spline, arc[n_pts - 1], 100, 0.0, 0.0, sphere_pos[i], 0.0, (2.0 * sqrt(105.0) + asinh(2.0 * sqrt(5.0))) / 4.0 );

      if (i == 0)
	{
	  tru_vol = 2.0 * PI * pow(5.0,3.5) / 9.0;
	}
      else if(i == 1 || i == 2 || i == 3)
	{
	  tru_vol = 2.0 * PI * pow(5.0,3.5) / 9.0 - 2.0 * PI * (1.0 - sphere_pos[i]) / 3.0;
	}
      else
	{
	  tru_vol = 2.0 * PI * pow(5.0,3.5) / 9.0 - 4.0 * PI / 3.0;
	}
      cout << setw(20) << est_vol << setw(20) << tru_vol << endl;
    }
  return 0;
}
