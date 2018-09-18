/*****************************************************************************
 *
 * orbitalElements.c -- solar system orbital elements
 *
 * Copyright 2018 James Fidell (james@openastroproject.org)
 *
 * License:
 *
 * This file is part of the Open Astro Project.
 *
 * The Open Astro Project is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * The Open Astro Project is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the Open Astro Project.  If not, see
 * <http://www.gnu.org/licenses/>.
 *
 *****************************************************************************/

#include <oa_common.h>

#include <openastro/ephemeris.h>

#include "orbitalElements.h"


orbitalElement orbitalElements[OA_EPHEM_NUM_SSO+1] =
{
  { // Dummy
	  .longitudeM			= 0.0,
	  .longitudeC			= 0.0,
	  .inclinationM		= 0.0,
	  .inclinationC		= 0.0,
	  .perihelionM		= 0.0,
	  .perihelionC		= 0.0,
	  .semiMajorAxisM	= 0.0,
	  .semiMajorAxisC	= 0.0,
	  .eccentricityM	= 0.0,
	  .eccentricityC	= 0.0,
	  .meanAnomalyM		= 0.0,
	  .meanAnomalyC		= 0.0,
  },
  { // Mercury
	  .longitudeM			= 3.24587E-5,
	  .longitudeC			= 48.3313,
	  .inclinationM		= 5.00E-8,
	  .inclinationC		= 7.0047,
	  .perihelionM		= 1.01444E-5,
	  .perihelionC		= 29.1241,
	  .semiMajorAxisM	= 0.0,
	  .semiMajorAxisC	= 0.387098,
	  .eccentricityM	= 5.59E-10,
	  .eccentricityC	= 0.205635,
	  .meanAnomalyM		= 4.0923344368,
	  .meanAnomalyC		= 168.6562
  },
  { // Venus
	  .longitudeM			= 2.46590E-5,
	  .longitudeC			= 76.6799,
	  .inclinationM		= 2.75E-8,
	  .inclinationC		= 3.3946,
	  .perihelionM		= 1.38374E-5,
	  .perihelionC		= 54.8910,
	  .semiMajorAxisM	= 0.0,
	  .semiMajorAxisC	= 0.723330,
	  .eccentricityM	= -1.302E-9,
	  .eccentricityC	= 0.006773,
	  .meanAnomalyM		= 1.6021302244,
	  .meanAnomalyC		= 48.0052
  },
  { // Earth -- another dummy entry
	  .longitudeM			= 0.0,
	  .longitudeC			= 0.0,
	  .inclinationM		= 0.0,
	  .inclinationC		= 0.0,
	  .perihelionM		= 0.0,
	  .perihelionC		= 0.0,
	  .semiMajorAxisM	= 0.0,
	  .semiMajorAxisC	= 0.0,
	  .eccentricityM	= 0.0,
	  .eccentricityC	= 0.0,
	  .meanAnomalyM		= 0.0,
	  .meanAnomalyC		= 0.0,
  },
  { // Mars
	  .longitudeM			= 2.11081E-5,
	  .longitudeC			= 49.5574,
	  .inclinationM		= -1.78E-8,
	  .inclinationC		= 1.8497,
	  .perihelionM		= 2.92961E-5,
	  .perihelionC		= 286.5016,
	  .semiMajorAxisM	= 0.0,
	  .semiMajorAxisC	= 1.523688,
	  .eccentricityM	= 2.516E-9,
	  .eccentricityC	= 0.093405,
	  .meanAnomalyM		= 0.5240207766,
	  .meanAnomalyC		= 18.6021
  },
  { // Jupiter
	  .longitudeM			= 2.76854E-5,
	  .longitudeC			= 100.4542,
	  .inclinationM		= -1.557E-7,
	  .inclinationC		= 1.3030,
	  .perihelionM		= 1.64505E-5,
	  .perihelionC		= 273.8777,
	  .semiMajorAxisM	= 0.0,
	  .semiMajorAxisC	= 5.20256,
	  .eccentricityM	= 4.469E-9,
	  .eccentricityC	= 0.048498,
	  .meanAnomalyM		= 0.0830853001,
	  .meanAnomalyC		= 19.8950
  },
  { // Saturn
	  .longitudeM			= 2.38980E-5,
	  .longitudeC			= 113.6634,
	  .inclinationM		= -1.081E-7,
	  .inclinationC		= 2.4886,
	  .perihelionM		= 2.97661E-5,
	  .perihelionC		= 339.3939,
	  .semiMajorAxisM	= 0.0,
	  .semiMajorAxisC	= 9.55475,
	  .eccentricityM	= -9.499E-9,
	  .eccentricityC	= 0.055546,
	  .meanAnomalyM		= 0.0334442282,
	  .meanAnomalyC		= 316.9670
  },
  { // Uranus
	  .longitudeM			= 1.3978E-5,
	  .longitudeC			= 74.0005,
	  .inclinationM		= 1.9E-8,
	  .inclinationC		= 0.7733,
	  .perihelionM		= 3.0565E-5,
	  .perihelionC		= 96.6612,
	  .semiMajorAxisM	= -1.55E-8,
	  .semiMajorAxisC	= 19.18171,
	  .eccentricityM	= 7.45E-9,
	  .eccentricityC	= 0.047318,
	  .meanAnomalyM		= 0.011725806,
	  .meanAnomalyC		= 142.5905
  },
  { // Neptune
	  .longitudeM			= 3.0173E-5,
	  .longitudeC			= 131.7806,
	  .inclinationM		= -2.55E-7,
	  .inclinationC		= 1.7700,
	  .perihelionM		= -6.027E-6,
	  .perihelionC		= 272.8461,
	  .semiMajorAxisM	= 3.313E-8,
	  .semiMajorAxisC	= 30.05826,
	  .eccentricityM	= 2.15E-9,
	  .eccentricityC	= 0.008606,
	  .meanAnomalyM		= 0.005995147,
	  .meanAnomalyC		= 260.2471
  },
  { // Pluto -- another dummy entry
	  .longitudeM			= 0.0,
	  .longitudeC			= 0.0,
	  .inclinationM		= 0.0,
	  .inclinationC		= 0.0,
	  .perihelionM		= 0.0,
	  .perihelionC		= 0.0,
	  .semiMajorAxisM	= 0.0,
	  .semiMajorAxisC	= 0.0,
	  .eccentricityM	= 0.0,
	  .eccentricityC	= 0.0,
	  .meanAnomalyM		= 0.0,
	  .meanAnomalyC		= 0.0,
  },
  { // Moon
	  .longitudeM			= -0.0529538083,
	  .longitudeC			= 125.1228,
	  .inclinationM		= 0.0,
	  .inclinationC		= 5.1454,
	  .perihelionM		= 0.1643573223,
	  .perihelionC		= 318.0634,
	  .semiMajorAxisM	= 0.0,
	  .semiMajorAxisC	= 60.2666, // Earth radii, not AU)
	  .eccentricityM	= 0.0,
	  .eccentricityC	= 0.054900,
	  .meanAnomalyM		= 13.0649929509,
	  .meanAnomalyC		= 115.3654
  },
  { // Sun
	  .longitudeM			= 0.0,
	  .longitudeC			= 0.0,
	  .inclinationM		= 0.0,
	  .inclinationC		= 0.0,
	  .perihelionM		= 4.70935E-5,
	  .perihelionC		= 282.9404,
	  .semiMajorAxisM	= 0.0,
	  .semiMajorAxisC	= 1.0,
	  .eccentricityM	= -1.151E-9,
	  .eccentricityC	= 0.016709,
	  .meanAnomalyM		= 0.9856002585,
	  .meanAnomalyC		= 356.0470
  }
};
