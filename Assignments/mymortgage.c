/*
 -------------------------------------
 File:    mymortgage.c
 Project: alix4667_a01
 file description
 -------------------------------------
 Author:  Suleman Ali
 ID:      169044667
 Email:   alix4667@mylaurier.ca
 Version  2024-01-20
 -------------------------------------
 */

#include "mymortgage.h"
#include <math.h> // Required for pow function

float monthly_payment(float principal_amount, float annual_interest_rate,
		int years) {
	float monthly_rate = annual_interest_rate / 100 / 12;
	int total_number_of_payments = years * 12;
	// If interest rate is 0, then the formula changes as the rate doesn't apply.
	if (annual_interest_rate == 0) {
		return principal_amount / total_number_of_payments;
	}
	float payment = principal_amount * monthly_rate
			* pow(1 + monthly_rate, total_number_of_payments)
			/ (pow(1 + monthly_rate, total_number_of_payments) - 1);
	return payment;
}

float total_payment(float principal_amount, float annual_interest_rate,
		int years) {
	float monthly_payment_amount = monthly_payment(principal_amount,
			annual_interest_rate, years);
	return monthly_payment_amount * years * 12;
}

float total_interest(float principal_amount, float annual_interest_rate,
		int years) {
	float total_pay = total_payment(principal_amount, annual_interest_rate,
			years);
	return total_pay - principal_amount;
}
