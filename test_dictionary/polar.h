#ifndef H_FOO_POLAR_H
#define H_FOO_POLAR_H

#include <complex>


/** Polar representation of double-complex numbers.
 *
 *  This stores the modulus r and phase phi of such number z,
 *  such that \f$ z(r,\phi) = re^{i\phi} \f$.
 *
 */
class PolarComplex
{
  public:
	/** Converts the complex number to a std::complex<double>
	 *  and returns the result.
	 *
	 *  \note This uses the Euler relation, see equation
	 *        \dictval eqn:euler in section \dictval sec:euler
	 *        in \cite MathOverview.
	 */
	std::complex<double> get_cartesian() const;
};

#endif // H_FOO_POLAR_H
