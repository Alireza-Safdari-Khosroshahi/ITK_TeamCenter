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

#ifndef  SOA_CLIENT_MODEL_APPMODELOBJECTFACTORY_HXX
#define  SOA_CLIENT_MODEL_APPMODELOBJECTFACTORY_HXX

#include <string>
#include <map>

#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ModelObjectFactory.hxx>

#include <teamcenter/soa/client/model/AppmodelMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {



class TCSOAAPPMODELMODELMNGD_API AppmodelObjectFactory
{
public:


    static std::map< std::string, Teamcenter::Soa::Client::ModelObjectFactory* >* init();
private:

    static void init0( std::map< std::string, Teamcenter::Soa::Client::ModelObjectFactory* >& factoryMap );


};

}}}} //end namespace
#include <teamcenter/soa/client/model/AppmodelMngd_undef.h>


#endif
