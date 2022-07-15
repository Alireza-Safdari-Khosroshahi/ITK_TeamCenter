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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SAVEDQUERYCRITERIA_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SAVEDQUERYCRITERIA_HXX

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
                class ImanQuery;


class TCSOACLIENTMNGD_API SavedQueryCriteria : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_adhoc_query_class();
    bool get_hierarchical_results();
    Teamcenter::Soa::Common::AutoPtr<ImanQuery> get_saved_query();
    const Teamcenter::Soa::Client::StringVector& get_attribute_names();
    const Teamcenter::Soa::Client::StringVector& get_attribute_values();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SavedQueryCriteria")

   virtual ~SavedQueryCriteria();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
