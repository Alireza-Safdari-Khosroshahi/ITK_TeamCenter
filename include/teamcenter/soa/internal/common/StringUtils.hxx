// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2012.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

#ifndef TEAMCENTER_SOA_INTERNAL_COMMON_STRINGUTILS_HXX
#define TEAMCENTER_SOA_INTERNAL_COMMON_STRINGUTILS_HXX

#include <string>
#include <vector>


#include <teamcenter/soa/common/SoaCommonExports.h>

namespace Teamcenter
{
    namespace Soa
    {
         namespace Internal
         {
            namespace Common
            {
class TCSOACOMMON_API StringUtils
{

public:

    static std::string trim( const std::string& word );
    static std::string trim( const std::string& word, int start, int end );

    static void split(const std::string& str, const std::string& delimiter, std::vector<std::string>& tokens );

    static std::string replace( const std::string& in, const std::string& target, const std::string& replacement );



};
}}}}

#include <teamcenter/soa/common/SoaCommonUndef.h>

#endif

