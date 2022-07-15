//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//==================================================
//Copyright 2012
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

#ifndef INCLUDE_TEAMCENTER_JSON_DATE_HXX
#define INCLUDE_TEAMCENTER_JSON_DATE_HXX

#include <string>


#include <teamcenter/soa/internal/json/Value.hxx>
#include <teamcenter/soa/common/DateTime.hxx>


#include <teamcenter/soa/common/SoaCommonExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Internal
        {
            namespace Json
            {

/**
 * JSON does not define an actual value type for dates, howerver this impelmenation
 * assumes any quoted value with the format of 'yyyy-MM-ddThh:mm:ss zz:zz' to be a date.
 */
class TCSOACOMMON_API DateValue : public Teamcenter::Soa::Internal::Json::Value
{
public:
    const Teamcenter::Soa::Common::DateTime mValue;
    const std::string                       mStringValue;

    DateValue( const Teamcenter::Soa::Common::DateTime& value );
    virtual ~DateValue();

    virtual bool      isEmpty() const;
    virtual size_t    size()    const;
    virtual ValueType getType() const;

protected:
    virtual void      serialize( int level, std::ostream& document ) const;

     
private:
    DateValue(); // Not implemented

};        // End Class
}}}}      // End Namespace

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
