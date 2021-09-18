/*
  TOKENIZER MODEL BASED ON STRTOK
  
  @The operating system simulator is devoted to incorporate treating basic and static 
   linear structures studied in algorithms and data structures I.

  @author Michel Pires da Silva (michel@cefetmg.br)

  @date 2021

	@copyright GNU Public License

	@cond GNU_PUBLIC_LICENSE
    	PyMid is free software: you can redistribute it and/or modify
    	it under the terms of the GNU General Public License as published by
    	the Free Software Foundation, either version 3 of the License, or
   		(at your option) any later version.
    
    	The operating system simulator is distributed in the hope that it will be useful,
    	but WITHOUT ANY WARRANTY; without even the implied warranty of
    	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    	GNU General Public License for more details.
    
    	You should have received a copy of the GNU General Public License
    	along with this program.  If not, see <http://www.gnu.org/licenses/>.
	@endcond

*/

#include "tokenizer.h"


int GetSizeOf(char *line, const char sep[]){
  char *pt;
  int index = 0;
  
  pt = strtok(line, sep); 
  while(pt){
    index ++;
    pt = strtok(NULL, sep);
  }

  return index;
}


int GetTokens(char *line, const char sep[], int *toks){
  char *pt;
  int index = 0;
  
  pt = strtok(line, sep);
  while(pt){
    *(toks+index) = atoi(pt);
    index ++;
    pt = strtok(NULL, sep);
  }
 
  return index;

}













