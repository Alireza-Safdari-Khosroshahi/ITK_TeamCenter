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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PADTIMEANALYSISFORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PADTIMEANALYSISFORM_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/model/CmtpadtwpMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMTPADTWPMODELMNGD_API PADTimeAnalysisForm : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_sequence_no();
    const std::string& get_decision_desc();
    const std::string& get_decsion_code();
    double get_constant_time();
    double get_variable_time();
    double get_frq();
    const std::string& get_ana_type();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PADTimeAnalysisForm")

   virtual ~PADTimeAnalysisForm();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmtpadtwpMngd_undef.h>
#endif
