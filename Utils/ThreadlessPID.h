/*
 * ThreadlessPID.h
 *
 *  Created on: Nov 21, 2013
 *      Author: msto
 */

#ifndef THREADLESSPID_H_
#define THREADLESSPID_H_

class ThreadlessPID {
public:
	ThreadlessPID(double p, double i=0, double d=0, double f=0);
	void setConstants(double p, double i=0, double d=0, double f=0);

	double calc(double target, double input);

	void reset();
private:
	double k_p;
	double k_i;
	double k_d;
	double k_f;

	double integral;
	double lerror;
	double ltime;
};

#endif /* THREADLESSPID_H_ */
