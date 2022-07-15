/*HEAD EQ HHH UGMATH */
/*
*===============================================================================
*
*             Copyright (c) 1993-2001 Unigraphics Solutions Inc.
*                        Unpublished - All rights reserved
*
*===============================================================================
*
*   Header file defining macros used to detected equality between scalars
*   of double or FREAL data type. NOTE: there is a fortran insert file eq.ins
*   if you make changes here, check eq.ins to see if changes are required there.
*
*===============================================================================
*   Date       Name
* 17-Aug-1993  Dennis Lavarini
* 06-Jan-1994  Dennis Lavarini    Add hooks to part/system specific tolerances
* 09-Mar-1994  Keith Hafen	  Add EQ_MAX_DBL and EQ_MIN_DBL tolerances
* 15-Mar-1996  William Vittitow   Add EQ_is_finite
* 13-Feb-1997  Jack Marr          Allow EQ_is_equal to work with tol=0.0
* 17-Sep-1998  Reger              Enforce macro signatures under QAZ
* 17-Feb-1999  Reger              Decorate UGMATH prototypes with UGEXPORT;
*                                 include 'unidefs.h' for 'UGEXPORT'
* 18-Aug-1999  Lavarini           Replace UGEXPORT with UGMATHEXPORT
*                                 Move to UGMATH
* 18-Oct-1999  Lavarini           Allow EQ_is_zero to work with tol=0.0
* 08-Dec-2000  Jim Lyles          Added EQ_is_eq, EQ_is_ne, EQ_is_2tol_eq, and
*                                 EQ_is_2tol_ne.
$HISTORY$
*
*===============================================================================
*
*   In the following macro definitions, these conventions are used:
*      Inputs:
*            s, t, and tol are scalars of data type double
*            pos_tol and neg_tol are also scalars of data type double
*
*      Outputs:
*            There is no data type output
*
*      Macro                   Action             Description
*  EQ_TOL_NUMBER           (function call)   Return the part's numerical tol
*  EQ_TOL_LENGTH           (function call)   Return the part's length tol
*  EQ_TOL_LENGTH_SQ        (function call)   Return the part's length squared
*                                            tol
*  EQ_ask_systol           (1.0e-10)         Return system tolerance
*  EQ_is_equal(s, t, tol)  (abs(s-t) <= tol) Return true if scalars are equal
*  EQ_is_eq(s, t, tol)     (abs(s-t) <= tol) Same as EQ_is_equal
*  EQ_is_ge(s, t, tol)     (s > t - tol)     Return true if s is greater than
*                                            or equal to t
*  EQ_is_gt(s, t, tol)     (s > t + tol)     Return true if s is greater than t
*  EQ_is_le(s, t, tol)     (s < t + tol)     Return true if s is less than or
*                                            equal to t
*  EQ_is_lt(s, t, tol)     (s < t - tol)     Return true if s is less than t
*  EQ_is_ne(s, t, tol)     (abs(s-t) > tol)  Return true if scalars are not
*                                            equal
*  EQ_is_2tol_eq(s, t, pos_tol, neg_tol)            Return true if s is inside
*                          ((s >= t - neg_tol) &&   the range (t - neg_tol)
*                           (s <= t + pos_tol))     through (t + pos_tol)
*  EQ_is_2tol_ne(s, t, pos_tol, neg_tol)            Return true if s is outside
*                          ((s < t - neg_tol) ||    the range (t - neg_tol)
*                           (s > t + pos_tol))      through (t + pos_tol)
*  EQ_is_zero(s, tol)      (abs(s) <= tol)   Return true if scalar is zero
*  EQ_MAX_DBL              (1.0e19)          Maximum number valid for distance
*					     operations.  EQ_MAX_DBL**2 is a 
*					     valid value on all platforms.
*  EQ_MIN_DBL              (1.0e-19)         Minimum number that can be used
*					     as a divisor, EQ_MAX_DBL/EQ_MIN_DBL
*					     is still a valid number on all
*					     platforms.
*  EQ_is_finite(s)         (abs(s) < EQ_MAX_DBL)  Return true if scalar is
*                                            finite on all platforms.
*/

#ifndef EQ_H_INCLUDED
#define EQ_H_INCLUDED

#include <math.h>
#include <libugmath_exports.h>

#define EQ_TOL_NUMBER           (EQ_ask_number_tolerance())
#define EQ_TOL_LENGTH           (EQ_ask_length_tolerance())
#define EQ_TOL_LENGTH_SQ        (EQ_ask_length_squared_tolerance())
#define EQ_MAX_DBL           	(1.0e19)
#define EQ_MIN_DBL           	(1.0e-19)

#define EQ_ask_systol           (1.0e-10)

#ifdef __lint

extern logical EQ_is_equal ( double s , double t , double tol );
extern logical EQ_is_eq ( double s, double t, double tol );
extern logical EQ_is_ge ( double s , double t , double tol );
extern logical EQ_is_gt ( double s , double t , double tol );
extern logical EQ_is_le ( double s , double t , double tol );
extern logical EQ_is_lt ( double s , double t , double tol );
extern logical EQ_is_ne ( double s, double t, double tol );
extern logical EQ_is_2tol_eq ( double s, double t,
                               double pos_tol, double neg_tol );
extern logical EQ_is_2tol_ne ( double s, double t,
                               double pos_tol, double neg_tol );
extern logical EQ_is_zero ( double s , double tol );
extern logical EQ_is_finite ( double s );

#else

#define EQ_is_equal(s, t, tol)  (fabs ((s) - (t)) <= (tol))
#define EQ_is_eq(s, t, tol)     (EQ_is_equal( s, t, tol ))
#define EQ_is_ge(s, t, tol)     ((s) > ((t) - (tol)))
#define EQ_is_gt(s, t, tol)     ((s) > ((t) + (tol)))
#define EQ_is_le(s, t, tol)     ((s) < ((t) + (tol)))
#define EQ_is_lt(s, t, tol)     ((s) < ((t) - (tol)))
#define EQ_is_ne(s, t, tol)     (! EQ_is_equal(s, t, tol))
#define EQ_is_2tol_eq(s, t, pos_tol, neg_tol)               \
                                (EQ_is_ge(s, t, neg_tol) && \
                                 EQ_is_le(s, t, pos_tol))
#define EQ_is_2tol_ne(s, t, pos_tol, neg_tol)                             \
                                (! EQ_is_2tol_eq(s, t, pos_tol, neg_tol))
#define EQ_is_zero(s, tol)      (fabs ((s)) <= (tol))
#define EQ_is_finite(s)         (fabs ((s)) < EQ_MAX_DBL)

#endif

/*
*   Proto-types for the part specific tolerance values
*/
extern UGMATHEXPORT double EQ_ask_number_tolerance (void);
extern UGMATHEXPORT double EQ_ask_length_tolerance (void);
extern UGMATHEXPORT double EQ_ask_length_squared_tolerance (void);

#undef EXPORTLIBRARY

#endif  /* EQ_H_INCLUDED */
