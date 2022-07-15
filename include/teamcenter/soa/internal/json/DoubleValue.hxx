//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//==================================================
//Copyright 2012
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

#ifndef INCLUDE_TEAMCENTER_JSON_DOUBLE_HXX
#define INCLUDE_TEAMCENTER_JSON_DOUBLE_HXX



#include <teamcenter/soa/internal/json/Value.hxx>


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
 */
class TCSOACOMMON_API DoubleValue : public Teamcenter::Soa::Internal::Json::Value
{
public:
    const double mValue;

    DoubleValue( double value );
    virtual ~DoubleValue();

    virtual bool      isEmpty() const;
    virtual size_t    size()    const;
    virtual ValueType getType() const;

protected:
    virtual void      serialize( int level, std::ostream& document ) const;

     
private:
    DoubleValue(); // Not implemented

};        // End Class
}}}}      // End Namespace

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
