/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/



#ifndef TEAMCENTER_SOA_CLIENT_LOV_HXX
#define TEAMCENTER_SOA_CLIENT_LOV_HXX

#include <string>
#include <vector>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/LovInfo.hxx>
#include <teamcenter/soa/client/Chooseable.hxx>



#include <teamcenter/soa/client/SoaClientMngdExports.h>


namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {



class TCSOACLIENTMNGD_API Lov: public Chooseable
{
public:
     enum Style
     {

       /** A simple list of values  */
       Standard,


       /**
        * An interdependent list of values, where each value has a nested list of values.
        * A list of states would have a list of cities for each state. For this style of LOV the
        * getDependantProperties method will have a list of property names that are associated with
        * each level of the LOV.
        */
       Interdependent,


       /**
        * Same as the Interdependent, but only the last level of values is associated with the
        * current property, the getDependantProperties list is empty.
        **/
       Hierarchical,


       /**
        *  This is similar to Interdependent; however levels 2-N will only have a single value.
        *  When the user selects a value from the first level LOV, the system can then fill property
        *  values for all levels.
        */
       Coordinated,

       /**
        * The nested layers of a Interdependent or Coordinated LOV may have a description attached.
        * The getDependantSytles for the L+1 layer may be 'Description', if so the LovValue.getDescription
        * should be assigned to the L+1 getDependantProperties.
        */
       Description
     };





    virtual ~Lov();
    SOA_CLASS_NEW_OPERATORS

   /**
    * @return The style of the LOV, Standard, Interdependent, Hierarchical, Coordinated or Description
    */
    virtual Style getStyle()=0;

   /**
    * @return  List of PropertyDescriptors that an Interdependent or Coordinated LOV is dependent on.
    */
    virtual std::vector<std::string> getDependantProperties()=0;


   /**
    * @return  List of Styles for each level of an Interdependent or Coordinated LOV.
    */
    virtual std::vector<Lov::Style> getDependantStyles()=0;

   /**
    * @return The LOV UID
    */
    virtual std::string getUid()=0;


   /**
    * @return  The specifier describing this LOV.
    */
    virtual int getSpecifier()=0;


   /**
    * Get the LOV Info.<br>
    *
    * <b>NOTICE:</b> This method may result in a server trip. When Type Meta data is pulled from
    * the server (default behavior) this will result in server trip to get the data that makes up the LovInfo.
    * When configured with a Client Meta Model Cache the LovInfo is returned without a server trip.
    *
    * @return   The LOV Info which has details about this List of Values
    */
    virtual LovInfo* getLovInfo()=0;


protected:

    Lov();

};




}}}//end namespace

#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif

