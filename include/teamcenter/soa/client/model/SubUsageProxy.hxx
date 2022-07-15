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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SUBUSAGEPROXY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SUBUSAGEPROXY_HXX

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


class TCSOACBAMODELMNGD_API SubUsageProxy : public Teamcenter::Soa::Client::Model::TcUsageProxy
{
public:
    const std::string& get_cba0ITEMTYPE_UExpression();
    const std::string& get_cba0VALIDINDICATOR_USubUsage();
    const std::string& get_alignedState();
    const std::string& get_valid_indicator();
    const Teamcenter::Soa::Client::ModelObjectVector& get_part_occs();
    bool get_is_modifiable();
    const std::string& get_object_desc();
    const std::string& get_object_name();
    const std::string& get_checked_out();
    const std::string& get_last_mod_date();
    const std::string& get_object_type();
    const std::string& get_owning_group();
    const std::string& get_owning_user();
    const std::string& get_relation();
    const std::string& get_release_status_list();
    const std::string& get_cba0EXPRESSIONMAJORFEATURE09_UExpression();
    const std::string& get_cba0APPENDEDVARIANTEXPRESSIONSTRIN_USubUsage();
    const std::string& get_cba0RECORDGROUPTUID_USubUsage();
    const std::string& get_cba0RECORDSTATE_UExpression();
    int get_cba0QUANTITY_USubUsage();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_USubUsage();
    const std::string& get_cba0EXPRESSIONMAJORFEATURE11_UExpression();
    const std::string& get_cba0SLOC_USubUsage();
    const std::string& get_cba0DISPLAYEXPRESSION_UExpression();
    const std::string& get_cba0CREATIONUSER_USubUsage();
    const std::string& get_cba0EXPRESSIONMAJORFEATURE13_UExpression();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_UExpression();
    const std::string& get_cba0PENDINGREVIEWINDICATOR_USubUsage();
    const std::string& get_cba0EXPRESSIONMAJORFEATURE15_UExpression();
    const std::string& get_cba0CADALIGNEDINDICATOR_USubUsage();
    const std::string& get_cba0LASTMODIFIEDUSER_UExpression();
    const std::string& get_cba0EXPRESSIONMAJORFEATURE02_UExpression();
    const std::string& get_cba0EXPRESSIONMAJORFEATURE04_UExpression();
    const std::string& get_cba0SUBUSAGETUID_USubUsage();
    const std::string& get_cba0COMPLETEBK_UExpression();
    int get_cba0CHECKSUM_UExpression();
    const std::string& get_cba0EXPRESSIONMAJORFEATURE06_UExpression();
    const std::string& get_cba0MATHVALIDATIONSTATUS_USubUsage();
    const std::string& get_cba0MUG02_UExpression();
    const std::string& get_cba0EXPRESSIONMAJORFEATURE08_UExpression();
    const std::string& get_cba0CONFIGEXPRESSIONTUID_USubUsage();
    const std::string& get_cba0EXPRESSIONMAJORFEATURE10_UExpression();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_USubUsage();
    const std::string& get_cba0LNG_USubUsage();
    const std::string& get_cba0EXPRESSIONMAJORFEATURE12_UExpression();
    const std::string& get_cba0LASTMODIFIEDUSER_USubUsage();
    int get_cba0CHECKSUMSEQUENCE_UExpression();
    const std::string& get_cba0EXPRESSIONMAJORFEATURE14_UExpression();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_UExpression();
    const std::string& get_cba0EXPRESSIONTUID_USubUsage();
    const std::string& get_cba0ACTIVEINDICATOR_USubUsage();
    const std::string& get_cba0EXPRESSIONMAJORFEATURE01_UExpression();
    const std::string& get_cba0EXPRESSIONMAJORFEATURE16_UExpression();
    const std::string& get_cba0CREATIONUSER_UExpression();
    const std::string& get_cba0CUSTOMERCODE_UExpression();
    const std::string& get_cba0EXPRESSIONTUID_UExpression();
    const std::string& get_cba0INVALIDINDICATOR_UExpression();
    const std::string& get_cba0EXPRESSION_UExpression();
    const std::string& get_cba0EXPRESSIONMAJORFEATURE03_UExpression();
    const std::string& get_cba0DESCRIPTION_USubUsage();
    const std::string& get_cba0VALIDATEDINDICATOR_USubUsage();
    const std::string& get_cba0RECORDGROUPITEMTUID_USubUsage();
    const std::string& get_cba0EXPRESSIONMAJORFEATURE05_UExpression();
    const std::string& get_cba0MUG01_UExpression();
    const std::string& get_cba0EXPRESSIONMAJORFEATURE07_UExpression();
    const std::string& get_cba0SHORTDESCRIPTION_USubUsage();
    const std::string& get_cba0RECORDSTATE_USubUsage();
    const std::string& get_cba0SLOC_UExpression();
    const std::string& get_active_indicator();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SubUsageProxy")

   virtual ~SubUsageProxy();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CbaMngd_undef.h>
#endif
