// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2012.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_INTERNAL_COMMON_BASECODE_HXX
#define TEAMCENTER_SOA_INTERNAL_COMMON_BASECODE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/schemas/soa/_2006_03/exceptions/SoaException.hxx>



#include <string>
#include <vector>


#include <teamcenter/soa/common/SoaCommonExports.h>




namespace Teamcenter
{
    namespace Soa
    {
        namespace Common
        {
            class BaseCode;
        }
    }
}

class TCSOACOMMON_API Teamcenter::Soa::Common::BaseCode
{
public:
             BaseCode();
    virtual ~BaseCode();

    SOA_CLASS_NEW_OPERATORS

    /**
     *
     * @return The error code.
     */
    virtual int getCode() const =0;

    /**
     *
     * @return The error text.
     */
    virtual std::string getText()const =0;

    /**
     *
     * @return The error text.
     */
    std::string getTextWithSubstitutions( const std::vector<std::string>& substitutions )const;

    /**
     *
     * @return The severity level.
     */
    virtual Teamcenter::Schemas::Soa::_2006_03::Exceptions::Error::Severity getSeverity() const =0;
};

#include <teamcenter/soa/common/SoaCommonUndef.h>

#endif
