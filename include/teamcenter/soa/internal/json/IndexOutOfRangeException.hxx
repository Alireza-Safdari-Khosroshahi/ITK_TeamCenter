//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//==================================================
//Copyright 2012
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

#ifndef INCLUDE_TEAMCENTER_JSON_INDEXOUTOFRANGEEXCEPTION_HXX
#define INCLUDE_TEAMCENTER_JSON_INDEXOUTOFRANGEEXCEPTION_HXX

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



class TCSOACOMMON_API IndexOutOfRangeException: public Teamcenter::Soa::Internal::Json::JSONException
{
public:
    explicit IndexOutOfRangeException( const std::string& message );
    virtual ~IndexOutOfRangeException();


protected:


private:

};        // End Class
}}}}      // End Namespace

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
