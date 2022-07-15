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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DESIGNPROXY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DESIGNPROXY_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/TcUsageProxy.hxx>

#include <teamcenter/soa/client/model/CbaMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACBAMODELMNGD_API DesignProxy : public Teamcenter::Soa::Client::Model::TcUsageProxy
{
public:
    bool get_is_modifiable();
    const std::string& get_object_desc();
    const std::string& get_cba0MATHSOURCETUID_UMathSource();
    const std::string& get_cba0MATHNOMENCLATURETUID_UMathNomenclature();
    const std::string& get_cba0ALTERNATEREPRESENTATION_UMathNomenclature();
    const std::string& get_cba0NOMENCLATURETUID_UMathNomenclatureText();
    const std::string& get_cba0RECORDSTATE_UMathNomenclature();
    const std::string& get_cba0RECORDSTATE_UMathNomenclatureTUID();
    const std::string& get_cba0MATHNOMENCLATURETEXTTUID_UMathNomenclatureText();
    const std::string& get_cba0SLOC_UMathSource();
    const std::string& get_cba0MATHBASE_UMathNomenclature();
    const std::string& get_cba0MATHKEY02_UMathNomenclature();
    const std::string& get_cba0DEFAULTREASONFORASSIGNMENT_UMathNomenclature();
    const std::string& get_object_name();
    const std::string& get_cba0MATHUIDNAMESPACE_UMathSource();
    const std::string& get_cba0MATHSYSTEMTUID_UMathSource();
    const std::string& get_cba0RECORDSTATE_UMathSource();
    const std::string& get_cba0MATHUID_UMathSource();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_UMathNomenclature();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_UMathNomenclatureTUID();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_UMathNomenclatureTUID();
    const std::string& get_cba0DEFAULTMATHNAME_UMathNomenclature();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_UMathNomenclature();
    const std::string& get_cba0RECORDSTATE_UMathNomenclatureText();
    const std::string& get_cba0MATHMATURITY_UMathSource();
    const std::string& get_cba0SLOC_UMathNomenclature();
    const std::string& get_cba0SLOC_UMathNomenclatureTUID();
    const std::string& get_cba0DEFAULTREASONFORASSIGNMENT_UMathNomenclatureText();
    const std::string& get_cba0LASTMODIFIEDUSER_UMathNomenclature();
    const std::string& get_cba0CREATIONUSER_UMathNomenclature();
    const std::string& get_cba0LASTMODIFIEDUSER_UMathNomenclatureTUID();
    const std::string& get_cba0CREATIONUSER_UMathNomenclatureTUID();
    const std::string& get_cba0MATHNUMBERNAMESPACE_UMathNomenclature();
    const std::string& get_checked_out();
    const std::string& get_last_mod_date();
    const std::string& get_object_type();
    const std::string& get_owning_group();
    const std::string& get_owning_user();
    const std::string& get_relation();
    const std::string& get_release_status_list();
    const std::string& get_cba0MATHREVISION_UMathNomenclature();
    const std::string& get_cba0MATHNAME_UMathNomenclatureText();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_UMathSource();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_UMathSource();
    const std::string& get_cba0SYSTEMGENERATED_UMathNomenclature();
    const std::string& get_cba0DEFAULTLNG_UMathNomenclature();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_UMathNomenclatureText();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_UMathNomenclatureText();
    const std::string& get_cba0SLOC_UMathNomenclatureText();
    const std::string& get_cba0LNG_UMathNomenclatureText();
    const std::string& get_cba0LASTMODIFIEDUSER_UMathSource();
    const std::string& get_cba0CREATIONUSER_UMathSource();
    const std::string& get_cba0MATHORIGINTUID_UMathSource();
    const std::string& get_cba0MATHKEY03_UMathNomenclature();
    const std::string& get_cba0LASTMODIFIEDUSER_UMathNomenclatureText();
    const std::string& get_cba0CREATIONUSER_UMathNomenclatureText();
    const std::string& get_cba0MATHNUMBERNAMESPACE_UMathNomenclatureText();
    const std::string& get_cba0MATHNOMENCLATURETUID_UMathSource();
    const std::string& get_cba0NOMENCLATURETUID_UMathNomenclatureTUID();
    const std::string& get_cba0NOMENCLATURETUID_UMathNomenclature();
    const std::string& get_cba0DEFAULTSORTCRITERA_UMathNomenclature();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DesignProxy")

   virtual ~DesignProxy();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CbaMngd_undef.h>
#endif
