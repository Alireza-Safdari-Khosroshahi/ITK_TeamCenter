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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SAVEDSEARCH_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SAVEDSEARCH_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class SavedQueryCriteria;


class TCSOACLIENTMNGD_API SavedSearch : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    bool get_shared();
    const Teamcenter::Soa::Client::StringVector& get_context_objects();
    Teamcenter::Soa::Common::AutoPtr<SavedQueryCriteria> get_saved_search_criteria();
    const Teamcenter::Soa::Client::StringVector& get_savedsearch_attr_names();
    const Teamcenter::Soa::Client::StringVector& get_savedsearch_attr_values();
    bool get_savedsearch_result_type();
    const std::string& get_savedsearch_adhoc_class();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_savedsearch_query();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SavedSearch")

   virtual ~SavedSearch();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
