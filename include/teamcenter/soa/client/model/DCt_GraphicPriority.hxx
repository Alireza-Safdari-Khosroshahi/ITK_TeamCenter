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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DCT_GRAPHICPRIORITY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DCT_GRAPHICPRIORITY_HXX

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


class TCSOACLIENTMNGD_API DCt_GraphicPriority : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    const std::string& get_grphPrioName();
    int get_grphPrioMaxOptions();
    const std::string& get_adminComment();
    const Teamcenter::Soa::Client::StringVector& get_graphicUsages();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DCt_GraphicPriority")

   virtual ~DCt_GraphicPriority();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
