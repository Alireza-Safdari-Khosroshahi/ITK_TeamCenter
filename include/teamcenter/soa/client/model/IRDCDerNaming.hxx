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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_IRDCDERNAMING_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_IRDCDERNAMING_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/IRDCNaming.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class DatasetType;


class TCSOACLIENTMNGD_API IRDCDerNaming : public Teamcenter::Soa::Client::Model::IRDCNaming
{
public:
    Teamcenter::Soa::Common::AutoPtr<DatasetType> get_der_ds_name();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("IRDCDerNaming")

   virtual ~IRDCDerNaming();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
