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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PSSIGNALREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PSSIGNALREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ItemRevision.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class PSSignalValue;


class TCSOACLIENTMNGD_API PSSignalRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    Teamcenter::Soa::Common::AutoPtr<PSSignalValue> get_signal_value_tag();
    const std::string& get_signal_characteristics();
    double get_signal_value();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PSSignalRevision")

   virtual ~PSSignalRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
