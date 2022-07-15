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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_JTSIMPLIFICATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_JTSIMPLIFICATION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Dataset.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API JtSimplification : public Teamcenter::Soa::Client::Model::Dataset
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_DMI_markup();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_capture();
    const Teamcenter::Soa::Client::ModelObjectVector& get_3DMarkup();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("JtSimplification")

   virtual ~JtSimplification();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
