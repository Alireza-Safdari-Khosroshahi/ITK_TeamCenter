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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MENUENTRYSUPPRESSIONINFO_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MENUENTRYSUPPRESSIONINFO_HXX

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


class TCSOACLIENTMNGD_API MenuEntrySuppressionInfo : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const Teamcenter::Soa::Client::StringVector& get_entries();
    const std::string& get_name();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MenuEntrySuppressionInfo")

   virtual ~MenuEntrySuppressionInfo();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
