/*
thot package for statistical machine translation
Copyright (C) 2013 Daniel Ortiz-Mart\'inez
 
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 3
of the License, or (at your option) any later version.
 
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.
 
You should have received a copy of the GNU Lesser General Public License
along with this program; If not, see <http://www.gnu.org/licenses/>.
*/
 
/********************************************************************/
/*                                                                  */
/* Module: Prob                                                     */
/*                                                                  */
/* Definitions file: Prob.cc                                        */
/*                                                                  */
/********************************************************************/


//--------------- Include files --------------------------------------

#include "Prob.h"

//--------------- Global variables -----------------------------------

//--------------- Function declarations 

//--------------- Classes --------------------------------------------


//--------------- Prob class methods
//

LgProb Prob::get_lp(void)const
{
  LgProb lp(log(x));

  return lp;
}

