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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MEPROCESSTIMEANALYSIS_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MEPROCESSTIMEANALYSIS_HXX

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


class TCSOACLIENTMNGD_API MEProcessTimeAnalysis : public Teamcenter::Soa::Client::Model::Form
{
public:
    double get_simulated_time();
    double get_allocated_time();
    double get_estimated_time();
    double get_cycle_time();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MEProcessTimeAnalysis")

   virtual ~MEProcessTimeAnalysis();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
