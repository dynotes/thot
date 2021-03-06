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
 
/**
 * @file ins_op_pair.h
 * 
 * @brief defines the less-than operator for vectors.
 */

#ifndef _ins_op_pair_h
#define _ins_op_pair_h

#if HAVE_CONFIG_H
#  include <thot_config.h>
#endif /* HAVE_CONFIG_H */

#include "utility"
#include <iostream>

template<class ELEM_X,class ELEM_Y>
ostream& operator<<(ostream &outS,
                    const pair<ELEM_X,ELEM_Y> &pair)
{
  outS<<pair.first<<" "<<pair.second;
  return outS;
}

#endif
