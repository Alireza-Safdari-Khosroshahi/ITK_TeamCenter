// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2012.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_INTERNAL_COMMON_AUTHUTILS_HXX
#define TEAMCENTER_SOA_INTERNAL_COMMON_AUTHUTILS_HXX




#include <string>
#include <teamcenter/schemas/core/_2011_06/session/Credentials.hxx>


#include <teamcenter/soa/common/SoaCommonExports.h>




namespace Teamcenter
{
    namespace Soa
    {
         namespace Internal
         {
            namespace Common
            {
                class AuthUtils;
            }
        }
    }
}

class TCSOACOMMON_API Teamcenter::Soa::Internal::Common::AuthUtils
{
public:
    static bool isLoginOperation( const std::string& service, const std::string& operation  );
    static Teamcenter::Soa::Common::AutoPtr<Teamcenter::Schemas::Core::_2011_06::Session::Credentials> getUserCredentials(
                    const std::string& service, 
                    const std::string& operation, 
                    const std::string& requestXml,
                    const std::string& encoding="" );



private:
    static const std::string SESSION_0603_SERVICE;
    static const std::string SESSION_0806_SERVICE;
    static const std::string SESSION_1106_SERVICE;
    static const std::string TCSERVICE_LOGIN_SERVICE; 

    static const std::string LOGIN_METHOD_NAME;
    static const std::string LOGIN_LOCALE_METHOD_NAME;
    static const std::string SSOLOGIN_METHOD_NAME;
    static const std::string AUTHENTICATE_METHOD_NAME;
    static const std::string AUTH_LOCALE_METHOD_NAME;


};

#include <teamcenter/soa/common/SoaCommonUndef.h>

#endif
