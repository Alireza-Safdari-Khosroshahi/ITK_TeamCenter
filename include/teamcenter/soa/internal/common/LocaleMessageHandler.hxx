// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
// ==================================================
// Copyright 2012.
// Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
// ==================================================
// Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.



#ifndef TEAMCENTER_SOA_INTERNAL_COMMON_LOCALMESSAGEHANDLER_HXX
#define TEAMCENTER_SOA_INTERNAL_COMMON_LOCALMESSAGEHANDLER_HXX




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
                class LocaleMessageHandler;
            }
        }
    }
}

/**
 * This class would be used to load and lookup localized error messages for SOA client.
 */
class TCSOACOMMON_API Teamcenter::Soa::Internal::Common::LocaleMessageHandler
{
public:


    /**
     * Get SOA error message corresponding to the client locale based on key.
     *
     * @param code - used to lookup message.
     * @return localized message corresponding to the code.
     */
    virtual std::string getMessage( int code );


    /**
     * Get SOA error message corresponding to the client locale based on key
     * substituting each %i with corresponding element in array
     *
     * @param code - used to lookup message.
     * @param substitutions - values to be substituted.
     * @return localized message corresponding to the code.
     */
    virtual std::string getMessage(int code, const std::vector<std::string>& substitutions);
 
    /**
     * The severity level.
     * <UL>
     * <li>  1: Information
     * <li>  2: Warning,
     * <li>  3: Error,
     * <li>  4: UserError;
     *</UL>
     *
     * @param code - used to lookup message.
     * @return The severity level.
     */
    virtual int getSeverity( int code ) const = 0;

protected:
    /**
     *
     * @return The error text.
     */
    virtual std::string getText( int code ) const =0;



};

#include <teamcenter/soa/common/SoaCommonUndef.h>

#endif