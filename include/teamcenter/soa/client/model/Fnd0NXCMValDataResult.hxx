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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0NXCMVALDATARESULT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0NXCMVALDATARESULT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Fnd0NXValDataResult.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Fnd0NXCMValDataResult : public Teamcenter::Soa::Client::Model::Fnd0NXValDataResult
{
public:
    const Teamcenter::Soa::Client::StringVector& get_fnd0parent_valdata_names();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0NXCMValDataResult")

   virtual ~Fnd0NXCMValDataResult();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
