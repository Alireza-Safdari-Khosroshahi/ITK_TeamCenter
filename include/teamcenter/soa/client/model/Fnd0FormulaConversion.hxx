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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0FORMULACONVERSION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0FORMULACONVERSION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Fnd0GenericConversionRule.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Fnd0AlgebraicFormula;


class TCSOACLIENTMNGD_API Fnd0FormulaConversion : public Teamcenter::Soa::Client::Model::Fnd0GenericConversionRule
{
public:
    const Teamcenter::Soa::Client::StringVector& get_fnd0ConstValues();
    Teamcenter::Soa::Common::AutoPtr<Fnd0AlgebraicFormula> get_fnd0AlgebraicFormula();
    const std::string& get_fnd0Expression();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0FormulaConversion")

   virtual ~Fnd0FormulaConversion();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
