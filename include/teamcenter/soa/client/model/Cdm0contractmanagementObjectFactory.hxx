/* 
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2012
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

 ==================================================

  Auto-generated source from Teamcenter Data Model.
                 DO NOT EDIT

 ==================================================
*/

#ifndef  SOA_CLIENT_MODEL_CDM0CONTRACTMANAGEMENTOBJECTFACTORY_HXX
#define  SOA_CLIENT_MODEL_CDM0CONTRACTMANAGEMENTOBJECTFACTORY_HXX

#include <string>
#include <map>

#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ModelObjectFactory.hxx>

#include <teamcenter/soa/client/model/Cdm0contractmanagementMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {



class TCSOACDM0CONTRACTMANAGEMENTMODELMNGD_API Cdm0contractmanagementObjectFactory
{
public:


    static std::map< std::string, Teamcenter::Soa::Client::ModelObjectFactory* >* init();
private:

    static void init0( std::map< std::string, Teamcenter::Soa::Client::ModelObjectFactory* >& factoryMap );


};

}}}} //end namespace
#include <teamcenter/soa/client/model/Cdm0contractmanagementMngd_undef.h>


#endif
