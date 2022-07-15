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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MFG0MEEXECUTIONPOSN_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MFG0MEEXECUTIONPOSN_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Mfg0MEExecutionPosn : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_Mfg0Acronym();
    const Teamcenter::Soa::Client::IntVector& get_Mfg0Color();
    int get_Mfg0Index();
    const Teamcenter::Soa::Client::IntVector& get_Mfg0MatrixPosition();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mfg0MEExecutionPosn")

   virtual ~Mfg0MEExecutionPosn();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
