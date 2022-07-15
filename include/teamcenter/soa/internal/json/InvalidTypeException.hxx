//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//==================================================
//Copyright 2012
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

#ifndef INCLUDE_TEAMCENTER_JSON_INVALIDTYPEEXCEPTION_HXX
#define INCLUDE_TEAMCENTER_JSON_INVALIDTYPEEXCEPTION_HXX

#include <string>

#include <teamcenter/soa/internal/json/JSONException.hxx>

#include <teamcenter/soa/common/SoaCommonExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Internal
        {
            namespace Json
            {



class TCSOACOMMON_API InvalidTypeException: public Teamcenter::Soa::Internal::Json::JSONException
{
public:
    explicit InvalidTypeException( const std::string& message );
    virtual ~InvalidTypeException();


protected:


private:

};        // End Class
}}}}      // End Namespace

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
