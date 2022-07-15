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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0SHAPERELATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0SHAPERELATION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ImanRelation.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Fnd0ShapeRelation : public Teamcenter::Soa::Client::Model::ImanRelation
{
public:
    const std::string& get_fnd0shapeGraphics();
    const std::string& get_fnd0membershipType();
    bool get_fnd0userOmitted();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0ShapeRelation")

   virtual ~Fnd0ShapeRelation();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
