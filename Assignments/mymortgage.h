/*
 -------------------------------------
 File:    mymortgage.h
 Project: alix4667_a01
 file description
 -------------------------------------
 Author:  Suleman Ali
 ID:      169044667
 Email:   alix4667@mylaurier.ca
 Version  2024-01-20
 -------------------------------------
 */

#ifndef MYMORTGAGE_H_
#define MYMORTGAGE_H_

#include <stdio.h>

/**
 * Compute the monthly payment of a given mortgage principal, annual interest rate (%), and mortgage years.
 */
float monthly_payment(float principal_amount, float annual_interest_rate,
		int years);

/**
 * Determine the total payment of loan given mortgage principal, annual interest rate (%), and mortgage years.
 */
float total_payment(float principal_amount, float annual_interest_rate,
		int years);

/**
 * Determine the total interest paid for the loan given mortgage principal, annual interest rate (%), and mortgage years.
 */
float total_interest(float principal_amount, float annual_interest_rate,
		int years);

#endif /* MYMORTGAGE_H_ */

