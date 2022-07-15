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

#ifndef TEAMCENTER_SERVICES_ASBUILT__2009_06_ASBUILT_HXX
#define TEAMCENTER_SERVICES_ASBUILT__2009_06_ASBUILT_HXX

#include <teamcenter/services/asbuilt/_2008_06/Asbuilt.hxx>
#include <teamcenter/soa/client/model/AsBuiltBOMLine.hxx>
#include <teamcenter/soa/client/model/PhysicalPartRevision.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/asbuilt/AsBuilt_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Asbuilt
        {
            namespace _2009_06
            {
                class Asbuilt;

class TCSOAASBUILTSTRONGMNGD_API Asbuilt
{
public:

    struct ReplaceAsBuiltPartInfo;
    struct ReplaceAsBuiltPartInputInfo;
    struct ReplaceAsBuiltPartOutput;
    struct ReplaceAsBuiltPartResponse;

    /**
     * Structure represents the parameters required to replace an as-built <b>PhysicalPart</b>
     * object.
     */
    struct ReplaceAsBuiltPartInfo
    {
        /**
         * The <i>Installation Time</i> which will be set on the <b>AsBuiltStructure</b> relation
         * object created between the parent and the replaced as-built <b>PhysicalPartRevision</b>
         * objects.
         */
        Teamcenter::Soa::Common::DateTime installationDate;
        /**
         * A ExtendedAttributes structure which will hold any additional parameters passed by
         * the consumer of this operation.
         */
        Teamcenter::Services::Asbuilt::_2008_06::Asbuilt::ExtendedAttributes extendedData;
    };

    /**
     * Structure represents the parameters required to replace an as-built <b>PhysicalPart</b>
     * object.
     */
    struct ReplaceAsBuiltPartInputInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * An object, which will be replaced.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AsBuiltBOMLine>  selectedLine;
        /**
         * A object which will replace the existing <b>PhysicalPartRevision</b> object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PhysicalPartRevision>  copiedPhysicalPartRevision;
        /**
         * A replace parameters like replace date.
         */
        Teamcenter::Services::Asbuilt::_2009_06::Asbuilt::ReplaceAsBuiltPartInfo replaceAsBuiltPartInfo;
    };

    /**
     * Structure represents the output parameters of the replaceAsBuiltPart operation.
     */
    struct ReplaceAsBuiltPartOutput
    {
        /**
         * The <code>clientId</code> from the input ReplaceAsBuiltPartInputInfo element. This
         * value is unchanged from the input, and can be used to identify this response element
         * with the corresponding input element.
         */
        std::string clientId;
        /**
         * An object created for the <b>PhysicalPartRevision</b> object which replaced the existing
         * object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AsBuiltBOMLine>  replacerLine;
    };

    /**
     * Structure contains the replace line and the <code>ServiceData</code>.
     */
    struct ReplaceAsBuiltPartResponse
    {
        /**
         * A list of replaced lines.
         */
        std::vector< Teamcenter::Services::Asbuilt::_2009_06::Asbuilt::ReplaceAsBuiltPartOutput > output;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation replaces an as-built <b>PhysicalPartRevision</b> in a structure with
     * a given as-built <b>PhysicalPartRevision</b> object.  The existing as-built <b>PhysicalPartRevision</b>
     * object will be removed from the structure and the new object will be installed in
     * that position. A new <b>AsBuiltStructure</b> relation will be created between the
     * parent and the new <b>PhysicalPartRevision</b> objects. The <i>Installation</i> Time
     * specified will be set as the Installation Time on the relation object.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * installPhysicalPart
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MRO As-Built - This component provides capabilities to generate and perform actions
     * on As-Built structures.
     *
     * @param inputData
     *        ReplaceAsBuiltPartInputInfo structure object which contains the required information
     *        for replace action
     *
     * @return
     *         The created <b>AsBuiltBOMLine</b> object for the replacer <b>PhysicalPart</b> object
     *         is returned in the created objects list of the <code>ServiceData</code>. Any failure
     *         will be returned with client id mapped to error message in the <code>ServiceData</code>
     *         list of partial errors.  Following error codes are returned in the <code>ServiceData</code>.
     *         <br>
     *         <ul>
     *         <li type="disc">237073&nbsp;&nbsp;&nbsp;&nbsp;    If the <i>Replace Date</i> is earlier
     *         than the <i>Effective From Date</i> of the <b>PhysicalPartRevision</b> object.
     *         </li>
     *         <li type="disc">238014 &nbsp;&nbsp;&nbsp;&nbsp;If the action tries to replace the
     *         top line.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Asbuilt::_2009_06::Asbuilt::ReplaceAsBuiltPartResponse replaceAsBuiltPart ( const std::vector< Teamcenter::Services::Asbuilt::_2009_06::Asbuilt::ReplaceAsBuiltPartInputInfo >& inputData ) = 0;


protected:
    virtual ~Asbuilt() {}
};
            }
        }
    }
}

#include <teamcenter/services/asbuilt/AsBuilt_undef.h>
#endif

