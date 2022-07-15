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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MES0MEDCD_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MES0MEDCD_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/GeneralDesignElement.hxx>

#include <teamcenter/soa/client/model/CmtmesMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMTMESMODELMNGD_API Mes0MEDCD : public Teamcenter::Soa::Client::Model::GeneralDesignElement
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mes0MEDCD_Details();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mes0MEDCD_Override();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mes0MEDCD")

   virtual ~Mes0MEDCD();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmtmesMngd_undef.h>
#endif
