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
// d:\_tao_work\ace_wrappers_dynamic_x64_release_vc10\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ci.cpp:65

ACE_INLINE
TcCorbaServiceGateway::TcCorbaServiceGateway (
    TAO_Stub *objref,
    ::CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc)
  : ::CORBA::Object (objref, _tao_collocated, servant, oc),
    the_TAO_TcCorbaServiceGateway_Proxy_Broker_ (0)
{
  this->TcCorbaServiceGateway_setup_collocation ();
}

ACE_INLINE
TcCorbaServiceGateway::TcCorbaServiceGateway (
    ::IOP::IOR *ior,
    TAO_ORB_Core *oc)
  : ::CORBA::Object (ior, oc)
    , the_TAO_TcCorbaServiceGateway_Proxy_Broker_ (0)
{
}

