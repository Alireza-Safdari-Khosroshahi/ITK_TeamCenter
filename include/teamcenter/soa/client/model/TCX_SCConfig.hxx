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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TCX_SCCONFIG_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TCX_SCCONFIG_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class AM_ACL;


class TCSOACLIENTMNGD_API TCX_SCConfig : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_SC_ID();
    const std::string& get_SC_Label();
    const std::string& get_SC_Choice();
    int get_SC_Type();
    const std::string& get_SC_Repository();
    const Teamcenter::Soa::Client::StringVector& get_SC_Affect();
    const std::string& get_SC_LastValue();
    const std::string& get_SC_Select();
    bool get_SC_Restrictive();
    int get_SC_ReuseValues();
    int get_SC_Generate();
    const std::string& get_SC_SecondValue();
    const std::string& get_SC_FirstValue();
    char get_SC_LeadingChar();
    int get_SC_Step_Offset();
    int get_SC_Step_Fill();
    Teamcenter::Soa::Common::AutoPtr<AM_ACL> get_SC_ACL();
    const std::string& get_SC_ExternalFn();
    const std::string& get_SC_CounterKey();
    const Teamcenter::Soa::Client::StringVector& get_SC_FieldSets();
    int get_SC_Step();
    int get_SC_Length();
    const std::string& get_SC_Sufix();
    const Teamcenter::Soa::Client::StringVector& get_SC_Mask();
    const std::string& get_SC_Prefix();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TCX_SCConfig")

   virtual ~TCX_SCConfig();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
