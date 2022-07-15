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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MRPDATA_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MRPDATA_HXX

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


class TCSOACLIENTMNGD_API MRPData : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_advtoolflg();
    const std::string& get_prodtoolflg();
    const std::string& get_abcclass();
    const std::string& get_containqty();
    const std::string& get_splyorg();
    const std::string& get_estitmcst();
    const std::string& get_itmtyp();
    const std::string& get_mba();
    const std::string& get_leadtime();
    const std::string& get_targetcst();
    const std::string& get_eccn();
    const std::string& get_wbs();
    const std::string& get_wtunit();
    const std::string& get_contractno();
    const std::string& get_estweight();
    const std::string& get_tgtweight();
    const std::string& get_edf();
    const std::string& get_ltunit();
    const std::string& get_chgclass();
    const std::string& get_prlt();
    const std::string& get_asmcst();
    const std::string& get_toolcst();
    const std::string& get_clitmcst();
    const std::string& get_cltoolcst();
    const std::string& get_clasmcst();
    const std::string& get_twtunit();
    const std::string& get_prltunit();
    const std::string& get_prordduedate();
    const std::string& get_loccode();
    const std::string& get_locqty();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MRPData")

   virtual ~MRPData();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
