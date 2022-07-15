/* 
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2012
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

 ==================================================

   Auto-generated source from service interface.
                 DO NOT EDIT

 ==================================================
*/

#ifndef TEAMCENTER_SERVICES_CORE__2007_06_LOV_HXX
#define TEAMCENTER_SERVICES_CORE__2007_06_LOV_HXX

#include <teamcenter/soa/client/model/ListOfValues.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/core/Core_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            namespace _2007_06
            {
                class Lov;

class TCSOACORESTRONGMNGD_API Lov
{
public:

    struct AttachedLOVsResponse;
    struct LOVInfo;
    struct LOVOutput;

    /**
     * InputTypeNameToLOVOutputMap
     */
    typedef std::map< std::string, std::vector< LOVOutput > > InputTypeNameToLOVOutputMap;

    /**
     * AttachedLOVsResponse
     */
    struct AttachedLOVsResponse
    {
        /**
         * Map of input type name to LOVOutput
         */
        InputTypeNameToLOVOutputMap inputTypeNameToLOVOutput;
        /**
         * ServiceData which has output tags as plain objects and errors in partialError
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * LOVInfo
     */
    struct LOVInfo
    {
        /**
         * The name of the Teamcenter Engineering type to which property belongs
         */
        std::string typeName;
        /**
         * List of Property names to which the LOV is attached
         */
        std::vector< std::string > propNames;
    };

    /**
     * LOVOutput
     */
    struct LOVOutput
    {
        /**
         * Input Property name to which the LOV is attached
         */
        std::string propName;
        /**
         * The attached LOV tag found for the input type and property name
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ListOfValues>  lov;
    };




    /**
     * Get attached LOV based on input type name and property names structure. The LOV Tag
     * is returned in the response and service data.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * List of Values (LOV) - Component to define lists of values and to associate them
     * with attributes and properties.  Associations can be stored in the database (persistent)
     * or independently associated for each Teamcenter session (run time).
     *
     * @param inputs
     *        - vector of structure of LOVInfo with type name and property names vector.
     *
     * @return
     *         AttachedLOVsResponse - Response structure with Map of input Index to LOV tag and
     *         serviceData
     *
     *
     * @exception ServiceException
     *           None
     * @deprecated
     *         As of tc2007.1, use the getAttachedPropDescs operation.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of tc2007.1, use the getAttachedPropDescs operation."))
#endif
    virtual Teamcenter::Services::Core::_2007_06::Lov::AttachedLOVsResponse getAttachedLOVs ( const std::vector< Teamcenter::Services::Core::_2007_06::Lov::LOVInfo >& inputs ) = 0;


protected:
    virtual ~Lov() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

