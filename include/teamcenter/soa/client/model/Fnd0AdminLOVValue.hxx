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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0ADMINLOVVALUE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0ADMINLOVVALUE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Fnd0AdminLOVValue : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    const std::string& get_fnd0lov_value();
    const std::string& get_fnd0lov_description();
    const std::string& get_fnd0lov_category();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0AdminLOVValue")

   virtual ~Fnd0AdminLOVValue();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
