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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_IMANIDCREATOR_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_IMANIDCREATOR_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API ImanIDCreator : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    int get_digits();
    const Teamcenter::Soa::Client::StringVector& get_sequence();
    const Teamcenter::Soa::Client::StringVector& get_start_value();
    const Teamcenter::Soa::Client::IntVector& get_value_type();
    const std::string& get_next_value();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ImanIDCreator")

   virtual ~ImanIDCreator();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
