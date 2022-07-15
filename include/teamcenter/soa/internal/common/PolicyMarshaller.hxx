// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2012
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.


#ifndef TEAMCENTER_SOA_INTERNAL_COMMON_POLICYMARSHALLER_HXX
#define TEAMCENTER_SOA_INTERNAL_COMMON_POLICYMARSHALLER_HXX

#include <string>
#include <map>
#include <vector>
#include <new>
#include <teamcenter/schemas/soa/_2006_03/base/Modifiers.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/PolicyProperty.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/PolicyType.hxx>
#include <teamcenter/schemas/soa/_2006_03/base/ObjectPropertyPolicy.hxx>
#include <teamcenter/schemas/soa/objectpropertypolicy/Property.hxx>
#include <teamcenter/schemas/soa/objectpropertypolicy/ObjectType.hxx>
#include <teamcenter/soa/common/PolicyProperty.hxx>
#include <teamcenter/soa/common/PolicyType.hxx>
#include <teamcenter/soa/common/ObjectPropertyPolicy.hxx>
#include <teamcenter/soa/common/xml/SaxToNodeParser.hxx>
#include <teamcenter/soa/common/MemoryManager.hxx>


#include <teamcenter/soa/common/SoaCommonExports.h>


namespace Teamcenter
{
    namespace Soa
    {
        namespace Internal
        {
            namespace Common
            {


class TCSOACOMMON_API PolicyMarshaller
{
 public:

     ~PolicyMarshaller();
   SOA_CLASS_NEW_OPERATORS
  



    static void toLocal( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::PolicyProperty> xsdPolicyProperty, Teamcenter::Soa::Common::PolicyProperty& localPolicyProperty );
    static void toLocal( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::PolicyType>& xsdPolicyType,        Teamcenter::Soa::Common::PolicyType&     localPolicyType     );
    static void toLocal( const Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ObjectPropertyPolicy>& xsdPolicy,  Teamcenter::Soa::Common::ObjectPropertyPolicy& localPolicy   );

    static Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::PolicyProperty>       toWire( const Teamcenter::Soa::Common::PolicyProperty& localPolicyProperty );
    static Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::PolicyType>           toWire( const Teamcenter::Soa::Common::PolicyType&     localPolicyType );
    static Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::_2006_03::Base::ObjectPropertyPolicy> toWire( const Teamcenter::Soa::Common::ObjectPropertyPolicy& localPolicy );


    static Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::Objectpropertypolicy::Property>   serialize( const Teamcenter::Soa::Common::PolicyProperty& policyProperty );
    static Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Soa::Objectpropertypolicy::ObjectType> serialize( const Teamcenter::Soa::Common::PolicyType&     policyType     );

    static void parse(const Teamcenter::Soa::Common::Xml::XMLNode &node, Teamcenter::Soa::Common::PolicyProperty& policyProperty );   
    static void parse(const Teamcenter::Soa::Common::Xml::XMLNode &node, Teamcenter::Soa::Common::PolicyType&     policyType     );   

    static bool isAFlag(const std::string flag);

private:
    
    // Don't all default constructor
    PolicyMarshaller();


};        // End Class
}}}}       // End Namespace

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
