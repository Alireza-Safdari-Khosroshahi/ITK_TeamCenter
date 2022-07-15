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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SYSD_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SYSD_HXX

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


class TCSOACLIENTMNGD_API Sysd : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_id();
    const std::string& get_cid();
    const std::string& get_sid();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_eref();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_iref();
    int get_iflags();
    const Teamcenter::Soa::Client::StringVector& get_shared_sites();
    const std::string& get_sm01();
    const std::string& get_sm02();
    const std::string& get_sm03();
    const std::string& get_sm04();
    const std::string& get_sm05();
    const std::string& get_sm06();
    const std::string& get_sm07();
    const std::string& get_sm08();
    const std::string& get_sm09();
    const std::string& get_sm10();
    const std::string& get_sm11();
    const std::string& get_sm12();
    const std::string& get_sm13();
    const std::string& get_sm14();
    const std::string& get_sm15();
    const std::string& get_sm16();
    const std::string& get_sm17();
    const std::string& get_sm18();
    const std::string& get_sm19();
    const std::string& get_sm20();
    const std::string& get_sm21();
    const std::string& get_sm22();
    const std::string& get_sm23();
    const std::string& get_sm24();
    const std::string& get_sm25();
    const std::string& get_sm26();
    const std::string& get_sm27();
    const std::string& get_sm28();
    const std::string& get_sm29();
    const std::string& get_sm30();
    const std::string& get_sm31();
    const std::string& get_sm32();
    const std::string& get_sm33();
    const std::string& get_sm34();
    const std::string& get_sm35();
    const std::string& get_sm36();
    const std::string& get_sm37();
    const std::string& get_sm38();
    const std::string& get_sm39();
    const std::string& get_sm40();
    const std::string& get_sm41();
    const std::string& get_sm42();
    const std::string& get_sm43();
    const std::string& get_sm44();
    const std::string& get_sm45();
    const std::string& get_sm46();
    const std::string& get_sm47();
    const std::string& get_sm48();
    const std::string& get_sm49();
    const std::string& get_sm50();
    const std::string& get_sm51();
    const std::string& get_sm52();
    const std::string& get_sm53();
    const std::string& get_sm54();
    const std::string& get_sm55();
    const std::string& get_sm56();
    const std::string& get_sm57();
    const std::string& get_sm58();
    const std::string& get_sm59();
    const std::string& get_sm60();
    const std::string& get_sm61();
    const std::string& get_sm62();
    const std::string& get_sm63();
    const std::string& get_sm64();
    const std::string& get_sm65();
    const std::string& get_sm66();
    const std::string& get_sm67();
    const std::string& get_sm68();
    const std::string& get_sm69();
    const std::string& get_sm70();
    const std::string& get_sm71();
    const std::string& get_sm72();
    const std::string& get_sm73();
    const std::string& get_sm74();
    const std::string& get_sm75();
    const std::string& get_sm76();
    const std::string& get_sm77();
    const std::string& get_sm78();
    const std::string& get_sm79();
    const std::string& get_sm80();
    const std::string& get_sm81();
    const std::string& get_sm82();
    const std::string& get_sm83();
    const std::string& get_sm84();
    const std::string& get_sm85();
    const std::string& get_sm86();
    const std::string& get_sm87();
    const std::string& get_sm88();
    const std::string& get_sm89();
    const std::string& get_sm90();
    const std::string& get_sm91();
    const std::string& get_sm92();
    const std::string& get_sm93();
    const std::string& get_sm94();
    const std::string& get_sm95();
    const std::string& get_sm96();
    const std::string& get_sm97();
    const std::string& get_sm98();
    const std::string& get_sm99();
    const std::string& get_sm100();
    const std::string& get_cr_uid();
    const std::string& get_cr_gid();
    const std::string& get_cr_date();
    const std::string& get_mod_uid();
    const std::string& get_mod_date();
    int get_gac();
    int get_wac();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Sysd")

   virtual ~Sysd();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
