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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_IMANQUERY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_IMANQUERY_HXX

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


class TCSOACLIENTMNGD_API ImanQuery : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_query_name();
    const std::string& get_query_desc();
    const std::string& get_query_class();
    const Teamcenter::Soa::Client::StringVector& get_query_clauses();
    const std::string& get_query_uid_name();
    int get_query_flag();
    int get_results_type();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ImanQuery")

   virtual ~ImanQuery();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
