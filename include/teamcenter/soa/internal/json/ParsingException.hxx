//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//==================================================
//Copyright 2012
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
#ifndef INCLUDE_TEAMCENTER_JSON_PARSINGEXCEPTION_HXX
#define INCLUDE_TEAMCENTER_JSON_PARSINGEXCEPTION_HXX

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


class TCSOACOMMON_API ParsingException: public Teamcenter::Soa::Internal::Json::JSONException
{
public:
    explicit ParsingException( const std::string& message );
    virtual ~ParsingException();


protected:


private:

};        // End Class
}}}}      // End Namespace

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
