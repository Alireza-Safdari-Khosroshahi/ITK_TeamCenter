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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_REQDATA_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_REQDATA_HXX

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


class TCSOACLIENTMNGD_API ReqData : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_ordno();
    const std::string& get_rqstrid();
    const std::string& get_chgno();
    const std::string& get_buyer();
    const std::string& get_ordqty();
    const std::string& get_orddate();
    const std::string& get_ordduedate();
    const std::string& get_promisedate();
    const std::string& get_estitmcst();
    const std::string& get_specprint();
    const std::string& get_itmmatl();
    const std::string& get_splyorg();
    const std::string& get_splydept();
    const std::string& get_docsattflg();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ReqData")

   virtual ~ReqData();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
