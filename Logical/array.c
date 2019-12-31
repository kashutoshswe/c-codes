/*
 * Author : Ashutosh Kumar
 * Last Modified : 17th August
 * Description : Function file to implement the functions
*/

#include "array.h"
#include <malloc.h>
#include <error.h>

/* create() - Allocates requested size of memory. If successful returns the address of memory block allocated
 * and also stores it in array variable along with size. On error, returns NULL.
 * Input Parameters : size : Array Size
 * Return : if pointer goes beyond the array memory size returns NULL
 *          else returns pointer pointing to the base address of the calling function
 *
 */

int* create(ARRAY* aname, short int size)
{
    int* pointerOf=(int*)malloc(size*sizeof(int));

    if(pointerOf == NULL)
    {
        //setenv("errno=ERROR_");
        putenv("");

        return NULL;
    }
    aname->base=pointerOf;
    return pointerOf;
}

/* store() - Stores a value at the specified index. If successful returns 0.
 * The function checks for bounds and on error, returns -1.
 * pointer ++ = which means it moves to next address in the array
 * Input Parameters : *aname- A pointer to array structure , index - of short int type , value - data which is to be inserted
 * Return : if pointer goes beyond the array memory size returns ERROR else returns TRUE if data is stored
 *
 */

int store(ARRAY* aname, int value, short int index)
{
    int* pointerToStore = (aname->base) + index;
    if(pointerToStore > ((aname->base)+((aname->size)-1)) || pointerToStore < (aname->base))
        return ERROR;

    *(pointerToStore)= value;
    return TRUE;
}

/* read() - Returns a value at the specified index.
 * Input Parameters : aname- An array Structure, index - of short int type
 * Return : ERROR in case of out of index access or returns value at the given index when valid
*/

int read(ARRAY aname, short int index)
{
    int* pointerToValue = aname.base+index;
    if(pointerToValue == NULL || (pointerToValue > ((aname.base)+((aname.size)-1)))  ||  pointerToValue < (aname.base))
        return ERROR;

    return *(pointerToValue);
}


/*Function to print the values of the array
 *  Input Parameters : aname- An array Structure
 *  Prints the Array's elements
 *  The function is mainly designed for testing purpose
*/

void printArray(ARRAY aname)
{
    for(int i=0;i<aname.size;i++)
    {
        printf(" Values : %d\n",*(aname.base+i));
    }
}
