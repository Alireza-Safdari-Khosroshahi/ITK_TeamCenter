// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.0a_p3
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/


// TAO_IDL - Generated from
// d:\_tao_work\ace_wrappers_dynamic_x64_release_vc10\ace_wrappers\tao\tao_idl\be\be_visitor_union/union_ci.cpp:42

// *************************************************************
// Inline operations for union TcStringValue_u
// *************************************************************

// TAO_IDL - Generated from
// d:\_tao_work\ace_wrappers_dynamic_x64_release_vc10\ace_wrappers\tao\tao_idl\be\be_visitor_union/discriminant_ci.cpp:151

ACE_INLINE
void 
TcStringValue_u::_default ()
{
  this->_reset ();
  this->disc_ = false;
}

// Accessor to set the discriminant.
ACE_INLINE
void
TcStringValue_u::_d ( ::CORBA::Boolean discval)
{
  this->disc_ = discval;
}

// Accessor to get the discriminant.
ACE_INLINE
::CORBA::Boolean
TcStringValue_u::_d (void) const
{
  return this->disc_;
}

// TAO_IDL - Generated from
// d:\_tao_work\ace_wrappers_dynamic_x64_release_vc10\ace_wrappers\tao\tao_idl\be\be_visitor_union_branch/public_ci.cpp:789

/// Accessor to set the member.
ACE_INLINE
void
TcStringValue_u::string_value (const TcString_t &val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = true;
  ACE_NEW (
      this->u_.string_value_,
      TcString_t (val)
    );
}

/// Readonly get method.
ACE_INLINE
const TcString_t &
TcStringValue_u::string_value (void) const
{
  return *this->u_.string_value_;
}

/// Read/write get method.
ACE_INLINE
TcString_t &
TcStringValue_u::string_value (void)
{
  return *this->u_.string_value_;
}

