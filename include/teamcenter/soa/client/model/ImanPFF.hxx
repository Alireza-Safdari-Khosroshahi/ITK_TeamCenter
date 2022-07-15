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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_IMANPFF_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_IMANPFF_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_application_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API ImanPFF : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_PFF_name();
    const std::string& get_PFF_desc();
    const std::string& get_PFF_class();
    const Teamcenter::Soa::Client::StringVector& get_PFF_clauses();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ImanPFF")

   virtual ~ImanPFF();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
