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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_UGPARTATTRIBUTES_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_UGPARTATTRIBUTES_HXX

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


class TCSOACLIENTMNGD_API UGPartAttributes : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    int get_flags();
    const Teamcenter::Soa::Client::StringVector& get_titles();
    const Teamcenter::Soa::Client::StringVector& get_values();
    const Teamcenter::Soa::Client::StringVector& get_fnd0sync_checksums();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("UGPartAttributes")

   virtual ~UGPartAttributes();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
