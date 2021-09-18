/*
  DISK MODEL BASED ON STACK PRINCIPLES
  
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

#ifndef DISK_H 
#define DISK_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include "tokenizer.h"


#define DISKPATH "dataset/disco.txt"


typedef struct DiskBlock{
	int file;
	int segment;
}DiskBlock;

typedef struct DiskPointers{
	int top;
	int base;
}DiskPointers;

typedef struct DiskParams{
	int maxrows;
	int maxcols;
}DiskParams;


void DiskShowFile(DiskBlock *file, DiskPointers *p, int fid);
void DiskGetParameters(DiskParams *p);
void DiskInitialize(int rows, int cols, DiskBlock blocks[rows][cols], DiskPointers pilha[rows]);

void Push(DiskBlock *file, DiskPointers *p, int cols, DiskBlock data);
bool Pop(DiskBlock *file, DiskPointers *p, int cols, DiskBlock *data);

void DiskLoad(int rows, int cols, DiskBlock blocks[rows][cols], DiskPointers pilha[rows]);
bool DiskLookAt(DiskBlock *file, int cols, DiskBlock data);

#endif










