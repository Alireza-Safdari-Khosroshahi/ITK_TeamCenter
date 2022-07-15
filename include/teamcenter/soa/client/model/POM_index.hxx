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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_POM_INDEX_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_POM_INDEX_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_rdbms_dd.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class POM_column;
                class POM_table;


class TCSOACLIENTMNGD_API POM_index : public Teamcenter::Soa::Client::Model::POM_rdbms_dd
{
public:
    const std::string& get_name();
    size_t count_columns();
    Teamcenter::Soa::Common::AutoPtr<POM_column> get_columns_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<POM_table> get_table();
    bool get_unique();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("POM_index")

   virtual ~POM_index();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
