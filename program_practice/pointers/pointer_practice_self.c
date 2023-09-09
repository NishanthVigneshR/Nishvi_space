#include <stdio.h>
#include <stdlib.h>

int main() {
	int var1 = 0;
	int * ptr1  =  NULL;    // NULL pointer, don't dereference. * (NULL) --> * (0) --> nothing will be there n will crash.
	
	var1 = 10;
	ptr1 = &var1;
	printf("Value at address stored by ptr1 : %d\n", *ptr1);   // * (address of var1) --> 10 will be printed.

	*ptr1 = 11;
	printf("Value of var1 after changing at ptr: %d\n", var1);    // We changed value at memory address of var1 as 11. 
						 		      //Now, 11 will be output.

	printf("Address stored by ptr: %x %u\n", ptr1, ptr1); // Here, I'm printing address stored at pointer ptr1. 
							      //In hexa and unsigned int format.

	printf("Address of ptr1: %x\n", &ptr1);   // Printing address of pointer ptr1.
	printf("size of pointer : %lu\n", sizeof(ptr1)); // Size of pointer is 4 bytes or 8 bytes (32-bit or 64-bit compiler).
							 // Even though it's holding address of structure with 50 bytes data.
							 // Pointer will hold just it's memory address.

	printf("Increment :%d %d\n", (*ptr1)++, ++(*ptr1)); //We'll fetch value at memory hold by pointer ptr. 
							    //Then we'll increment. Output will be 12 12.

	printf("Decrement : %d %d\n", --(*ptr1), (*ptr1)--);   //We'll fetch value first and we'll decrement. 
							       //Output will be 11 13.
	
Arrays_and_pointers:
Pointers_arithmetic:
	/* Let's take array and will check pointer arithmetic */

	int array1[] = {1,3,5,7,9,11,-1,0};
	int * ptr2;  // This is Wild pointer, Address at ptr2 can hold any memory address. So, not recommended.
		   // We can avoid by initialising it with NULL, dynamic mem allocation or assigning known variable address.
	
	/* Here, array1 by itself is an pointer. It holds memory address of starting memory address of array */
	printf("Address of array1 : %x\n", array1);  //Array1 is constant pointer.
	printf("Value at array1 - %d and 1st index of array - %d. Both will be same\n", *array1, array1[0]);

	/* Now, initialize pointer ptr2 with address of array1 */
	ptr2 = array1;  //or ptr2 = &array1[0]

	/* Let's do pointer arithmetic */

	printf("Address of ptr2 - %x , address at ptr2 - %x\n", &ptr2, ptr2);
	printf("%d %d %d\n", (*ptr2)-5,*(ptr2+4), (*ptr2)+4); // -4 9 5.
	// Here, initially ptr is holding array[0] address.
	// First, based on precedence, flow will be right to left.
	// 1] (*ptr2)+4 will be executed first. (1)+4 --> 5
	// 2] *(ptr2+4), Here, pointer ptr2 will be increment 4 times of it's datatype size.
	// That is it'll fetch value at address array1[4]. Output will be 9.
	// 3] *(ptr2)-5, ptr2 still will be pointing to array[0]. We are incrementing addresses, 
	// but nowhere we re-initialized ptr2 with other addresses. Thus, *(1) - 5 --> -4.

	ptr2 = ptr2+3;  // Now, ptr2 is re-wriiten with new address. address of array[0] +3 --> address of array1[3].
	printf("Address of ptr2 - %x , address at ptr2 - %x\n", &ptr2, ptr2);
	printf("After addition : Value at ptr2 - %d\n", *ptr2);  // --> output - 7

	ptr2 = ptr2-2;  // ptr2 will be assigned with new address. Address of array1[3] - 2 --> Address of array1[1].
	printf("Address of ptr2 - %x , address at ptr2 - %x\n", &ptr2, ptr2);
        printf("After subtraction : Value at ptr2 - %d\n", *ptr2); // --> output - 3.

	//now, pointer ptr2 is pointing to array[1].//
	printf("Increment : %d %d %d %d\n", (*ptr2)++, *ptr2++, ++(*ptr2), *++ptr2);  // 7 6 6 5
	//Right to left. 1] pre-increment *++ptr2 --> p will be moved to array[2] and that value will be printed. --> 5.
	// 2] ++ (*ptr2) --> ++(Value at address at p) --> ++(5)  --> 6.
	// 3] *ptr2++ --> Post-increment. Pointer will hold address of array[3]. But, it's post-increment. Thus, 6 is output.
	// 4] (*ptr2)++ --> Now, pointer holds address of array[3]. (Value at address at ptr2)++ --> (7)++ --> Output 7.
	

	/* Addition between two pointers is not possible.
	 * But, subtraction between two pointers is possible.
	 * Subtraction between pointers won't return memory address difference. 
	 * It'll return number of elements present between those two memory address
	 */

	int *ptr3 = array1;
	int* ptr4 = &array1[3];
	printf("Address at ptr4 - %x, Address ar ptr3 - %x. Performing subtraction b/w two pointers\n", ptr4, ptr3);

	unsigned long diff =  ptr4 - ptr3;  // assume 1012 -1000 --> 12 / (sizeof(datatype)) --> 1012 / 4 --> 3.
	printf("After subtraction, diff is %lu\n", diff);  // 3 will be output.

void_pointer:
	/* 
	 * Consider we are having three variables with datatypes int, float and char.
	 * Incase, if we want to store address of these variables. We need to declare three pointers.
	 * This drawback can be avoided by using void pointer.
	 *
	 * E.g -> void * pointer_name;
	 */
	int   int_var   = 5;
	float float_var = 11.1;
	char char_var   = 'a';

	//int * int_ptr = &int_var;
	//float *float_ptr = &float_var;
	//char* char_val = &char_var;

	/* In above lines, we are using three pointer variables to store addresses of respective datatype
	 * It can be avoided by using void pointer. But, one important thing is
	 * while dereferencing the address stored in void pointer, compiler won't be aware about no.of.bytes
	 * to be allocated. So, 'typecast' will comes into rescue.
	 * By doing typecast, compiler will get to know about no.of.bytes to be allocated
	 */

	 void * void_ptr = NULL;

	 void_ptr = &int_var;
	 printf("int value stored at void ptr is %d\n", *(int *)void_ptr);

	 void_ptr = &float_var;
	 printf("float value stored at void ptr is %f\n", *(float *)void_ptr);

	 void_ptr = &char_var;
	 printf("char value stored at void ptr is %c\n", *(char *)void_ptr);
	

NULL_pointer:
	/*
	 * while declaring pointer, if we are not defining it with some memory address, it will store some
	 * garbage memory address. While dereferencing that pointer, we may end up in undefined behavoiur.
	 * Either we'll get some valid value or we'll fetch address which is used by someother process or program will crash.
	 * So, always initialize pointer with NULL value
	 */
	 int * ptrr = NULL; //if you dereference it'll be *(NULL) --> *(0) i,e. 0 is special memory address

	 // All the pointers initialized with NULL, points to memory address 0.
	
Wild_pointer:
	/* Declaring pointer without initializing it with NULL or some valid memory address known as wild pointer */
	 int *wild_ptr;  // This is wild pointer

	/*Wild pointer can be avoided by initializing it with NULL or some valid memory address or dynamic memory allocation*/

Dangling_pointer:
	// Consider below scenario.
	int * ptr5 = NULL;
	ptr5 = (int *)malloc (sizeof(int)); //Here, 4 bytes of memory from heap section, will be allocated to ptr3. 

	*ptr5 = 4;
	printf("Dynamically allocated memory for ptr5 and address is %x, value is %d\n", ptr5, *ptr5);

	free(ptr5);  // Here, I'm freeing the ptr3. So, the address hold by pointer ptr3 will be freed.
		     // The memory used in heap section will be freed now. But, still ptr3 will be holding that address.
		     // So, if you dereference ptr3 after free, we may get correct output for sometime.
		     // But, it's not recommended and should be avoided with atmost care.
	
	/* The below line is not recommended, see the output of one of the execution
	 *
	 * Output : Dynamically allocated memory for ptr5 and address is 21b96b0, value is 4
	 *	    Freed ptr5 and trying to dereference it, address is 21b96b0, value is 8633
	 */

	//printf("Freed ptr5 and trying to dereference it, address is %x, value is %d\n", ptr5, *ptr5);
	
	// This kind of pointers are known as dangling pointer. Like this, function return and local scope initialization also	      // will leads to dangling pointer.
	
	/* We can avoid this by initializing the pointer with NULL value as soon as freeing the same */

	ptr5 = NULL;  // This will resolve the dangle pointer pointer.

Pointer_to_pointer:
	/*
	 * If we want to store address of variable, we will use single pointer.
	 * What if we want to store address of pointer? Here, we should use pointer to pointer.
	 */

	int int_var1 = 10;
	int * sint_ptr = &int_var1;
	int **dint_ptr = &sint_ptr;   // Here, address of sint_ptr will be stored in dint_ptr.

	printf("Address of sint_ptr- %x , address at sint_ptr- %x, value at sint_ptr- %d\n", &sint_ptr, sint_ptr, *sint_ptr);
	//Now, dereference double pointer.
	printf("Address of dint_ptr- %x, Address at dint_ptr- %x, value at dint_ptr- %d\n", &dint_ptr, dint_ptr, **dint_ptr);

	/* Output : 
	 * Address of sint_ptr- f2ce1d60 , address at sint_ptr- f2ce1d68, value at sint_ptr- 10
	 * Address of dint_ptr- f2ce1d58, Address at dint_ptr- f2ce1d60, value at dint_ptr- 10
	 */

Pointer_to_constant:

	//Assume, we're using constant variable. So, the param will be read-only parameter.
	const int const_var = 3;
	
	//const_var = 5;  --> This line will throw error. Because, we're overwriting read-only parameter.
	
	/* Error : 
	 * pointer_practice_self.c:185:19: error: assignment of read-only variable ‘const_var’
	 * 185 |         const_var = 5;
	 */        
	 
	// Now, I need to create ptr with datatype const int.
	const int * ptr6 = &const_var;
	printf("Address of const_ptr - %x, address at const_ptr - %x, value at const_ptr - %d\n",
			&ptr6, ptr6, *ptr6);
	//(*ptr6)++;

	/* Due to above line, We will get compilation error. Because, ptr6 is holding address of constant variable.
	 * So, incrementing that read-only location value will throw below error.
	 *
	 * Error:
	 * pointer_practice_self.c:197:16: error: increment of read-only location ‘*ptr6’
	 *  197 |         (*ptr6)++;
	 */

Constant_pointer:
	/* Now, we need to initialize the pointer which will store fixed memory location.
	 * The address stored by that pointer can't be modified (or) changed. But, we can modify the value present
	 * in that location. We can achieve that by declaring like below.
	 *
	 * Syntax : datatype * const pointer_name;   --> Let's try.
	 */

	int array2[] = {2,3,4};
	int * const ptr7 = array2;

	printf("Address of ptr7 - %x, address at ptr7 - %x, value at ptr7 - %d\n", &ptr7, ptr7, *ptr7);
	
	//*ptr7++;
	/* Above line will throw below error.
	 * pointer_practice_self.c:219:14: error: increment of read-only variable ‘ptr7’
	 *  219 |         *ptr7++;
	 */
constant_pointer_to_constant:
	const int const_variable = 10;
	const int * const ptr8 =  &const_variable;
	/* The memory address stored at ptr8 can't be changed. It'll be fixed and
	 * even the value at that memory address can't be changed, that one also will be fixed.
	 */
}
