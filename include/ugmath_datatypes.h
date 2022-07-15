/*HEAD UGMATH_DATATYPES HHH UGMATH */
/*
*===============================================================================
*
*           Copyright (c) 1999 Unigraphics Solutions Inc.
*                        Unpublished - All rights reserved
*
*===============================================================================
*
*   Header file defining the data types used by the vector math package.
*
*===============================================================================
*   Date       Name
* 17-Aug-1999  Dennis Lavarini
27-Aug-2001  Allan Hansen            Add 2D and 3D Boxes to package
12-Sep-2003  Radhika Vurputoor       Added INT3
*$HISTORY$
*===============================================================================
*/

#ifndef UGMATH_DATATYPES_H_INCLUDED
#define UGMATH_DATATYPES_H_INCLUDED

/* 
 * Definition for array of 3 integers
 */
typedef  struct INT3_s
{
    int      i3[3];
} INT3_t, *INT3_p_t;

typedef const INT3_t  INT3_c_t, *INT3_pc_t;

#define INT3_0(p)           ((p)->i3[0])
#define INT3_1(p)           ((p)->i3[1])
#define INT3_2(p)           ((p)->i3[2])

/*
*  Definition for 2-D vector
*/
typedef struct VEC2_s
{
    double  v2[2];
} VEC2_t, *VEC2_p_t;

typedef const VEC2_t   VEC2_c_t, *VEC2_pc_t;

#define VEC2_X(u)           ((u)->v2[0])
#define VEC2_Y(u)           ((u)->v2[1])

/*
*  Definition for 3-D vector
*/
typedef struct VEC3_s
{
    double  v3[3];
} VEC3_t, *VEC3_p_t;

typedef const VEC3_t   VEC3_c_t, *VEC3_pc_t;

#define VEC3_X(u)           ((u)->v3[0])
#define VEC3_Y(u)           ((u)->v3[1])
#define VEC3_Z(u)           ((u)->v3[2])

/*
*  Definition for 2-D point
*/
typedef struct PNT2_s
{
    double  p2[2];
} PNT2_t, *PNT2_p_t;

typedef const PNT2_t   PNT2_c_t, *PNT2_pc_t;

#define PNT2_X(p)           ((p)->p2[0])
#define PNT2_Y(p)           ((p)->p2[1])

/*
*  Definition for 3-D point
*/
typedef struct PNT3_s
{
    double  p3[3];
} PNT3_t, *PNT3_p_t;

typedef const PNT3_t   PNT3_c_t, *PNT3_pc_t;

#define PNT3_X(p)          ((p)->p3[0])
#define PNT3_Y(p)          ((p)->p3[1])
#define PNT3_Z(p)          ((p)->p3[2])

/*
*  Definition for 4-D point
*/
typedef struct PNT4_s
{
    double  p4[4];
} PNT4_t, *PNT4_p_t;

typedef const PNT4_t   PNT4_c_t, *PNT4_pc_t;

#define PNT4_X(p)          ((p)->p4[0])
#define PNT4_Y(p)          ((p)->p4[1])
#define PNT4_Z(p)          ((p)->p4[2])
#define PNT4_W(p)          ((p)->p4[3])

/*
*  Definition for 2 X 2 matrix
*/
typedef struct MTX2_s
{
    double  m2[4];
} MTX2_t, *MTX2_p_t;

typedef const MTX2_t   MTX2_c_t, *MTX2_pc_t;

/*
*  Definition for 3 X 3 matrix
*/
typedef struct MTX3_s
{
    double  m3[9];
} MTX3_t, *MTX3_p_t;

typedef const MTX3_t   MTX3_c_t, *MTX3_pc_t;

/*
*  Definition for 4 X 4 matrix
*/
typedef struct MTX4_s
{
    double  m4[16];
} MTX4_t, *MTX4_p_t;

typedef const MTX4_t   MTX4_c_t, *MTX4_pc_t;

/*
*  Definition for 3-D plane
*/
typedef struct PLN3_s
{
    PNT3_t  origin;
    VEC3_t  normal;
} PLN3_t, *PLN3_p_t;

typedef const PLN3_t   PLN3_c_t, *PLN3_pc_t;

/*
*  Definition for 3-D coordinate system
*/
typedef struct CSYS_s
{
    PNT3_t  origin;
    MTX3_t  matrix;
} CSYS_t, *CSYS_p_t;

typedef const CSYS_t   CSYS_c_t, *CSYS_pc_t;

/*
*  Definition for 2-d box
*/
typedef union
{
    double a[4];
    struct
    {
        double xmin;
        double xmax;
        double ymin;
        double ymax;
    } n;
} BOX2_t, *BOX2_p_t;

typedef const BOX2_t BOX2_c_t, *BOX2_pc_t;

#define BOX2_XMIN(p)          ((p)->n.xmin)
#define BOX2_XMAX(p)          ((p)->n.xmax)
#define BOX2_YMIN(p)          ((p)->n.ymin)
#define BOX2_YMAX(p)          ((p)->n.ymax)

/*
*  Definition for 3-d box
*/
typedef union BOX3_s
{
    double a[6];
    struct
    {
        double xmin;
        double xmax;
        double ymin;
        double ymax;
        double zmin;
        double zmax;
    } n;
} BOX3_t, *BOX3_p_t;

typedef const BOX3_t BOX3_c_t, *BOX3_pc_t;

#define BOX3_XMIN(p)          ((p)->n.xmin)
#define BOX3_XMAX(p)          ((p)->n.xmax)
#define BOX3_YMIN(p)          ((p)->n.ymin)
#define BOX3_YMAX(p)          ((p)->n.ymax)
#define BOX3_ZMIN(p)          ((p)->n.zmin)
#define BOX3_ZMAX(p)          ((p)->n.zmax)

#endif  /* UGMATH_DATATYPES_H_INCLUDED */
