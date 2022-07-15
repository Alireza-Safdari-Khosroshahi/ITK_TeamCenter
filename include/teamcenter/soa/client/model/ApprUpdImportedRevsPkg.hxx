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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPRUPDIMPORTEDREVSPKG_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPRUPDIMPORTEDREVSPKG_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ApprUpdChangedRevsPkg.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API ApprUpdImportedRevsPkg : public Teamcenter::Soa::Client::Model::ApprUpdChangedRevsPkg
{
public:
    const Teamcenter::Soa::Common::DateTime& get_import_date();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ApprUpdImportedRevsPkg")

   virtual ~ApprUpdImportedRevsPkg();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
