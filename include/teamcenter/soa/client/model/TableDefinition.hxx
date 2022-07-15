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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TABLEDEFINITION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TABLEDEFINITION_HXX

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
                class TableLabel;
                class TableLabel;


class TCSOACLIENTMNGD_API TableDefinition : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    int get_cols();
    int get_rows();
    size_t count_colLabels();
    Teamcenter::Soa::Common::AutoPtr<TableLabel> get_colLabels_at( size_t inx );
    size_t count_rowLabels();
    Teamcenter::Soa::Common::AutoPtr<TableLabel> get_rowLabels_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TableDefinition")

   virtual ~TableDefinition();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
