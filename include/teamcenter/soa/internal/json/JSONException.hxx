//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//==================================================
//Copyright 2012
//Siemens Product Lifecycle Management Software Inc.
//All Rights Reserved.
//==================================================
//Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
#ifndef INCLUDE_TEAMCENTER_JSON_JSONEXCEPTION_HXX
#define INCLUDE_TEAMCENTER_JSON_JSONEXCEPTION_HXX

#include <string>


#include <teamcenter/soa/common/SoaCommonExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Internal
        {
            namespace Json
            {


class TCSOACOMMON_API JSONException
{
public:
    explicit JSONException( const std::string& message );
    virtual ~JSONException();

    virtual std::string getMessage();

protected:


private:
    std::string mMessage;

};        // End Class
}}}}      // End Namespace

#include <teamcenter/soa/common/SoaCommonUndef.h>
#endif
