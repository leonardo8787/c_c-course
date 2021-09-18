/*
  SWAP MODEL BASED ON LIST PRINCIPLES
  
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

#include "swap.h"



void SwapInitialize(int rows, int cols, DiskBlock swap[rows][cols], SwapPointers listas[rows]){

	for(int i=0; i<rows; i++){
		listas[i].first = 0;
		listas[i].last  = 0;
	}

	for(int i=0; i<rows; i++)
		for(int j=0; j<cols; j++){
			swap[i][j].file    = -1;
			swap[i][j].segment = -1;
		}

}

bool SendToSwap(DiskBlock *swap, DiskBlock b, SwapPointers *lista, int cols){
	bool isfull = false;

	if (lista->last >= cols)
		isfull = true;
	else{
		swap[lista->last] = b;
		lista->last ++;
	}

	return isfull;

}


bool SwapToMemory(DiskBlock *swap, DiskBlock *b, SwapPointers *lista){
	bool isempty = false;
  
	if(lista->first == lista->last)
		isempty = true;
	else{
		*b = swap[lista->first];
		for(int i=lista->first; i<lista->last-1; i++)
			swap[i] = swap[i+1];
		lista->last --;
	}

	return isempty;

}

