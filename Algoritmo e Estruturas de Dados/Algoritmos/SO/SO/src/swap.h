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

#ifndef SWAP_H 
#define SWAP_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include "disk.h"

typedef struct SwapPointers{
	int first;
	int last;
}SwapPointers;

typedef struct SwapParams{
	int maxrows;
	int maxcols;
}SwapParams;


void SwapInitialize(int rows, int cols, DiskBlock swap[rows][cols], SwapPointers listas[rows]);
bool SendToSwap(DiskBlock *swap, DiskBlock b, SwapPointers *lista, int cols);
bool SwapToMemory(DiskBlock *swap, DiskBlock *b, SwapPointers *lista);


#endif









