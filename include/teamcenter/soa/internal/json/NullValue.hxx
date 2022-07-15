//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//==================================================
//Copyright 2012
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

#ifndef INCLUDE_TEAMCENTER_JSON_NULL_HXX
#define INCLUDE_TEAMCENTER_JSON_NULL_HXX



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
class TCSOACOMMON_API NullValue : public Teamcenter::Soa::Internal::Json::Value
{
public:

    NullValue(  );
    virtual ~NullValue();

    virtual bool      isEmpty() const;
    virtual size_t    size()    const;
    virtual ValueType getType() const;

protected:
    virtual void      serialize( int level, std::ostream& document ) const;

     
private:

};        // End Class
}}}}      // End Namespace

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
