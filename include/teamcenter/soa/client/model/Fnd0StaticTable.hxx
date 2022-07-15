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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0STATICTABLE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0STATICTABLE_HXX

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
                class TableProperties;


class TCSOACLIENTMNGD_API Fnd0StaticTable : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    size_t count_fnd0StaticTableData();
    Teamcenter::Soa::Common::AutoPtr<TableProperties> get_fnd0StaticTableData_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0StaticTable")

   virtual ~Fnd0StaticTable();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
