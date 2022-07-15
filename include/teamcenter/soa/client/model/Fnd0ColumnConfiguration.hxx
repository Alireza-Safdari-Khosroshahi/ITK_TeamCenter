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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0COLUMNCONFIGURATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0COLUMNCONFIGURATION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Fnd0UIConfiguration.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Fnd0ColumnConfiguration : public Teamcenter::Soa::Client::Model::Fnd0UIConfiguration
{
public:
    const Teamcenter::Soa::Client::StringVector& get_fnd0ColumnNames();
    const Teamcenter::Soa::Client::StringVector& get_fnd0ColumnDescs();
    const Teamcenter::Soa::Client::StringVector& get_fnd0ColumnWidths();
    const Teamcenter::Soa::Client::StringVector& get_fnd0FilterValues();
    const Teamcenter::Soa::Client::StringVector& get_fnd0FilterOperators();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0ColumnConfiguration")

   virtual ~Fnd0ColumnConfiguration();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
