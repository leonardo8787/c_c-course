/*
  MEMORY MODEL BASED ON QUEUE PRINCIPLES
  
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

#ifndef MEMORY_H 
#define MEMORY_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include "tokenizer.h"
#include "disk.h"

#define MEMORYMAXCOLS 5
#define MEMORYPATH "dataset/processos.txt"

typedef struct MemoryParams{
	int maxrows;
	int maxcols;
}MemoryParams;


typedef struct MemoryPointers{
	int first;
	int last;
}MemoryPointers;


void MemoryGetParameters(MemoryParams *p);
void MemoryInitialize(int rows, DiskBlock blocks[rows][MEMORYMAXCOLS], MemoryPointers filas[rows]);
bool MemoryQueue(DiskBlock *mem, DiskBlock b, MemoryPointers *fila);
bool MemoryDequeue(DiskBlock *mem, DiskBlock *b, MemoryPointers *fila);
bool MemoryLookAt(int rows, DiskBlock blocks[rows][MEMORYMAXCOLS], DiskBlock b);

#endif






