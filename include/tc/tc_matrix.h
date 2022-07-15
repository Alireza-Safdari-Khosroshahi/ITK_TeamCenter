// Copyright 2020 Siemens Digital Industries Software
// ==================================================
// Copyright 2012.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2020 Siemens Digital Industries Software
// ==================================================
// File Description:
// tc_matrix.h contains declarations to some of the commonly
// used matrix operations like matrix multiply, transpose,
// transformation of a point and matrix comparison.
//
// ==================================================

#ifndef TEAMCENTER_TC_MATRIX_H
#define TEAMCENTER_TC_MATRIX_H

#include <tc/libtc_exports.h>
 
/**
    @defgroup TC_MATRIX Teamcenter Matrices
    @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/**
 * Fixes up the rotational elements of the 4x4 matrix.
 * If any elements are within tolerance of 0.0, 1.0, or -1.0, set that element
 * exactly to that number.
 * Also makes sure the matrix is orthonormal.
 * @param[in,out] mx Input matrix for the fix up
 * @return If the matrix canot be made orthonormal, returns ITK_internal_error, otherwise returns ITK_ok
 */
extern TC_API int TC_matrix_fixup (
  double        mx[16]  /**< (I/O) input matrix for the fix up, also returns the output matrix */
  );


/**
 * Determines if two matrices are identical within tolerance
 * @param[in]  mx1 Input matrix 1 
 * @param[in]  mx2 Input matrix 2
 * @param[out] eq true if matrices are equal, false if they are not
 * @return ITK_ok on success, on error returns ITK_internal_error
 */
extern TC_API int TC_matrix_is_equal(
  const double  mx1[16],      /**< (I) Input matrix 1 */
  const double  mx2[16],      /**< (I) Input matrix 2 */
  bool*         eq            /**< (O) true if matrices are equal, false if they are not */
  );
                            
/**
 * Multiplies two 4 by 4 matrices.
 * @param[in]  mx1       Input matrix 1
 * @param[in]  mx2       Input matrix 2
 * @param[out] mx_result Resulting Matrix after multiplication of mx1 and mx2
 * @return ITK_ok on success, on error returns ITK_internal_error
 */
extern TC_API int TC_matrix_multiply(
  const double        mx1[16],         /**< (I) Input matrix 1 */
  const double        mx2[16],         /**< (I) Input matrix 2 */
  double            **mx_result        /**< (OF) 16 Resulting Matrix after multiplication of mx1 and mx2 */
  );

/**
 * Multiplies a point though a 4 by 4 matrix. Return the resulting point.
 * @param[in]  point      Coordinates of the point
 * @param[in]  matrix     Transformation matrix with which the point is multiplied
 * @param[out] mx_result  Coordinates of the new (transformed) point
 * @return ITK_ok on success, on error returns ITK_internal_error
 */
extern TC_API int TC_matrix_point_multiply(
  const double      point[3],         /**< (I) coordinates of the point */
  const double      matrix[16],       /**< (I) transformation matrix with which the point is multiplied */
  double          **mx_result         /**< (OF) 3 coordinates of the new (transformed) point */
  );


/**
 * Transposes a 4 by 4 matrix.
 * @param[in]  mx            Input matrix that needs to be transposed
 * @param[out] mx_transposed Transposed matrix
 * @return ITK_ok on success, on error returns ITK_internal_error
 */
extern TC_API int TC_matrix_transpose(
  const double          mx[16],                 /**< (I) Input matrix that needs to be transposed */
  double              **mx_transposed           /**< (OF) 16 Transposed matrix */
  );

/**
 * Computes Euler Angles (theta) from 4x4 matrix
 * @param[in] mx             Input matix for which Euler angles are needed.
 * @param[in] precision      double precision
 * @param[out] euler_angles   double vector of size 3 representing the Euler Angles
 * @returns 
 *   <ul>
 *   <li>#ITK_ok on success
 *   <li>#ITK_internal_error on error.
 *   </ul> 
 */
extern TC_API int TC_matrix_euler_angle(
  const double          mx[16],
  const double          precision,
  double                euler_angles[3]
  );
#ifdef __cplusplus
}
#endif

/**
   @}
 */
#include <tc/libtc_undef.h>
#endif
