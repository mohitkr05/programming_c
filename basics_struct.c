/*
 * struct.c : To understand the working, memory allocation of structs
 *
 * Copyright 2018 mohit
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

#include <stdio.h>

	struct fraction {
		int numerator;
		int denominator;

	};

int main () {



	struct fraction pi;

	pi.numerator = 22;
	pi.denominator = 7;

	/* Let us check the memory location of all the variables */
	printf("%p \n" ,&pi.numerator);
	printf("%p \n" ,&pi.denominator);
	printf("%p \n" ,&pi); /* Should be same as the memory location of the numerator */

	/*Alternate way */

	/* memory location of the pi struct */
	printf("%d \n" , (&pi)[0].numerator);



}
