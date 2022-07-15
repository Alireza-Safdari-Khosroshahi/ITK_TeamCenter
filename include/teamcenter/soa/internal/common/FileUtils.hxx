// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2012.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

#ifndef TEAMCENTER_SOA_INTERNAL_COMMON_FILEUTILS_HXX
#define TEAMCENTER_SOA_INTERNAL_COMMON_FILEUTILS_HXX

#include <string>


#include <teamcenter/soa/common/SoaCommonExports.h>

namespace Teamcenter
{
    namespace Soa
    {
         namespace Internal
         {
            namespace Common
            {
class TCSOACOMMON_API FileUtils
{

public:
    /**
     * @return True if the file or folder exists.
     */
    static bool fileExists( const std::string& filePath );

    /**
     * @return True if the folder was successfully created, or already exists.
     */
    static bool createDirectories( const std::string& path );

};
}}}}

#include <teamcenter/soa/common/SoaCommonUndef.h>

#endif

