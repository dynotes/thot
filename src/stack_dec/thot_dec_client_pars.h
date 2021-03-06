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
 
#ifndef _thot_dec_client_pars
#define _thot_dec_client_pars

//--------------- Include files --------------------------------------

#if HAVE_CONFIG_H
#  include <thot_config.h>
#endif /* HAVE_CONFIG_H */

#include <myVector.h>
#include <string>

using namespace std;

//--------------- Structs --------------------------------------------

struct thot_dec_client_pars
{
  float f;
  int integer;
  unsigned int uinteger;
  std::string stlString;
  std::string stlString1;
  std::string stlString2;
  std::string stlStringSrc;
  std::string stlStringRef;
  std::string sentenceToTranslate;
  std::string strToAddToPref;
  std::string serverIP;
  Vector<float> floatVec;
  int user_id;
  int server_request_code;
  unsigned int server_port;
  int verbose;
};

#endif
