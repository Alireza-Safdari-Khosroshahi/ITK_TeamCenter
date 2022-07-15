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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVRWORKAREA_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVRWORKAREA_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ImanItemLine.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Mfg0BvrWorkarea : public Teamcenter::Soa::Client::Model::ImanItemLine
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0sub_elements();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0input_flows();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0output_flows();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0predecessors();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0successors();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_Mfg0container();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mfg0BvrWorkarea")

   virtual ~Mfg0BvrWorkarea();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
