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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MES0BVRSTXELEMENT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MES0BVRSTXELEMENT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ImanItemBOPLine.hxx>

#include <teamcenter/soa/client/model/CmtmesMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMTMESMODELMNGD_API Mes0BvrSTXElement : public Teamcenter::Soa::Client::Model::ImanItemBOPLine
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_mes0ObjectData();
    const Teamcenter::Soa::Client::ModelObjectVector& get_mes0DCDNodes();
    const Teamcenter::Soa::Client::ModelObjectVector& get_mes0PFNodes();
    bool get_mes0IsActive();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mes0BvrSTXElement")

   virtual ~Mes0BvrSTXElement();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmtmesMngd_undef.h>
#endif
